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
This is the interpreter main file that executes the instructions.
*/
//dom.h -> always required as all the AST nodes do is manipulate 
//the dom
#include <string.h>
#include <stdio.h>
#include "dom.h"
#include "dast.h"


extern uint8_t  alloc_buffer[];

void *dalloc(uint16_t size)
{
    void *dalBlock;
    if(enable)
    {
        if((dlpointer+size) <= DAL_BFR_SIZE)
        {
            dalBlock = &alloc_buffer[dlpointer];
            dlpointer+=size;
        }
    }
    return dalBlock;
}
void dldisable(void)
{
    enable = 0;
}
/*extern script_t script;

int main()
{
    //Check if there is a script- should be ready before starting to run
    if(!script.isValid)
    {
        //There is no script or this one is outdated, fetch new
        return OK;
    }
    //If there is no source, should exit with an error status code

    while(version == script.version)
    {
        //navigate the AST and execute the statements

        //Init

        do
        {
            //Run
        }
        while(evalCondition(script.));//condition

        //Check the conditional statement -> how long to wait before the next loop


    }
    script.isValid = INVALID;
    //There is a newer version of the script and needs to restart
    return OK;
}
*/

int write_register(char *name, char *value)
{
	if(reg_pointer < (REG_SIZE -1))
	{
		reg_entry_t reg;
                strcpy(reg.name, name);
                strcpy(reg.value, value);
		registers[reg_pointer] = reg;
                reg_pointer++;
		return SUCCESS;
	}
	return FAULT;
}

int update_register(char *name, char *value)
{
	if(reg_pointer < REG_SIZE)
	{
		int index = reg_pointer-1;
		while(index >= 0)
		{
			if(strcmp(name,registers[index].name)==0)
			{
				strcpy(registers[index].value, value);
				return SUCCESS;
			}
                        index--;
		}
                //If not found, insert it
                reg_entry_t reg;
                strcpy(reg.name, name);
                strcpy(reg.value, value);
		registers[reg_pointer] = reg;
                reg_pointer++;
		return SUCCESS;
	}
	return FAULT;
}

char* read_register(char *name)
{
	if(reg_pointer < REG_SIZE )
	{
		int index = reg_pointer-1;
		while(index >= 0)
		{
			if(strcmp(registers[index].name, name)==0)
			{
				return registers[index].value;
			}
                        index--;
		}
		return "NAN";
	}
	return "NAN";
}

int push(char *entry)
{
	if(stack_pointer < (STACK_SIZE -1))
	{
		stack[stack_pointer] = entry;
		stack_pointer++;
		return SUCCESS;
	}
	return FAULT;
}

char* pop()
{
	if(stack_pointer >= 0)
	{
		return stack[stack_pointer--];
	}
	return "";
}
/**
 * @brief 
 * 
 * @param contents 
 * @return struct script_member* 
 */
struct script_member* build_block(struct script_member* contents)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = BLK_SMT;
    member->value.block.contenets = contents;
    return member;        
}
/**
 * @brief 
 * 
 * @param version 
 * @return struct script_member* 
 */
struct script_member* build_version(int version)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = VERS_SMT;
    member->value.inumber = version;
    return member; 
}
/**
 * @brief 
 * 
 * @param name 
 * @param value 
 * @return struct script_member* 
 */
struct script_member* build_include(char *name, struct script_member* value)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = INC_SMT;
    strcpy(member->value.assignment.variable,name);
    member->value.assignment.right = value;
    return member; 
}
/**
 * @brief 
 * 
 * @param parent 
 * @param toappend 
 * @return struct script_member* 
 */
struct script_member* build_statements(struct script_member* parent, struct script_member* toappend)
{
    struct script_member* member = parent;
    int index = member->value.statements.count;
    if(index < STMT_MAX)
    {
        member->type = STMT_SMT;
        member->value.statements.elements[index] = toappend;
        member->value.statements.count++;
    }
    return member; 
}
/**
 * @brief 
 * 
 * @param left 
 * @param right 
 * @return struct script_member* 
 */
struct script_member* build_assignment(struct script_member* left, struct script_member* right)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = ASST_SMT;
    return member; 
}
/**
 * @brief 
 * 
 * @param loop 
 * @param condition 
 * @param truevals 
 * @param falsevals 
 * @return struct script_member* 
 */
struct script_member* build_conditional(int loop, struct script_member* condition, struct script_member* truevals, struct script_member* falsevals)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = COND_SMT;
    member->value.conditional.loop = loop;
    member->value.conditional.compare = condition;
    member->value.conditional.thenstmts = truevals;
    member->value.conditional.notstmts = falsevals;
    return member;
}
/**
 * @brief 
 * 
 * @param loop 
 * @param condition 
 * @param truevals 
 * @return struct script_member* 
 */
struct script_member* build_conditional_bl(int loop, struct script_member* condition, struct script_member* truevals)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = COND_SMT_BL;
    member->value.conditional.loop = loop;
    member->value.conditional.compare = condition;
    member->value.conditional.thenstmts = truevals;
    member->value.conditional.notstmts = NULL;
    return member;
}
/**
 * @brief 
 * 
 * @param condition 
 * @return struct script_member* 
 */
struct script_member* build_conditional_st(struct script_member* condition)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = COND_SMT_ST;
    member->value.conditional.loop = 1;
    member->value.conditional.compare = condition;
    member->value.conditional.thenstmts = NULL;
    member->value.conditional.notstmts = NULL;
    return member;
}
/**
 * @brief 
 * 
 * @param oper 
 * @param left 
 * @param right 
 * @return struct script_member* 
 */
struct script_member* build_expression(int oper, struct script_member* left, struct script_member* right)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = EXPER_SMT;
    member->value.expression.oper = oper;
    member->value.expression.left = left;
    member->value.expression.right = right;
    return member;
}
/**
 * @brief 
 * 
 * @param name 
 * @return struct script_member* 
 */
struct script_member* build_variable(char *name)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = VAR_SMT;
    strcpy(member->value.strvar, name);
    return member;
}
/**
 * @brief 
 * 
 * @param name 
 * @return struct script_member* 
 */
struct script_member* build_constr(char *name)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = CONSTSTR_SMT;
    strcpy(member->value.strvar, name);
    return member;
}
/**
 * @brief 
 * 
 * @param value 
 * @return struct script_member* 
 */
struct script_member* build_fltconstant(float value)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = CONSTFLT_SMT;
    member->value.number = value;
    return member;
}
/**
 * @brief 
 * 
 * @param value 
 * @return struct script_member* 
 */
struct script_member* build_intconstant(int value)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = CONSTINT_SMT;
    member->value.inumber = value;
    return member;
}
/**
 * @brief 
 * 
 * @param name 
 * @param argc 
 * @param arguments 
 * @return struct script_member* 
 */
struct script_member* build_domcall(char *objName, char *name, int argc, struct script_member* arguments)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = DOMCALL_SMT;
    if(objName)
    {
        strcpy(member->value.domcall.objct, objName);
    }
    strcpy(member->value.domcall.fname, name);
    member->value.domcall.pcount = argc;
    member->value.domcall.params = arguments;
    return member;
}
/**
 * @brief 
 * 
 * @param parent 
 * @param toappend 
 * @return struct script_member* 
 */
struct script_member* build_parameters(struct script_member* parent, struct script_member* toappend)
{
    struct script_member* member = parent;
    int index = member->value.params.count;
    if(index < PRM_MAX)
    {
        member->type = PARM_STM;
        member->value.params.elements[index] = toappend;
        member->value.params.count++;
    }
    return member; 
}

//Extended functions
/**
 * @brief 
 * 
 * @param header 
 * @param body 
 * @return struct script_member* 
 */
struct script_member* build_script(struct script_member* header, struct script_member* body)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = SCRPT_STM;
    member->value.script.header = header;
    member->value.script.body = body;
    return member;
}
/**
 * @brief 
 * 
 * @param version 
 * @param includes 
 * @return struct script_member* 
 */
struct script_member* build_header(struct script_member* version, struct script_member* includes)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = HEADER_STM;
    member->value.header.versionInfo = version;
    member->value.header.imports = includes;
    return member;
}
/**
 * @brief 
 * 
 * @param iblock 
 * @param rblock 
 * @return struct script_member* 
 */
struct script_member* build_body(struct script_member* iblock, struct script_member* rblock)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = BODY_STM;
    member->value.sbody.init = iblock;
    member->value.sbody.runBlock = rblock;
    return member;
}
/**
 * @brief 
 * 
 * @param parent 
 * @param append 
 * @return struct script_member* 
 */
struct script_member* build_includes(struct script_member* parent, struct script_member* append)
{
    struct script_member* member = parent;
    int index = member->value.includes.count;
    if(index < INC_MAX)
    {
        member->value.includes.elements[index] = append;
        member->value.includes.count++;
    }
    member->type = INCLDS_STM;
    return member;
}
/**
 * @brief 
 * 
 * @param init 
 * @param lcond 
 * @return struct script_member* 
 */
struct script_member* build_initls(struct script_member* init, struct script_member* lcond)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    member->type = INIT_STM;
    member->value.init.initBlock = init;
    member->value.init.lcondn = lcond;
    return member;
}

/**
 * @brief 
 * 
 * @return struct script_member* 
 */
struct script_member* build_parent(void)
{
    struct script_member* member = dalloc(sizeof(struct script_member));
    return member;
}