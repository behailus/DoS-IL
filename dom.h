#ifndef DOM_H
#define DOM_H
#include <stdio.h>


typedef struct
{
	char frmt[100];
}sformat_t;

typedef struct
{
	sformat_t sfrm;
	float     value;
}sval_t;

typedef struct
{
	int   i;
	float f;
}snumber_t;

typedef struct
{
	char *key;
	char *value;
}resource_t;

typedef struct
{
	char *did;
}tag_t;
/* Event Id is in the range 0x10 to 0x1F */
typedef struct
{
	int 		id;
	char		*name;
	int 		fired;
	void 		(*get_state)(int id);
	void 		(*args)(int id);
}event_t;

/* Sensor Id is in the range 0x20 to 0x2F */
typedef struct
{
	int id;
	void   (*read)(void);
}sensor_t;
/* Actuator Id is in the range 0x30 to 0x3F */
typedef struct
{
	int (*rotate)(int angle); 
	int id;
}actuator_t;

typedef struct
{
	/* device elements*/
	tag_t 		tag;
	event_t 	events[16];
	sensor_t 	sensors[16];
	actuator_t 	actuators[16];
	
	/* device resources*/
	resource_t  devicemeta[10];
	
	/* device functions*/
	int (*ready)(void);
	int (*sleep)(void);
	int	(*wait)(int t); 
	int (*record)(void *buffer, char *dest);
	int (*subscribe)(char *topic);
}device_t;


typedef struct domstr
{
	device_t device;	
	void (*iexecute)(device_t self,int ac,char *as[], char* ret);
}dom_t;

dom_t 		dom_init(void);
int 		sleep(void);
int 		ready(void);
int			wait(int t); 		
int 		record(void *buffer, char *dest);
int 		subscribe(char *topic);
void	 	read(void);
int 		rotate(int angle);
void 		get_state(int id);
void 		args(int id);
void  		iexecute(device_t self,int ac,char *as[], char* ret);
#endif //DOM_H