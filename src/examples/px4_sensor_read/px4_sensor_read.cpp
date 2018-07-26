/****************************************************************************
 *
 *   Copyright (c) 2012-2016 PX4 Development Team. All rights reserved.
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
 * 3. Neither the name PX4 nor the names of its contributors may be
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

/**
 * @file px4_sensor_read.cpp
 * Application for reading wind sensors from FT Technologies
 *
 * @author Talha Tariq
 */

#include <px4_config.h>
#include <px4_tasks.h>
#include <px4_posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <math.h>

#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>
#include <termios.h>

extern "C" __EXPORT int px4_sensor_read_main(int argc, char *argv[]);

int px4_sensor_read_main(int argc, char *argv[])
{
    PX4_INFO("Hello Sky!");

    int uart0_filestream = -1;
    int num_of_bytes = 24; //Number of characters (bytes) to be read in one loop (see while loop below)


    //OPEN THE UART
    //The flags (defined in fcntl.h):
    //	Access modes (use 1 of these):
    //		O_RDONLY - Open for reading only.
    //		O_RDWR - Open for reading and writing.
    //		O_WRONLY - Open for writing only.
    //
    //	O_NDELAY / O_NONBLOCK (same function) - Enables nonblocking mode. When set read requests on the file can return immediately with a failure status
    //											if there is no input immediately available (instead of blocking). Likewise, write requests can also return
    //											immediately with a failure status if the output can't be written immediately.
    //
    //	O_NOCTTY - When set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling terminal for the process.

    //Open port /dev/tty--
    //See: https://pixhawk.org/users/wiring for names corresponding to hardware ports
//    uart0_filestream = open("/dev/ttyS6", O_RDONLY | O_NOCTTY | O_SYNC); //| O_NDELAY);
    uart0_filestream = open("/dev/ttyS2", O_RDWR | O_NOCTTY | O_NDELAY); //{}
    if (uart0_filestream == -1)
    {
        PX4_ERR("Error - Unable to open UART.  Ensure it is not in use by another application");
        return -1;
    }
    else
    {
        PX4_INFO("Successful Connection!");
        PX4_INFO("uart0_filestream is: %d", uart0_filestream);
    }

    //CONFIGURE THE UART
    //The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
    //	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
    //	CSIZE:- CS5, CS6, CS7, CS8
    //	CLOCAL - Ignore modem status lines
    //	CREAD - Enable receiver
    //	IGNPAR = Ignore characters with parity errors
    //	ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
    //	PARENB - Parity enable
    //	PARODD - Odd parity (else even)

    //setting terminal options
    struct termios options;
    int termios_state;
    tcgetattr(uart0_filestream, &options);
    //system("stty -F /dev/ttyUSB0 sane raw pass8 -echo -hupcl clocal 9600"); //Linux command
    //options.c_cflag = B9600 | CS8 | PARENB | CLOCAL | CREAD; //DOESN'T WORK

    /* Back up the original uart configuration to restore it after exit */
    if ((termios_state = tcgetattr(uart0_filestream, &options)) < 0) {
        PX4_ERR("ERR GET CONF: %d\n", termios_state);
        close(uart0_filestream);
        return -1;
    }

    cfsetispeed(&options, B38400);    // set baud rates. 38400 for FT205EV sensor, 9600 for FT742
    cfsetospeed(&options, B38400);

    //RAW configuration
//    cfmakeraw(&options);
    options.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
                    | INLCR | IGNCR | ICRNL | IXON);
    options.c_oflag &= ~OPOST;
    options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;

    options.c_cflag |= (CLOCAL | CREAD);   // Enable the receiver and set local mode
    options.c_cflag &= ~CSTOPB;            // 1 stop bit
    options.c_cflag &= ~CRTSCTS;           // Disable hardware flow control
    options.c_cc[VMIN]  = num_of_bytes;
    options.c_cc[VTIME] = 1;

    //FROM c_uart_interface_example
//    options.c_iflag &= ~(IGNBRK | BRKINT | ICRNL |
//                            INLCR | PARMRK | INPCK | ISTRIP | IXON);
//    options.c_oflag &= ~(OCRNL | ONLCR | ONLRET |
//                         ONOCR | OFILL | OPOST);
//    #ifdef OLCUC
//        options.c_oflag &= ~OLCUC;
//    #endif

//    #ifdef ONOEOT
//        options.c_oflag &= ~ONOEOT;
//    #endif
//    options.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
// //     options.c_cflag &= ~(CSIZE | PARENB);
//    options.c_cflag &= ~(CSTOPB | PARENB); //{}
//    options.c_cflag |= CS8;
//    options.c_cc[VMIN]  = num_of_bytes;
//    options.c_cc[VTIME] = 1;

    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);

    if (tcsetattr(uart0_filestream, TCSANOW, &options) != 0) {
            PX4_ERR("Error from tcsetattr");
            return -1;
        }

    int rx_length;
//    int counter = 0;
//    int prev_counter = 1;
//    bool pass = false;
//    bool restart = false;
    unsigned char rx_buffer[num_of_bytes];
    unsigned char data[num_of_bytes];

    if (sizeof(rx_buffer) != sizeof(data))
    {
        PX4_ERR("Error! size of rx_buffer != size of data array");
        return -1;
    }

    fcntl(uart0_filestream, F_SETFL, 0);

    PX4_INFO("test");
    rx_length = read(uart0_filestream, &rx_buffer, sizeof(rx_buffer));
    PX4_INFO("test_rx_buffer: %s", rx_buffer);
    PX4_INFO("test");
//    PX4_INFO("rx_buffer: %s", rx_buffer);
//    PX4_INFO("rx_length: %d", rx_length);
//    rx_length = 0;

    //----- CHECK FOR ANY RX BYTES -----
    while((rx_length = read(uart0_filestream, &rx_buffer, sizeof(rx_buffer)))) 	//Read from USB port
//    while(1)
    {
        if (rx_length < 0)
        {
                PX4_ERR("An error occured (will occur if there are no bytes)");
                return -1;
        }
        else if (rx_length == 0)
        {
                PX4_ERR("No data waiting");
                return -1;
        }

        PX4_INFO("rx_buffer: %s", rx_buffer);
        PX4_INFO("rx_length: %d", rx_length);

//        //find '$' location in rx_buffer array
//        for (counter = 0; counter < num_of_bytes ; counter++) //TODO: Make this into a method
//        {
//            if(rx_buffer[counter] == '$')
//            {
//                PX4_INFO("counter: %d", counter);
//                break;
//            }

//            if(counter == (num_of_bytes - 1)) //restart if no '$' found
//            {
//                PX4_INFO("Error! Buffer does not contain valid sensor data! Restarting...\n");
//                restart = true;
//            }
//        }

//        //restarting the loop
//        if (restart)
//        {
//            restart = false;
//            pass = false;
//            memset(data, 0, sizeof(data));
//            continue;
//        }

//        //making sure that the data flow is consistent
//        // if (counter - prev_counter > 1 || counter - prev_counter == 0) //TODO: Check if this is needed. If yes, restart needed in statement?
//        // {
//        // 	pass = false;
//        // 	cout << "FAIL!" << endl;
//        // 	cout << endl;
//        // }

//        //fill in previous data with new buffer array from previous for loop
//        if (pass)
//        {
//            for (int i = 0; i < prev_counter; i++)
//            {
//                data[i + (sizeof(rx_buffer) - prev_counter)] = rx_buffer[i];
//            }

//            PX4_INFO("Data: %s \n", data);
//        }

//        //filling up data array with '$' location known
//        for (int i = 0; i < (num_of_bytes - counter); i++)
//        {
//            data[i] = rx_buffer[(counter) + i];
//        }

//        pass = true;
//        prev_counter = counter;

//        counter++;
//        PX4_INFO("counter: %d", counter);
    }

    PX4_INFO("exiting");

    return 0;
}
