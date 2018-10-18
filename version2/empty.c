#include <stdio.h>
#include <string.h>
#include "dast.h"
#include "dom.h"



dom_t model = {
    .sync = post,
    .every = sleep,
    .read = read,
    .write = write,
    .send = put,
    .receive = get,
    .initialized = 1
};


void executeExpression(script_member_t expression)
{

}

script_member_t executeDomcall(script_member_t domcall)
{
    script_member_t member;
    //If the function has no return type return empty member
    printf("Executing domcall: %s\n",domcall.value.domcall.fname);
    if(strcmp(domcall.value.domcall.fname,"sleep")==0)
    {
        model.every(domcall.value.domcall.params[0]->value.inumber);
    }
    else if(strcmp(domcall.value.domcall.fname,"write")==0)
    {
        model.write(domcall.value.domcall.params[0]->value.strvar,(void*)&domcall.value.domcall.params[1]->value.number);
    }
    return member;
}




int main()
{
    printf("Starting Tests:\n");
    init();//Initialize the DOM

    printf("New temperature: %f\n",temperature);
    /*
    script_member_t myvar = build_variable("tester");
    script_member_t param = build_intconstant(25);
    script_member_t param1 = build_fltconstant(22.5);
    script_member_t param2 = build_variable("temperature");

    script_member_t pcoll[]={param2,param1};
    script_member_t domc = build_domcall("write",2,pcoll);
    script_member_t exper = build_expression(20,myvar,domc);

    printf("Expression: %s\n",exper.value.expression.left->value.strvar);
    printf("Operator: %d\n",exper.value.expression.oper);
    printf("Domcall: %s(%s,%f)\n",exper.value.expression.right->value.domcall.fname,
                            exper.value.expression.right->value.domcall.params[0]->value.strvar,
                            exper.value.expression.right->value.domcall.params[1]->value.number);
    
    
    //Execute the domcall expression
    executeDomcall(domc);
    printf("New temperature: %f\n",temperature);
    */
    return 0;
}

Version info done
Import id done
Import done
Import dom done
Imports done
Header done
ID done
Param done
Strval done
Params done
Dom call param done
Dom call done
Statement done
ID done
Param done
Inumber done
Numeric done
Params done
Dom call param done
Dom call done
Statements done
Block done
Init section done
Inumber done
dom loop done
Initialization done
ID done
Param done
Dom call param done
dom ex done
Assignment ex done
Assignment done
Statement done
ID done
Param done
ID done
Params done
Dom call param done
Dom call done
Statements done
ID done
Param done
Dom call param done
dom ex done
Assignment ex done
Assignment done
Statements done
Id con done
== done
Str con done
ccc done
Id con done
> done
Inumber done
Num con done
ccc done
ID done
Param done
Inumber done
Numeric done
Params done
Dom call param done
Dom call done
Statement done
Block done
ID done
Param done
Inumber done
Numeric done
Params done
Dom call param done
Dom call done
Statement done
Block done
If else done
IF clause done
Conditional done
Statement done
Block done
Id con done
> done
Inumber done
Num con done
ccc done
ID done
Param done
Inumber done
Numeric done
Params done
Dom call param done
Dom call done
Statement done
Block done
ID done
Param done
Inumber done
Numeric done
Params done
Dom call param done
Dom call done
Statement done
Block done
If else done
IF clause done
Conditional done
Statement done
Block done
If else done
IF clause done
Conditional done
Statements done
Dom call empty done
Dom call done
Statements done
Block done
Run section done
Body done
Script done
Compeleted script parsing. 
