/* 
This source file implements the thing description file that also 
exists in dom.h
*/
#include "dom.h"
#include <stdio.h>
#include <string.h>

/*
Predefined elements
*/
//Initialize the variables
int version = 1;

//Properties
float battery = 3.3;
uint8_t state = STATE_READY;
//Properties
float temperature = 23.5;
int speed = 0;
char unit = 'C';
/**
 * @brief Initilize and assign the member functions of dom
 * 
 * @return status_t : status of the initialization
 */
status_t init(void)
{

    return STATUS_OK;
}
/**
 * @brief Sleep the device for a given ms
 * 
 * @param duration time in ms
 * @return status_t of function call
 */
status_t    sleep(uint16_t duration)
{
    printf("Going to sleep for %d ms\n",duration);
    return STATUS_OK;
}
status_t    write(char* property, void* value)
{
    printf("Updated property %f\n",*((float*)value));
    if(strcmp("temperature",property)==0)
    {
        temperature = *(float*)(value);
    }
    return STATUS_OK;
}
status_t    read(char* property, void *buffer)
{
    return STATUS_OK;
}
status_t send(void *buffer)
{
    return STATUS_OK;
}
status_t receive(void *buffer)
{
    return STATUS_OK;
}
/*
User defined components - Please extend from this point on
*/
status_t put(void* buffer)//buffer can be any request
{
    return STATUS_OK;
}
status_t get(void *buffer)
{
    return STATUS_OK;
}
status_t post(void)//sync dom whenever property is written
{
    return STATUS_OK;
}


/*
Uaser defined section
*/