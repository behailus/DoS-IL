/*
 * Copyright (c) 2017, Turku University.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the DoS-IL interpreter.
 *
 * Author: Behailu S. Negash <behneg@utu.fi>
 *
 */
#include "dom.h"

int sleep(void)
{
	printf("Going to sleep!\n");
	return 0;
}

int ready(void)
{
	printf("Device ready!\n");
	return 0;
}

int record(void *buffer, char *dest)
{
	printf("Data recorded in %s\n",dest);
	return 0;
}

int subscribe(char *topic)
{
	printf("Subscribe %s\n",topic);
	return 0;
}

int	wait(int t)
{
	printf("waiting for %i seconds\n",t );
	return 0;
}

void read(void)
{
	printf("Sensor read the value!\n");
}

int rotate(int angle)
{
	printf("Actuator rotated \n");
	return 0;
}

void get_state(int id)
{
	printf("Returns state of %i event\n",id );
}
void args(int id)
{
	printf("Get value of the argument for event %i \n",id );
}

void iexecute(device_t self,int ac, char *as[], char* ret)
{
	while(--ac>=0)
	{
		printf("%s%s",*as++,(ac>0)?" ":"" );
		/*sprintf(ret,"%s%s",*as++,(ac>0)?" ":"" );
		ret++;
		ret++;*/
	}
	
	sprintf(ret,"%s","Test Return");
}

dom_t dom_init(void)
{
	dom_t 			dom;
	device_t 		device;
	tag_t 			tag;
	resource_t	resource;
	sensor_t 		sensor;
	actuator_t	actuator;
	event_t			event;
	//Initialize the stack

	tag.did="DEV0234";

	resource.key="NProtocol";
	resource.value="BLE";
	event.id = 18;
	event.name="Ready";
	event.fired = 1;
	event.args = args;

	sensor.id = 34;
	sensor.read = &read;

	actuator.id = 52;
	actuator.rotate = &rotate;

	device.tag = tag;
	device.events[0] = event;
	device.sensors[0] = sensor;
	device.actuators[0] = actuator;
	device.devicemeta[0] = resource;

	/* device functions*/
	device.ready = &ready;
	device.sleep = &sleep;
	device.record = &record;
	device.subscribe = &subscribe;

	dom.device = device;
	dom.iexecute = iexecute;
	return dom;
}