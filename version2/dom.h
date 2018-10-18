
/*
 * Copyright (c) 2018, Behailu S. Negash.
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

/*
This file defines the key elements that are organized in a things 
description file. It has pre-defined and user defined sections.
*/

#ifndef DOM_H
#define DOM_H
/*
Include files
*/

#include <stdio.h>
#include <inttypes.h>


#define STATE_RUNNING     2
#define STATE_WAITING     1
#define STATE_ERROR       -1
#define STATE_READY       0
/*
Pre-defined components 
*/
typedef enum{
    STATUS_OK,
    STATUS_ERROR
}status_t;

typedef struct{
    int initialized;
    status_t (*sync)();
    status_t (*every)(uint16_t time);
    status_t (*read)(char *property, void *buffer);
    status_t (*write)(char *property, void* value);
    status_t (*send)(void *buffer);
    status_t (*receive)(void *buffer);
}dom_t;


//Actions

status_t    sleep(uint16_t duration);
status_t    write(char* property, void* value);
status_t    read(char* property, void *buffer);
/*
User defined components - Please extend from this point on
*/
status_t init(void);
status_t put(void* buffer);//buffer can be any request
status_t get(void *buffer);
status_t post(void);//sync dom whenever property is written


//Tracks and compares the version of the script
extern int version;

//Properties
extern float   battery;
extern uint8_t state;
//Properties
extern float   temperature ;
extern int     speed;
extern char    unit;


extern dom_t model;
#endif //DOM_H