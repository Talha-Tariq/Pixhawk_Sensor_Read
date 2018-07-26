/****************************************************************************
 *
 *   Copyright (C) 2013-2016 PX4 Development Team. All rights reserved.
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

/* Auto-generated by genmsg_cpp from file tecs_status.msg */


#include <cinttypes>
#include <cstdio>
#include <px4_defines.h>
#include <uORB/topics/tecs_status.h>
#include <drivers/drv_hrt.h>

constexpr char __orb_tecs_status_fields[] = "uint64_t timestamp;float altitudeSp;float altitude_filtered;float flightPathAngleSp;float flightPathAngle;float airspeedSp;float airspeed_filtered;float airspeedDerivativeSp;float airspeedDerivative;float totalEnergyError;float energyDistributionError;float totalEnergyRateError;float energyDistributionRateError;float throttle_integ;float pitch_integ;uint8_t mode;uint8_t[7] _padding0;";

ORB_DEFINE(tecs_status, struct tecs_status_s, 65, __orb_tecs_status_fields);


void print_message(const tecs_status_s& message)
{
	printf(" tecs_status_s\n");
	printf("\ttimestamp: %" PRIu64, message.timestamp);
	if (message.timestamp != 0) {
		printf(" (%.6f seconds ago)\n", hrt_elapsed_time(&message.timestamp) / 1e6);
	} else {
		printf("\n");
	}
	printf("\taltitudeSp: %.3f\n", (double)message.altitudeSp);
	printf("\taltitude_filtered: %.3f\n", (double)message.altitude_filtered);
	printf("\tflightPathAngleSp: %.3f\n", (double)message.flightPathAngleSp);
	printf("\tflightPathAngle: %.3f\n", (double)message.flightPathAngle);
	printf("\tairspeedSp: %.3f\n", (double)message.airspeedSp);
	printf("\tairspeed_filtered: %.3f\n", (double)message.airspeed_filtered);
	printf("\tairspeedDerivativeSp: %.3f\n", (double)message.airspeedDerivativeSp);
	printf("\tairspeedDerivative: %.3f\n", (double)message.airspeedDerivative);
	printf("\ttotalEnergyError: %.3f\n", (double)message.totalEnergyError);
	printf("\tenergyDistributionError: %.3f\n", (double)message.energyDistributionError);
	printf("\ttotalEnergyRateError: %.3f\n", (double)message.totalEnergyRateError);
	printf("\tenergyDistributionRateError: %.3f\n", (double)message.energyDistributionRateError);
	printf("\tthrottle_integ: %.3f\n", (double)message.throttle_integ);
	printf("\tpitch_integ: %.3f\n", (double)message.pitch_integ);
	printf("\tmode: %u\n", message.mode);
	}