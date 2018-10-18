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
Header file that contains the abstract syntax tree elements that 
make up the grammar of DoSIL. 
*/

#ifndef DAST_H
#define DAST_H

#include <inttypes.h>

#define FAULT -1
#define SUCCESS 0

//function definitions

#define STACK_SIZE 16
#define REG_SIZE 32

#define NAME_MAX 50
#define STMT_MAX 12
#define INC_MAX 4
#define PRM_MAX 6
#define DAL_BFR_SIZE 20480
extern uint8_t  enable;
extern uint16_t dlpointer; 
void *dalloc(uint16_t size);
void dldisable(void);
typedef struct{
	char name[NAME_MAX];
	char value[NAME_MAX];
}reg_entry_t;

reg_entry_t registers[REG_SIZE];
static int reg_pointer = 0;

char* stack[STACK_SIZE];
static int stack_pointer = 0;

int write_register(char *name, char *value);
int update_register(char *name, char *value);
char* read_register(char *name);
int push(char *entry);
char* pop();

typedef enum{
	//Extended
	SCRPT_STM,
	HEADER_STM,
	BODY_STM,
	INCLDS_STM,
	INIT_STM,
	PARM_STM,
    CONSTINT_SMT,//build_intconstant
    CONSTFLT_SMT,//build_fltconstant
    CONSTSTR_SMT,//build_constr - with " "
    DOMCALL_SMT,//build_domcall
    EXPER_SMT,//build_expression
    STMT_SMT,//build_statements
    ASST_SMT,//build_assignment
    BLK_SMT,//build_block
    COND_SMT,//build_conditional
	COND_SMT_ST,
	COND_SMT_BL,
	VERS_SMT,//build_version
	INC_SMT,//build_include
	VAR_SMT//build_variable - without " "
}member_type_t;


typedef struct script_member
{
    member_type_t type;
    union 
    {
        int   inumber;
        float number;
        char  strvar[NAME_MAX];

        struct{
			char objct[NAME_MAX];
            char fname[NAME_MAX];
            int  pcount;
            struct script_member *params;
        }domcall;

        struct{
            int oper;
            struct script_member *left;
            struct script_member *right;
        }expression;

        struct{
            int count;
            struct script_member *elements[STMT_MAX];
        }statements;

        struct{
            int count;
            struct script_member *elements[PRM_MAX];
        }params;

        struct{
            char variable[NAME_MAX];
            struct script_member *right;
        }assignment;

        struct{
            struct script_member *contenets;
        }block;

        struct{
			int  loop;//if = 0, while = 1
            struct script_member *compare;
            struct script_member *thenstmts;
            struct script_member *notstmts;
        }conditional;

		//Extended
		struct{
			int count;
			struct script_member *elements[INC_MAX];
		}includes;

		struct{
			struct script_member *versionInfo;
			struct script_member *imports;
		}header;

		struct{
			struct script_member *header;
			struct script_member *body;
		}script;

		struct{
			struct script_member *init;//block
			struct script_member *runBlock;
		}sbody;

		struct{
			struct script_member *initBlock;
			struct script_member *lcondn;
		}init;

    }value;
}script_member_t;


struct script_member* build_block(struct script_member* contents);

struct script_member* build_version(int version);

struct script_member* build_include(char *name, struct script_member* value);

struct script_member* build_statements(struct script_member* parent, struct script_member* toappend);

struct script_member* build_parameters(struct script_member* parent, struct script_member* toappend);

struct script_member* build_assignment(struct script_member* left, struct script_member* right);

struct script_member* build_conditional(int loop, struct script_member* condition, struct script_member* truevals, struct script_member* falsevals);

struct script_member* build_conditional_bl(int loop, struct script_member* condition, struct script_member* truevals);

struct script_member* build_conditional_st(struct script_member* condition);

struct script_member* build_expression(int oper, struct script_member* left, struct script_member* right);

struct script_member* build_variable(char *name);

struct script_member* build_constr(char *name);

struct script_member* build_fltconstant(float value);

struct script_member* build_intconstant(int value);

struct script_member* build_domcall(char *objName, char *name, int argc, struct script_member* arguments);

//Extended helpers

struct script_member* build_script(struct script_member* header, struct script_member* body);

struct script_member* build_header(struct script_member* version, struct script_member* includes);

struct script_member* build_body(struct script_member* iblock, struct script_member* rblock);

struct script_member* build_includes(struct script_member* parent, struct script_member* append);

struct script_member* build_initls(struct script_member* init, struct script_member* lcond);

struct script_member* build_parent(void);

#endif //DAST_H