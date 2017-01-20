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