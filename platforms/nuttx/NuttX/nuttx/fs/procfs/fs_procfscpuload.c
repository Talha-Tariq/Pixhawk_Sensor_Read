/****************************************************************************
 * fs/procfs/fs_procfscpuload.c
 *
 *   Copyright (C) 2014, 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <sys/statfs.h>
#include <sys/stat.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/clock.h>
#include <nuttx/kmalloc.h>
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_PROCFS)
#if defined(CONFIG_SCHED_CPULOAD) && !defined(CONFIG_FS_PROCFS_EXCLUDE_CPULOAD)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define CPULOAD_LINELEN 16

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct cpuload_file_s
{
  struct procfs_file_s  base;   /* Base open file structure */
  unsigned int linesize;        /* Number of valid characters in line[] */
  char line[CPULOAD_LINELEN];   /* Pre-allocated buffer for formatted lines */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* File system methods */

static int     cpuload_open(FAR struct file *filep, FAR const char *relpath,
                 int oflags, mode_t mode);
static int     cpuload_close(FAR struct file *filep);
static ssize_t cpuload_read(FAR struct file *filep, FAR char *buffer,
                 size_t buflen);
static int     cpuload_dup(FAR const struct file *oldp,
                 FAR struct file *newp);
static int     cpuload_stat(FAR const char *relpath, FAR struct stat *buf);

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* See fs_mount.c -- this structure is explicitly externed there.
 * We use the old-fashioned kind of initializers so that this will compile
 * with any compiler.
 */

const struct procfs_operations cpuload_operations =
{
  cpuload_open,       /* open */
  cpuload_close,      /* close */
  cpuload_read,       /* read */
  NULL,               /* write */

  cpuload_dup,        /* dup */

  NULL,              /* opendir */
  NULL,              /* closedir */
  NULL,              /* readdir */
  NULL,              /* rewinddir */

  cpuload_stat        /* stat */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: cpuload_open
 ****************************************************************************/

static int cpuload_open(FAR struct file *filep, FAR const char *relpath,
                      int oflags, mode_t mode)
{
  FAR struct cpuload_file_s *attr;

  finfo("Open '%s'\n", relpath);

  /* PROCFS is read-only.  Any attempt to open with any kind of write
   * access is not permitted.
   *
   * REVISIT:  Write-able proc files could be quite useful.
   */

  if ((oflags & O_WRONLY) != 0 || (oflags & O_RDONLY) == 0)
    {
      ferr("ERROR: Only O_RDONLY supported\n");
      return -EACCES;
    }

  /* "cpuload" is the only acceptable value for the relpath */

  if (strcmp(relpath, "cpuload") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* Allocate a container to hold the file attributes */

  attr = (FAR struct cpuload_file_s *)kmm_zalloc(sizeof(struct cpuload_file_s));
  if (!attr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the attributes as the open-specific state in filep->f_priv */

  filep->f_priv = (FAR void *)attr;
  return OK;
}

/****************************************************************************
 * Name: cpuload_close
 ****************************************************************************/

static int cpuload_close(FAR struct file *filep)
{
  FAR struct cpuload_file_s *attr;

  /* Recover our private data from the struct file instance */

  attr = (FAR struct cpuload_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  /* Release the file attributes structure */

  kmm_free(attr);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: cpuload_read
 ****************************************************************************/

static ssize_t cpuload_read(FAR struct file *filep, FAR char *buffer,
                           size_t buflen)
{
  FAR struct cpuload_file_s *attr;
  size_t linesize;
  off_t offset;
  ssize_t ret;

  finfo("buffer=%p buflen=%d\n", buffer, (int)buflen);

  /* Recover our private data from the struct file instance */

  attr = (FAR struct cpuload_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  /* If f_pos is zero, then sample the system time.  Otherwise, use
   * the cached system time from the previous read().  It is necessary
   * save the cached value in case, for example, the user is reading
   * the time one byte at a time.  In that case, the time must remain
   * stable throughout the reads.
   */

  if (filep->f_pos == 0)
    {
      struct cpuload_s cpuload;
      uint32_t intpart;
      uint32_t fracpart;

      /* Sample the counts for the IDLE thread.  clock_cpuload should only
       * fail if the PID is not valid.  This, however, should never happen
       * for the IDLE thread.
       */

      DEBUGVERIFY(clock_cpuload(0, &cpuload));

      /* On the simulator, you may hit cpuload.total == 0, but probably never on
       * real hardware.
       */

      if (cpuload.total > 0)
        {
          uint32_t tmp;

          tmp      = 1000 - (1000 * cpuload.active) / cpuload.total;
          intpart  = tmp / 10;
          fracpart = tmp - 10 * intpart;
        }
      else
        {
          intpart  = 0;
          fracpart = 0;
        }

      linesize = snprintf(attr->line, CPULOAD_LINELEN, "%3d.%01d%%",
                          intpart, fracpart);

      /* Save the linesize in case we are re-entered with f_pos > 0 */

      attr->linesize = linesize;
    }

  /* Transfer the system up time to user receive buffer */

  offset = filep->f_pos;
  ret    = procfs_memcpy(attr->line, attr->linesize, buffer, buflen, &offset);

  /* Update the file offset */

  if (ret > 0)
    {
      filep->f_pos += ret;
    }

  return ret;
}

/****************************************************************************
 * Name: cpuload_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int cpuload_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct cpuload_file_s *oldattr;
  FAR struct cpuload_file_s *newattr;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldattr = (FAR struct cpuload_file_s *)oldp->f_priv;
  DEBUGASSERT(oldattr);

  /* Allocate a new container to hold the task and attribute selection */

  newattr = (FAR struct cpuload_file_s *)kmm_malloc(sizeof(struct cpuload_file_s));
  if (!newattr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newattr, oldattr, sizeof(struct cpuload_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = (FAR void *)newattr;
  return OK;
}

/****************************************************************************
 * Name: cpuload_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int cpuload_stat(const char *relpath, struct stat *buf)
{
  /* "cpuload" is the only acceptable value for the relpath */

  if (strcmp(relpath, "cpuload") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* "cpuload" is the name for a read-only file */

  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#endif /* CONFIG_FS_PROCFS_EXCLUDE_CPULOAD */
#endif /* !CONFIG_DISABLE_MOUNTPOINT && CONFIG_FS_PROCFS */
