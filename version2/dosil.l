/* Definitions */
%{
    #include "dast.h"
    #include "dosil.tab.h"
    #include <stdio.h>
    #include <stdlib.h>

    int lineno = 1;
    void yyerror(const char *);
%}
/* Rules */
%%

"version"           return VERSION;
"include"           return INCLUDE;
"run"               return RUN;
"if"                return IFB;
"init"              return INIT;
"while"             return WHILEB;
"every"             return EVERY;
"else"              return ELSEB;
"or"                return OR;
"and"               return AND;
"dom"               return DOM;
">""="              return GE;
"<""="              return LE;
"=""="              return EQ;
"!""="              return NE;

[><=.:;{}()+-/*,]                 return yytext[0];

[!](.*)*.*  /* Ignore single line comment */ ;


[-]?[0-9]+                       { yylval.ival = atoi(yytext); return INUMBER; }
[-]?[0-9]+[.][0-9]+              { yylval.fval = atof(yytext); return FNUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*              { 
                                        yylval.sval = strdup(yytext);
                                        return IDENTIFIER; 
                                    }
["][a-zA-Z_ .\t]*["]                { 
                                        yylval.sval = strdup(yytext);
                                        return STRVAL; 
                                    }
\n                                   { ++lineno; }/* Ignore new line */   ;
[ \t]+                             /* Ignore white space */ ;
.                       { ECHO; yyerror("Illegal token found"); }
%%
/* User code */
int yywrap(void)
{
    return 1;
}