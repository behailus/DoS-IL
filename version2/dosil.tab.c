/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "dosil.y"


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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "dosil.y"
{
    int   ival;
    float fval;
    char  *sval;
    struct script_member *scelem;
}
/* Line 193 of yacc.c.  */
#line 162 "dosil.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 175 "dosil.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    36,    33,    29,    34,    26,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,    25,
      32,    30,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    21,
      24,    29,    34,    37,    40,    44,    46,    49,    52,    54,
      57,    63,    69,    76,    83,    85,    89,    91,    93,    95,
      97,    99,   105,   113,   119,   127,   133,   137,   139,   141,
     143,   145,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   165,   167,   169,   171,   173,   175,   179,   183,   185,
     187,   189,   191,   194,   198,   202,   206,   210,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    -1,    39,    40,    -1,    42,    43,    -1,
      41,    46,    -1,    45,    56,    -1,    17,    14,    -1,    44,
      -1,    43,    44,    -1,    16,    22,    18,    15,    -1,     8,
      22,    18,    15,    -1,     4,    47,    -1,     3,    47,    -1,
      23,    48,    24,    -1,    49,    -1,    48,    49,    -1,    57,
      25,    -1,    53,    -1,    50,    25,    -1,     8,    26,    16,
      27,    28,    -1,    16,    26,    16,    27,    28,    -1,     8,
      26,    16,    27,    51,    28,    -1,    16,    26,    16,    27,
      51,    28,    -1,    52,    -1,    51,    29,    52,    -1,    15,
      -1,    58,    -1,    16,    -1,    54,    -1,    55,    -1,    19,
      27,    63,    28,    47,    -1,    19,    27,    63,    28,    47,
      20,    47,    -1,    21,    27,    63,    28,    47,    -1,     8,
      26,     5,    27,    58,    28,    25,    -1,    21,    27,    63,
      28,    25,    -1,    16,    30,    59,    -1,    14,    -1,    13,
      -1,    60,    -1,    50,    -1,    63,    -1,    65,    -1,    58,
      -1,    15,    -1,    16,    -1,    31,    -1,    32,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,     6,    -1,     7,
      -1,    58,    -1,    16,    -1,    60,    61,    60,    -1,    63,
      62,    63,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    34,    13,    -1,    13,    64,    13,    -1,    13,    64,
      16,    -1,    16,    64,    16,    -1,    16,    64,    13,    -1,
      65,    64,    13,    -1,    65,    64,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    49,    56,    63,    70,    77,    83,    89,
      96,   102,   110,   117,   124,   129,   135,   142,   144,   146,
     151,   157,   163,   168,   175,   181,   187,   192,   197,   204,
     207,   211,   216,   223,   230,   237,   242,   250,   253,   258,
     261,   264,   267,   271,   274,   277,   282,   285,   288,   291,
     294,   297,   302,   305,   310,   313,   318,   323,   330,   333,
     336,   339,   344,   347,   350,   353,   356,   359,   362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RUN", "INIT", "EVERY", "OR", "AND",
  "DOM", "GE", "LE", "EQ", "NE", "FNUMBER", "INUMBER", "STRVAL",
  "IDENTIFIER", "VERSION", "INCLUDE", "IFB", "ELSEB", "WHILEB", "':'",
  "'{'", "'}'", "';'", "'.'", "'('", "')'", "','", "'='", "'>'", "'<'",
  "'+'", "'-'", "'/'", "'*'", "$accept", "script", "header", "body",
  "initialization", "version_info", "imports", "import", "init_section",
  "run_section", "block", "statements", "statement", "dom_call",
  "parameters", "parameter", "conditional", "if_condition",
  "while_condition", "loop_condition", "assignment", "numeric",
  "expression", "const_expression", "comparison_operator",
  "logical_opeartor", "logical_expression", "arthimetic_operator",
  "arthimetic_expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    58,   123,   125,    59,    46,    40,    41,    44,
      61,    62,    60,    43,    45,    47,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    40,    41,    42,    43,    43,
      44,    44,    45,    46,    47,    48,    48,    49,    49,    49,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     1,     2,
       4,     4,     2,     2,     3,     1,     2,     2,     1,     2,
       5,     5,     6,     6,     1,     3,     1,     1,     1,     1,
       1,     5,     7,     5,     7,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     7,     1,     0,     3,     0,
       0,     0,     0,     4,     8,     0,    12,     0,     5,     0,
       0,     6,     0,     0,     9,     0,     0,     0,     0,     0,
      15,     0,    18,    29,    30,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    16,    19,    17,
       0,    38,    37,    44,    45,    43,     0,     0,    11,    10,
       0,     0,    38,    45,     0,    40,    36,    39,    41,    42,
       0,     0,     0,    48,    49,    50,    51,    46,    47,     0,
      52,    53,     0,     0,     0,     0,    58,    59,    60,    61,
       0,     0,    62,     0,     0,     0,     0,    45,    43,    56,
      35,    57,    26,    28,    20,     0,    24,    27,    21,     0,
      63,    64,    66,    65,    67,    68,    31,    33,     0,    22,
       0,    23,     0,    34,    25,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     8,     9,     4,    13,    14,    10,    18,
      16,    29,    30,    31,   105,   106,    32,    33,    34,    21,
      35,    55,    66,    56,    79,    83,    57,    90,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int8 yypact[] =
{
      -7,     6,    27,    28,    49,   -72,   -72,    17,   -72,    59,
       4,    36,    64,    49,   -72,    68,   -72,    17,   -72,    46,
      91,   -72,    96,    99,   -72,    94,    25,    92,    95,    40,
     -72,    98,   -72,   -72,   -72,   100,   -72,   116,    77,   109,
     111,   112,   113,     3,    77,    77,   -72,   -72,   -72,   -72,
     103,   -72,   -72,   -72,    22,    24,    12,    32,   -72,   -72,
     104,   105,    62,     0,   114,   -72,   -72,    12,    67,    62,
      39,    47,    90,   -72,   -72,   -72,   -72,   -72,   -72,    86,
     -72,   -72,   108,    77,    55,    66,   -72,   -72,   -72,   -72,
      50,    72,   -72,    97,    17,    17,   106,   -72,   -72,   -72,
     -72,    67,   -72,   -72,   -72,    83,   -72,   -72,   -72,    87,
     -72,   -72,   -72,   -72,   -72,   -72,   115,   -72,   117,   -72,
      93,   -72,    17,   -72,   -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   123,   -72,   -72,
     -17,   -72,   110,   101,    52,    18,   -72,   -72,   -72,   -72,
     -72,   -71,   -72,   -38,   -72,   -72,   -41,   -54,   -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int8 yytable[] =
{
      36,    96,    68,    70,    71,    67,   -55,   -55,    98,    91,
       1,    25,    19,   107,   107,    93,    62,    52,    53,    63,
       5,    73,    74,    75,    76,    20,    42,     6,   -55,   -55,
     -54,   -54,     7,    86,    87,    88,    89,    64,    80,    81,
      15,    99,   101,    77,    78,    80,    81,   -55,    25,   107,
     -55,    42,   -54,    80,    81,    43,    26,    11,    22,    27,
      82,    28,    17,   110,    46,    12,   111,    94,    51,    52,
     102,   103,    37,    80,    81,    95,    25,   116,   117,    51,
      52,   102,   103,   104,    26,   112,    23,    27,   113,    28,
      51,    52,    53,    54,   108,    86,    87,    88,    89,    51,
      52,    53,    97,    51,    52,   125,    51,    52,   102,   103,
     114,   119,   120,   115,    39,   121,   120,    40,    38,    44,
      41,    50,    45,    48,    58,    49,    59,    92,    60,    61,
      72,    84,    85,   100,   118,   122,    24,   109,   124,    47,
       0,     0,   123,     0,    65
};

static const yytype_int8 yycheck[] =
{
      17,    72,    43,    44,    45,    43,     6,     7,    79,    63,
      17,     8,     8,    84,    85,    69,    13,    14,    15,    16,
      14,     9,    10,    11,    12,    21,    26,     0,     6,     7,
       6,     7,     4,    33,    34,    35,    36,    34,     6,     7,
      23,    79,    83,    31,    32,     6,     7,    25,     8,   120,
      28,    26,    28,     6,     7,    30,    16,     8,    22,    19,
      28,    21,     3,    13,    24,    16,    16,    28,    13,    14,
      15,    16,    26,     6,     7,    28,     8,    94,    95,    13,
      14,    15,    16,    28,    16,    13,    22,    19,    16,    21,
      13,    14,    15,    16,    28,    33,    34,    35,    36,    13,
      14,    15,    16,    13,    14,   122,    13,    14,    15,    16,
      13,    28,    29,    16,    18,    28,    29,    18,    27,    27,
      26,     5,    27,    25,    15,    25,    15,    13,    16,    16,
      27,    27,    27,    25,    28,    20,    13,    85,   120,    29,
      -1,    -1,    25,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    38,    39,    42,    14,     0,     4,    40,    41,
      45,     8,    16,    43,    44,    23,    47,     3,    46,     8,
      21,    56,    22,    22,    44,     8,    16,    19,    21,    48,
      49,    50,    53,    54,    55,    57,    47,    26,    27,    18,
      18,    26,    26,    30,    27,    27,    24,    49,    25,    25,
       5,    13,    14,    15,    16,    58,    60,    63,    15,    15,
      16,    16,    13,    16,    34,    50,    59,    60,    63,    65,
      63,    63,    27,     9,    10,    11,    12,    31,    32,    61,
       6,     7,    28,    62,    27,    27,    33,    34,    35,    36,
      64,    64,    13,    64,    28,    28,    58,    16,    58,    60,
      25,    63,    15,    16,    28,    51,    52,    58,    28,    51,
      13,    16,    13,    16,    13,    16,    47,    47,    28,    28,
      29,    28,    20,    25,    52,    47
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 41 "dosil.y"
    {
                struct script_member *sct=build_parent();
                sct->type = SCRPT_STM;
                sct->value.script.header = NULL;
                sct->value.script.body = NULL;
                (*(struct script_member**)scrtparam) = sct;
        ;}
    break;

  case 3:
#line 50 "dosil.y"
    { 
                (*(struct script_member**)scrtparam) = build_script((yyvsp[(1) - (2)].scelem), (yyvsp[(2) - (2)].scelem));
        ;}
    break;

  case 4:
#line 57 "dosil.y"
    {
                (yyval.scelem) = build_header((yyvsp[(1) - (2)].scelem), (yyvsp[(2) - (2)].scelem));
        ;}
    break;

  case 5:
#line 64 "dosil.y"
    {
                (yyval.scelem) = build_body((yyvsp[(1) - (2)].scelem), (yyvsp[(2) - (2)].scelem));
        ;}
    break;

  case 6:
#line 71 "dosil.y"
    {
                (yyval.scelem) = build_initls((yyvsp[(1) - (2)].scelem), (yyvsp[(2) - (2)].scelem));
        ;}
    break;

  case 7:
#line 78 "dosil.y"
    {
                (yyval.scelem) = build_version((yyvsp[(2) - (2)].ival)); 
            ;}
    break;

  case 8:
#line 84 "dosil.y"
    { 
                struct script_member *mem = build_parent();
                (yyval.scelem) = build_includes(mem, (yyvsp[(1) - (1)].scelem));
        ;}
    break;

  case 9:
#line 90 "dosil.y"
    {
                (yyval.scelem) = build_includes((yyvsp[(1) - (2)].scelem), (yyvsp[(2) - (2)].scelem));
        ;}
    break;

  case 10:
#line 97 "dosil.y"
    {
                struct script_member* idnt = build_constr((yyvsp[(4) - (4)].sval));
                (yyval.scelem) = build_include((yyvsp[(1) - (4)].sval),idnt);
        ;}
    break;

  case 11:
#line 103 "dosil.y"
    {
                struct script_member* idnt = build_constr((yyvsp[(4) - (4)].sval));
                (yyval.scelem) = build_include("dom",idnt);
        ;}
    break;

  case 12:
#line 111 "dosil.y"
    {
                (yyval.scelem) = (yyvsp[(2) - (2)].scelem);
        ;}
    break;

  case 13:
#line 118 "dosil.y"
    {
                (yyval.scelem) = (yyvsp[(2) - (2)].scelem);
        ;}
    break;

  case 14:
#line 125 "dosil.y"
    { (yyval.scelem) = build_block((yyvsp[(2) - (3)].scelem)); ;}
    break;

  case 15:
#line 130 "dosil.y"
    { 
            struct script_member *mem = build_parent();
            (yyval.scelem) = build_statements(mem, (yyvsp[(1) - (1)].scelem));
        ;}
    break;

  case 16:
#line 136 "dosil.y"
    {
                (yyval.scelem) = build_statements((yyvsp[(1) - (2)].scelem), (yyvsp[(2) - (2)].scelem));
        ;}
    break;

  case 17:
#line 143 "dosil.y"
    { (yyval.scelem) = (yyvsp[(1) - (2)].scelem); ;}
    break;

  case 18:
#line 145 "dosil.y"
    { (yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 19:
#line 147 "dosil.y"
    { (yyval.scelem) = (yyvsp[(1) - (2)].scelem); ;}
    break;

  case 20:
#line 152 "dosil.y"
    {
                struct script_member* empty;
                (yyval.scelem) = build_domcall(NULL, (yyvsp[(3) - (5)].sval), 0,empty);
        ;}
    break;

  case 21:
#line 158 "dosil.y"
    {
                struct script_member* empty;
                (yyval.scelem) = build_domcall((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].sval), 0,empty);
        ;}
    break;

  case 22:
#line 164 "dosil.y"
    {
                (yyval.scelem) = build_domcall(NULL, (yyvsp[(3) - (6)].sval), 0,(yyvsp[(5) - (6)].scelem));
        ;}
    break;

  case 23:
#line 169 "dosil.y"
    {
                (yyval.scelem) = build_domcall((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].sval), 0,(yyvsp[(5) - (6)].scelem));
        ;}
    break;

  case 24:
#line 176 "dosil.y"
    { 
                struct script_member* prnt = build_parent();
                (yyval.scelem) = build_parameters(prnt, (yyvsp[(1) - (1)].scelem)); 
        ;}
    break;

  case 25:
#line 182 "dosil.y"
    {  
                (yyval.scelem) = build_parameters((yyvsp[(1) - (3)].scelem), (yyvsp[(3) - (3)].scelem)); 
        ;}
    break;

  case 26:
#line 188 "dosil.y"
    {
                 (yyval.scelem) = build_constr((yyvsp[(1) - (1)].sval)); 
        ;}
    break;

  case 27:
#line 193 "dosil.y"
    {
                 (yyval.scelem) = (yyvsp[(1) - (1)].scelem); 
        ;}
    break;

  case 28:
#line 198 "dosil.y"
    { 
                (yyval.scelem) = build_variable((yyvsp[(1) - (1)].sval)); 
        ;}
    break;

  case 29:
#line 205 "dosil.y"
    { (yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 30:
#line 208 "dosil.y"
    { (yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 31:
#line 212 "dosil.y"
    {
                (yyval.scelem) = build_conditional_bl(0, (yyvsp[(3) - (5)].scelem), (yyvsp[(5) - (5)].scelem));
        ;}
    break;

  case 32:
#line 217 "dosil.y"
    {
                (yyval.scelem) = build_conditional(0, (yyvsp[(3) - (7)].scelem), (yyvsp[(5) - (7)].scelem), (yyvsp[(7) - (7)].scelem));
        ;}
    break;

  case 33:
#line 224 "dosil.y"
    {
                (yyval.scelem) = build_conditional_bl(1, (yyvsp[(3) - (5)].scelem), (yyvsp[(5) - (5)].scelem));
        ;}
    break;

  case 34:
#line 231 "dosil.y"
    { 
                struct script_member* prnt = build_parent();
                struct script_member* parms = build_parameters(prnt,(yyvsp[(5) - (7)].scelem));
                (yyval.scelem) =  build_conditional_st(build_domcall(NULL,"every",1,parms)); 
        ;}
    break;

  case 35:
#line 238 "dosil.y"
    { (yyval.scelem) =  build_conditional_st((yyvsp[(3) - (5)].scelem));;}
    break;

  case 36:
#line 243 "dosil.y"
    {
                struct script_member* left = build_variable((yyvsp[(1) - (3)].sval));
                (yyval.scelem) = build_assignment(left,(yyvsp[(3) - (3)].scelem));
        ;}
    break;

  case 37:
#line 251 "dosil.y"
    { (yyval.scelem) = build_intconstant((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 38:
#line 254 "dosil.y"
    { (yyval.scelem) = build_fltconstant((yyvsp[(1) - (1)].fval)); ;}
    break;

  case 39:
#line 259 "dosil.y"
    {(yyval.scelem) = (yyvsp[(1) - (1)].scelem);;}
    break;

  case 40:
#line 262 "dosil.y"
    {(yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 41:
#line 265 "dosil.y"
    {(yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 42:
#line 268 "dosil.y"
    {(yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 43:
#line 272 "dosil.y"
    {(yyval.scelem) = (yyvsp[(1) - (1)].scelem); ;}
    break;

  case 44:
#line 275 "dosil.y"
    {(yyval.scelem) = build_constr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 45:
#line 278 "dosil.y"
    {(yyval.scelem) = build_variable((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 46:
#line 283 "dosil.y"
    { (yyval.ival) = 0; ;}
    break;

  case 47:
#line 286 "dosil.y"
    { (yyval.ival) = 1; ;}
    break;

  case 48:
#line 289 "dosil.y"
    { (yyval.ival) = 2; ;}
    break;

  case 49:
#line 292 "dosil.y"
    { (yyval.ival) = 3; ;}
    break;

  case 50:
#line 295 "dosil.y"
    { (yyval.ival) = 4; ;}
    break;

  case 51:
#line 298 "dosil.y"
    { (yyval.ival) = 5; ;}
    break;

  case 52:
#line 303 "dosil.y"
    { (yyval.ival) = 10; ;}
    break;

  case 53:
#line 306 "dosil.y"
    { (yyval.ival) = 11; ;}
    break;

  case 54:
#line 311 "dosil.y"
    {(yyval.scelem) = (yyvsp[(1) - (1)].scelem);printf("Num lex done\n");;}
    break;

  case 55:
#line 314 "dosil.y"
    {
                (yyval.scelem) = build_variable((yyvsp[(1) - (1)].sval));
        ;}
    break;

  case 56:
#line 319 "dosil.y"
    { 
                (yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].scelem), (yyvsp[(3) - (3)].scelem));
        ;}
    break;

  case 57:
#line 324 "dosil.y"
    {
                (yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].scelem), (yyvsp[(3) - (3)].scelem));
        ;}
    break;

  case 58:
#line 331 "dosil.y"
    { (yyval.ival) = 20; ;}
    break;

  case 59:
#line 334 "dosil.y"
    { (yyval.ival) = 21; ;}
    break;

  case 60:
#line 337 "dosil.y"
    { (yyval.ival) = 22; ;}
    break;

  case 61:
#line 340 "dosil.y"
    { (yyval.ival) = 23; ;}
    break;

  case 62:
#line 345 "dosil.y"
    {(yyval.scelem) = build_expression(21,build_fltconstant(0.0),build_fltconstant((yyvsp[(2) - (2)].fval)));;}
    break;

  case 63:
#line 348 "dosil.y"
    {(yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival),build_fltconstant((yyvsp[(1) - (3)].fval)),build_fltconstant((yyvsp[(3) - (3)].fval)));;}
    break;

  case 64:
#line 351 "dosil.y"
    {(yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival), build_fltconstant((yyvsp[(1) - (3)].fval)), build_variable((yyvsp[(3) - (3)].sval)));;}
    break;

  case 65:
#line 354 "dosil.y"
    { (yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival), build_variable((yyvsp[(1) - (3)].sval)), build_variable((yyvsp[(3) - (3)].sval))); ;}
    break;

  case 66:
#line 357 "dosil.y"
    { (yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival), build_variable((yyvsp[(1) - (3)].sval)), build_fltconstant((yyvsp[(3) - (3)].fval))); ;}
    break;

  case 67:
#line 360 "dosil.y"
    { (yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival), (yyvsp[(1) - (3)].scelem), build_fltconstant((yyvsp[(3) - (3)].fval))); ;}
    break;

  case 68:
#line 363 "dosil.y"
    { (yyval.scelem) = build_expression((yyvsp[(2) - (3)].ival),(yyvsp[(1) - (3)].scelem),build_variable((yyvsp[(3) - (3)].sval))); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1893 "dosil.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 365 "dosil.y"


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


