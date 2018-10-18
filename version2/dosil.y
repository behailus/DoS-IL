%{

#include <stdio.h>
//#include "dom.h"
#include "dast.h"
#include <string.h>
extern int lineno;
extern int yylex();
extern int yyparse();
void yyerror(const char *s);

static struct script_member scrpt;
//Return the ast to be executed out of the parser
#define YYPARSE_PARAM scrtparam

%}
%start script
%token RUN INIT EVERY OR AND DOM 
%token GE LE EQ NE           

%token <fval>FNUMBER
%token <ival>INUMBER
%token <sval>STRVAL IDENTIFIER
%token VERSION INCLUDE 
%token IFB  ELSEB WHILEB    

%union{
    int   ival;
    float fval;
    char  *sval;
    struct script_member *scelem;
}

%type <scelem> script header body initialization version_info imports import init_section run_section block statements statement
%type <scelem> dom_call parameters parameter conditional if_condition while_condition loop_condition assignment numeric expression
%type <scelem> const_expression logical_expression arthimetic_expression
%type <ival> arthimetic_operator logical_opeartor comparison_operator

%%

script: {
                struct script_member *sct=build_parent();
                sct->type = SCRPT_STM;
                sct->value.script.header = NULL;
                sct->value.script.body = NULL;
                (*(struct script_member**)scrtparam) = sct;
        }
        |
        header body
        { 
                (*(struct script_member**)scrtparam) = build_script($1, $2);
        }
        ;

header:
        version_info imports
        {
                $$ = build_header($1, $2);
        }
        ;

body:
        initialization run_section
        {
                $$ = build_body($1, $2);
        }
        ;

initialization:
        init_section loop_condition
        {
                $$ = build_initls($1, $2);
        }
        ;

version_info:     
        VERSION INUMBER 
            {
                $$ = build_version($2); 
            }
        ;
imports:  
        import
        { 
                struct script_member *mem = build_parent();
                $$ = build_includes(mem, $1);
        }
        |
        imports import
        {
                $$ = build_includes($1, $2);
        }
        ;

import:
        IDENTIFIER  ':'  INCLUDE  STRVAL 
        {
                struct script_member* idnt = build_constr($4);
                $$ = build_include($1,idnt);
        }
        |
        DOM  ':' INCLUDE STRVAL 
        {
                struct script_member* idnt = build_constr($4);
                $$ = build_include("dom",idnt);
        }
        ;

init_section:
        INIT block
        {
                $$ = $2;
        }
        ;

run_section:
        RUN  block
        {
                $$ = $2;
        }
        ;
        
block:
        '{' statements '}'
        { $$ = build_block($2); }
        ;

statements:
        statement
        { 
            struct script_member *mem = build_parent();
            $$ = build_statements(mem, $1);
        }
        |
        statements statement
        {
                $$ = build_statements($1, $2);
        }
        ;

statement:
        assignment ';'
        { $$ = $1; }
        | conditional
        { $$ = $1; }
        | dom_call ';'
        { $$ = $1; }
        ;

dom_call:
        DOM '.' IDENTIFIER '(' ')'
        {
                struct script_member* empty;
                $$ = build_domcall(NULL, $3, 0,empty);
        }
        |
        IDENTIFIER '.' IDENTIFIER '(' ')'
        {
                struct script_member* empty;
                $$ = build_domcall($1, $3, 0,empty);
        }
        |
        DOM '.' IDENTIFIER '(' parameters ')'
        {
                $$ = build_domcall(NULL, $3, 0,$5);
        }
        |
        IDENTIFIER '.' IDENTIFIER '(' parameters ')'
        {
                $$ = build_domcall($1, $3, 0,$5);
        }
        ;

parameters:
        parameter
        { 
                struct script_member* prnt = build_parent();
                $$ = build_parameters(prnt, $1); 
        }
        |
        parameters ',' parameter
        {  
                $$ = build_parameters($1, $3); 
        }
        ;
parameter:
        STRVAL
        {
                 $$ = build_constr($1); 
        }
        |
        numeric
        {
                 $$ = $1; 
        }
        |
        IDENTIFIER
        { 
                $$ = build_variable($1); 
        }
        ;

conditional:
        if_condition
        { $$ = $1; }
        |
        while_condition
        { $$ = $1; }
        ;
if_condition:
        IFB '(' logical_expression ')' block
        {
                $$ = build_conditional_bl(0, $3, $5);
        }
        |
        IFB '(' logical_expression ')' block ELSEB block
        {
                $$ = build_conditional(0, $3, $5, $7);
        }
        ;

while_condition:
        WHILEB '(' logical_expression ')' block
        {
                $$ = build_conditional_bl(1, $3, $5);
        }
        ;

loop_condition:
        DOM '.' EVERY '(' numeric ')' ';'
        { 
                struct script_member* prnt = build_parent();
                struct script_member* parms = build_parameters(prnt,$5);
                $$ =  build_conditional_st(build_domcall(NULL,"every",1,parms)); 
        }
        |
        WHILEB '(' logical_expression ')' ';'
        { $$ =  build_conditional_st($3);}
        ;

assignment:
        IDENTIFIER '='  expression
        {
                struct script_member* left = build_variable($1);
                $$ = build_assignment(left,$3);
        }
        ;

numeric:
        INUMBER
        { $$ = build_intconstant($1); }
        |
        FNUMBER
        { $$ = build_fltconstant($1); }
        ;

expression:
        const_expression
        {$$ = $1;}
        |
        dom_call
        {$$ = $1; }
        |
        logical_expression
        {$$ = $1; }
        |
        arthimetic_expression
        {$$ = $1; }
        ;
const_expression:
        numeric
        {$$ = $1; }
        |
        STRVAL
        {$$ = build_constr($1); }
        |
        IDENTIFIER
        {$$ = build_variable($1); }
        ;

comparison_operator:
        '>'
        { $$ = 0; }
        |
        '<'
        { $$ = 1; }
        |
        GE
        { $$ = 2; }
        |
        LE
        { $$ = 3; }
        |
        EQ
        { $$ = 4; }
        |
        NE
        { $$ = 5; }
        ;

logical_opeartor:
        OR
        { $$ = 10; }
        |
        AND
        { $$ = 11; }
        ;

logical_expression:
        numeric
        {$$ = $1;printf("Num lex done\n");}
        |
        IDENTIFIER
        {
                $$ = build_variable($1);
        }
        |
        const_expression comparison_operator  const_expression
        { 
                $$ = build_expression($2, $1, $3);
        }
        |
        logical_expression logical_opeartor logical_expression
        {
                $$ = build_expression($2, $1, $3);
        }
        ;

arthimetic_operator:
        '+'
        { $$ = 20; }
        |
        '-'
        { $$ = 21; }
        |
        '/'
        { $$ = 22; }
        |
        '*'
        { $$ = 23; }
        ;

arthimetic_expression:
        '-' FNUMBER
        {$$ = build_expression(21,build_fltconstant(0.0),build_fltconstant($2));}
        |
        FNUMBER arthimetic_operator FNUMBER
        {$$ = build_expression($2,build_fltconstant($1),build_fltconstant($3));}
        |
        FNUMBER arthimetic_operator IDENTIFIER
        {$$ = build_expression($2, build_fltconstant($1), build_variable($3));}
        |
        IDENTIFIER arthimetic_operator IDENTIFIER
        { $$ = build_expression($2, build_variable($1), build_variable($3)); }
        |
        IDENTIFIER arthimetic_operator FNUMBER
        { $$ = build_expression($2, build_variable($1), build_fltconstant($3)); }
        |
        arthimetic_expression arthimetic_operator FNUMBER
        { $$ = build_expression($2, $1, build_fltconstant($3)); }
        |
        arthimetic_expression arthimetic_operator IDENTIFIER
        { $$ = build_expression($2,$1,build_variable($3)); }
        ;
%%

uint8_t  alloc_buffer[DAL_BFR_SIZE];
uint8_t  enable = 1;
uint16_t dlpointer = 0;
int main(){
    struct script_member *spt;
    yyparse(&spt);

    printf("Compeleted script parsing. Version %d\n",spt->value.script.header->value.header.versionInfo->value.inumber);
    printf("Dom is %s\n",spt->value.script.header->value.header.imports->value.includes.elements[0]->value.assignment.right->value.strvar);
    printf("Dom is %s\n",spt->value.script.header->value.header.imports->value.includes.elements[1]->value.assignment.right->value.strvar);
    return 0;
}

void yyerror (const char *s) {
    fprintf (stderr, "Stop! %s, on line: %i\n", s, lineno);
 }

