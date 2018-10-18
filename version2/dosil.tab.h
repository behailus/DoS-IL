/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RUN = 258,
     INIT = 259,
     EVERY = 260,
     OR = 261,
     AND = 262,
     DOM = 263,
     GE = 264,
     LE = 265,
     EQ = 266,
     NE = 267,
     FNUMBER = 268,
     INUMBER = 269,
     STRVAL = 270,
     IDENTIFIER = 271,
     VERSION = 272,
     INCLUDE = 273,
     IFB = 274,
     ELSEB = 275,
     WHILEB = 276
   };
#endif
/* Tokens.  */
#define RUN 258
#define INIT 259
#define EVERY 260
#define OR 261
#define AND 262
#define DOM 263
#define GE 264
#define LE 265
#define EQ 266
#define NE 267
#define FNUMBER 268
#define INUMBER 269
#define STRVAL 270
#define IDENTIFIER 271
#define VERSION 272
#define INCLUDE 273
#define IFB 274
#define ELSEB 275
#define WHILEB 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "dosil.y"
{
    int   ival;
    float fval;
    char  *sval;
    struct script_member *scelem;
}
/* Line 1529 of yacc.c.  */
#line 98 "dosil.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

