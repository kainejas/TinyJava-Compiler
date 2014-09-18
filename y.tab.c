
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "tjc.y"


 #include <iostream> 
#include <string.h> 
using namespace std; 
#include "Ast.h"  
extern Expression *expTree; 
extern ClassDeclaration *classDecl;
extern int yylineno;

MethodDeclaration * methodDecl = NULL; 
int yylex(void); 
int yyerror( const char *msg);


/* Line 189 of yacc.c  */
#line 89 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PUBLIC = 258,
     CLASS = 259,
     IDENT = 260,
     LBRACE = 261,
     RBRACE = 262,
     STATIC = 263,
     EQ = 264,
     SEMI = 265,
     LPAR = 266,
     RPAR = 267,
     VOID = 268,
     LBRACK = 269,
     RBRACK = 270,
     INT = 271,
     FLOAT = 272,
     COMMA = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     RETURN = 277,
     PERIOD = 278,
     DOUBLEEQ = 279,
     NEQ = 280,
     LESS = 281,
     GREATER = 282,
     LEQ = 283,
     GEQ = 284,
     PLUS = 285,
     MINUS = 286,
     MULT = 287,
     DIVIDE = 288,
     ICONST = 289,
     FCONST = 290,
     SCONST = 291
   };
#endif
/* Tokens.  */
#define PUBLIC 258
#define CLASS 259
#define IDENT 260
#define LBRACE 261
#define RBRACE 262
#define STATIC 263
#define EQ 264
#define SEMI 265
#define LPAR 266
#define RPAR 267
#define VOID 268
#define LBRACK 269
#define RBRACK 270
#define INT 271
#define FLOAT 272
#define COMMA 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define RETURN 277
#define PERIOD 278
#define DOUBLEEQ 279
#define NEQ 280
#define LESS 281
#define GREATER 282
#define LEQ 283
#define GEQ 284
#define PLUS 285
#define MINUS 286
#define MULT 287
#define DIVIDE 288
#define ICONST 289
#define FCONST 290
#define SCONST 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "tjc.y"

int		ival;
char		*sval;
Statement	*tval;
BlockStatement	*bval;
Expression	*xval;
MethodCallExpression	*mval;
Declaration	*dval;
vector<int>	*vival;
vector<Expression *>	*aval;
vector<Declaration *>	*vdval;



/* Line 214 of yacc.c  */
#line 212 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 224 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   541

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNRULES -- Number of states.  */
#define YYNSTATES  354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    14,    21,    28,    35,    37,
      39,    42,    44,    46,    53,    60,    67,    74,    81,    88,
      89,    90,   102,   103,   104,   116,   125,   134,   135,   150,
     160,   170,   179,   188,   197,   206,   215,   224,   238,   252,
     266,   280,   294,   308,   322,   336,   350,   352,   354,   356,
     360,   364,   367,   370,   373,   376,   377,   383,   389,   395,
     401,   407,   410,   412,   415,   418,   419,   424,   430,   438,
     444,   447,   450,   454,   456,   461,   466,   471,   477,   483,
     489,   495,   501,   507,   513,   519,   525,   529,   532,   536,
     540,   543,   548,   552,   559,   565,   567,   571,   573,   577,
     581,   585,   589,   591,   595,   599,   603,   607,   611,   615,
     619,   623,   625,   629,   633,   637,   641,   643,   647,   651,
     655,   659,   661,   664,   667,   672,   677,   682,   685,   688,
     690,   692,   694,   698,   702,   706,   708,   710
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    -1,     3,     4,     5,    40,
       6,    41,     7,    -1,     3,     4,     1,     6,    41,     7,
      -1,     3,     1,     5,     6,    41,     7,    -1,     1,     4,
       5,     6,    41,     7,    -1,     1,    -1,    42,    -1,    42,
      41,    -1,    43,    -1,    44,    -1,     8,    50,     5,     9,
      68,    10,    -1,     8,    50,     5,     9,    68,     1,    -1,
       8,    50,     5,     9,     1,    10,    -1,     8,    50,     5,
       1,    68,    10,    -1,     8,    50,     1,     9,    68,    10,
      -1,     8,     1,     5,     9,    68,    10,    -1,    -1,    -1,
       8,    50,     5,    11,    45,    51,    12,    46,     6,    53,
       7,    -1,    -1,    -1,     8,    13,     5,    11,    47,    51,
      12,    48,     6,    53,     7,    -1,     8,    50,     5,    11,
      12,     6,    53,     7,    -1,     8,    13,     5,    11,    12,
       6,    53,     7,    -1,    -1,     3,     8,    13,     5,    11,
       5,    14,    15,     5,    12,    49,     6,    53,     7,    -1,
       8,    13,     5,     1,    51,    12,     6,    53,     7,    -1,
       8,    13,     1,    11,    51,    12,     6,    53,     7,    -1,
       8,    50,     5,    11,    12,     6,    53,     1,    -1,     8,
      50,     1,    11,    12,     6,    53,     7,    -1,     8,    13,
       5,    11,    12,     6,    53,     1,    -1,     8,    13,     5,
      11,    12,     1,    53,     7,    -1,     8,    13,     5,    11,
       1,     6,    53,     7,    -1,     8,    13,     5,     1,    12,
       6,    53,     7,    -1,     3,     8,    13,     5,    11,     5,
      14,    15,     5,    12,     1,    53,     7,    -1,     3,     8,
      13,     5,    11,     5,    14,    15,     5,     1,     6,    53,
       7,    -1,     3,     8,    13,     5,    11,     5,    14,    15,
       1,    12,     6,    53,     7,    -1,     3,     8,    13,     5,
      11,     5,    14,     1,     5,    12,     6,    53,     7,    -1,
       3,     8,    13,     5,    11,     5,     1,    15,     5,    12,
       6,    53,     7,    -1,     3,     8,    13,     5,    11,     1,
      14,    15,     5,    12,     6,    53,     7,    -1,     3,     8,
      13,     5,     1,     5,    14,    15,     5,    12,     6,    53,
       7,    -1,     3,     8,     1,     5,    11,     5,    14,    15,
       5,    12,     6,    53,     7,    -1,     3,     1,    13,     5,
      11,     5,    14,    15,     5,    12,     6,    53,     7,    -1,
      16,    -1,    17,    -1,    52,    -1,    52,    18,    51,    -1,
      52,    18,     1,    -1,    50,     5,    -1,    50,     1,    -1,
      54,    56,    -1,    55,    54,    -1,    -1,    50,     5,     9,
      68,    10,    -1,    50,     5,     9,    68,     1,    -1,    50,
       5,     9,     1,    10,    -1,    50,     5,     1,    68,    10,
      -1,    50,     1,     9,    68,    10,    -1,    58,    56,    -1,
      59,    -1,    58,    57,    -1,    58,     1,    -1,    -1,     5,
       9,    62,    10,    -1,    19,    11,    62,    12,    58,    -1,
      19,    11,    62,    12,    58,    20,    58,    -1,    21,    11,
      62,    12,    58,    -1,    60,    10,    -1,    60,     1,    -1,
       6,    57,     7,    -1,    10,    -1,     5,     9,    62,     1,
      -1,     5,     9,     1,    10,    -1,     5,     1,    62,    10,
      -1,    19,    11,    62,    12,     1,    -1,    19,    11,    62,
       1,    58,    -1,    19,    11,     1,    12,    58,    -1,    19,
       1,    62,    12,    58,    -1,     1,    11,    62,    12,    58,
      -1,    21,    11,    62,    12,     1,    -1,    21,    11,    62,
       1,    58,    -1,    21,    11,     1,    12,    58,    -1,    21,
       1,    62,    12,    58,    -1,    22,    62,    10,    -1,    22,
      10,    -1,    22,    62,     1,    -1,    22,     1,    10,    -1,
      22,     1,    -1,     5,    11,    61,    12,    -1,     5,    11,
      12,    -1,     5,    23,     5,    11,    61,    12,    -1,     5,
      23,     5,    11,    12,    -1,    62,    -1,    62,    18,    61,
      -1,    63,    -1,    63,    24,    63,    -1,    63,    25,    63,
      -1,    63,    24,     1,    -1,    63,    25,     1,    -1,    64,
      -1,    64,    26,    64,    -1,    64,    27,    64,    -1,    64,
      28,    64,    -1,    64,    29,    64,    -1,    64,    26,     1,
      -1,    64,    27,     1,    -1,    64,    28,     1,    -1,    64,
      29,     1,    -1,    65,    -1,    64,    30,    65,    -1,    64,
      31,    65,    -1,    64,    30,     1,    -1,    64,    31,     1,
      -1,    66,    -1,    65,    32,    66,    -1,    65,    33,    66,
      -1,    65,    32,     1,    -1,    65,    33,     1,    -1,    67,
      -1,    30,    66,    -1,    31,    66,    -1,    11,    50,    12,
      66,    -1,    11,    50,    12,     1,    -1,    11,    50,     1,
      66,    -1,    30,     1,    -1,    31,     1,    -1,    68,    -1,
       5,    -1,    60,    -1,    11,    62,    12,    -1,    11,     1,
      12,    -1,    11,    62,     1,    -1,    34,    -1,    35,    -1,
      36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    61,    60,    65,    69,    73,    77,    83,
      84,    86,    87,    89,    93,    97,   101,   105,   109,   115,
     120,   114,   125,   130,   124,   134,   139,   147,   145,   163,
     167,   171,   175,   179,   183,   187,   191,   197,   201,   206,
     210,   214,   218,   222,   226,   230,   324,   328,   334,   339,
     344,   349,   353,   358,   364,   369,   373,   377,   381,   385,
     389,   394,   399,   405,   410,   415,   419,   423,   427,   431,
     435,   439,   443,   447,   451,   455,   459,   463,   467,   471,
     475,   479,   483,   487,   491,   495,   503,   507,   511,   515,
     519,   524,   528,   532,   536,   553,   558,   565,   569,   573,
     577,   581,   586,   590,   594,   598,   602,   606,   611,   615,
     619,   624,   628,   632,   636,   640,   645,   649,   653,   657,
     661,   667,   671,   675,   679,   683,   688,   693,   697,   702,
     706,   710,   714,   718,   723,   728,   732,   736
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PUBLIC", "CLASS", "IDENT", "LBRACE",
  "RBRACE", "STATIC", "EQ", "SEMI", "LPAR", "RPAR", "VOID", "LBRACK",
  "RBRACK", "INT", "FLOAT", "COMMA", "IF", "ELSE", "WHILE", "RETURN",
  "PERIOD", "DOUBLEEQ", "NEQ", "LESS", "GREATER", "LEQ", "GEQ", "PLUS",
  "MINUS", "MULT", "DIVIDE", "ICONST", "FCONST", "SCONST", "$accept",
  "tiny_java_program", "class_decl", "$@1", "member_decl_list",
  "member_decl", "field_decl", "method_decl", "$@2", "$@3", "$@4", "$@5",
  "$@6", "type", "formal_param_list", "formal_param", "method_body",
  "local_decl_list", "local_decl", "method_statement_list",
  "statement_list", "statement", "return_statement", "method_invocation",
  "argument_list", "expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "primary_expression", "literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    40,    39,    39,    39,    39,    39,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    43,    45,
      46,    44,    47,    48,    44,    44,    44,    49,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    50,    50,    51,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    55,    55,
      55,    56,    56,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     7,     6,     6,     6,     1,     1,
       2,     1,     1,     6,     6,     6,     6,     6,     6,     0,
       0,    11,     0,     0,    11,     8,     8,     0,    14,     9,
       9,     8,     8,     8,     8,     8,     8,    13,    13,    13,
      13,    13,    13,    13,    13,    13,     1,     1,     1,     3,
       3,     2,     2,     2,     2,     0,     5,     5,     5,     5,
       5,     2,     1,     2,     2,     0,     4,     5,     7,     5,
       2,     2,     3,     1,     4,     4,     4,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     3,     2,     3,     3,
       2,     4,     3,     6,     5,     1,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     2,     2,     4,     4,     4,     2,     2,     1,
       1,     1,     3,     3,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     0,     0,     2,     0,     0,     0,     1,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       9,    11,    12,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     7,    10,     6,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,   135,   136,   137,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    52,    51,
       0,     0,    55,     0,    55,    55,    55,     0,    17,    55,
      16,    15,    14,    13,    55,     0,     0,     0,     0,     0,
       0,     0,    55,    50,    49,     0,     0,     0,    55,    55,
       0,     0,     0,    23,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,    73,     0,     0,     0,    53,     0,    62,     0,    54,
       0,    35,    34,    33,    26,     0,    32,    31,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,   130,    87,     0,     0,     0,   131,
       0,    97,   102,   111,   116,   121,   129,    61,    71,    70,
      29,    55,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,    95,     0,    72,    64,    63,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,   127,   122,   128,
     123,    88,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    55,    55,    55,    55,
      55,    55,    55,    55,     0,    60,    59,    58,    57,    56,
       0,    76,    75,    74,    66,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
     132,   100,    98,   101,    99,   107,   103,   108,   104,   109,
     105,   110,   106,   114,   112,   115,   113,   119,   117,   120,
     118,    24,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    81,    96,    94,     0,    80,    79,    78,
      77,    67,    85,    84,    83,    82,    69,   126,   125,   124,
      45,    44,    43,    42,    41,    40,    39,    38,    37,     0,
      93,     0,    28,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    16,    19,    20,    21,    22,    81,   159,
      74,   155,   264,   115,    68,    69,   116,   117,   118,   145,
     177,   146,   147,   189,   221,   222,   191,   192,   193,   194,
     195,   196
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
     110,    30,    51,    97,  -184,   107,   214,     1,  -184,   197,
     227,   245,  -184,   296,   296,   296,   264,   217,    15,   199,
     296,  -184,  -184,   283,   303,   296,   284,    24,   309,   109,
    -184,  -184,   239,  -184,  -184,  -184,  -184,   310,   325,   345,
     351,   354,   349,   136,   348,   149,  -184,   363,   366,   181,
      45,   112,   241,   108,    45,   367,    45,    23,   370,   373,
     378,   384,   242,  -184,  -184,  -184,   380,   249,   392,   387,
     390,   398,   405,   305,   112,   403,   408,   406,   409,   195,
     416,   112,   414,   430,   435,   437,     6,  -184,  -184,  -184,
     427,    77,   112,   446,   112,   112,   112,   431,  -184,   112,
    -184,  -184,  -184,  -184,   112,   441,   439,   449,   450,   451,
     452,     2,   112,  -184,  -184,   295,   461,   396,   112,   112,
     462,   463,   200,  -184,   464,   225,  -184,   467,   468,   469,
     470,   471,   472,   302,   473,   447,   180,  -184,   474,   177,
     402,  -184,   182,   184,    72,  -184,   396,  -184,   198,  -184,
     475,  -184,  -184,  -184,  -184,   477,  -184,  -184,  -184,   478,
     466,   476,   479,   480,   481,   482,   483,    26,  -184,    45,
      45,    29,    65,    65,    87,   121,   484,   489,   419,    65,
     179,    65,   186,   487,    64,  -184,    55,   193,   230,  -184,
     201,   252,   432,   338,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,   112,   112,   492,   493,   494,   495,   496,   497,   498,
     499,   312,   500,   501,   502,   229,   503,   504,   506,   236,
    -184,   505,   488,   507,  -184,   474,  -184,   508,   509,    34,
     510,   511,    50,  -184,   512,   118,   126,  -184,  -184,  -184,
    -184,  -184,  -184,   237,   244,   251,   258,   290,   297,   304,
     311,   318,   350,   518,   519,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   513,  -184,  -184,  -184,  -184,  -184,
     426,  -184,  -184,  -184,  -184,  -184,    65,   364,   426,   426,
     426,   429,   426,   426,   426,   436,  -184,    65,   357,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,   253,  -184,   253,  -184,
     253,  -184,   253,  -184,   338,  -184,   338,  -184,  -184,  -184,
    -184,  -184,  -184,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   112,  -184,  -184,  -184,   529,  -184,  -184,  -184,
     474,   459,  -184,  -184,  -184,   474,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   530,
    -184,   426,  -184,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,   134,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,    -7,   -38,  -184,   -86,   368,  -184,   335,
     329,  -139,  -184,  -117,    60,  -132,   100,   119,   123,  -183,
    -184,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
     148,   178,    11,   132,   238,   240,    12,   110,   120,   121,
     122,    32,   190,   124,    71,    66,    28,   133,   125,    75,
     111,    77,    79,   148,    78,    39,   134,   210,    29,   148,
     214,    30,    31,   150,     5,   280,    97,    40,   211,   178,
     216,   217,   219,   105,    67,    67,   281,   227,   229,   230,
     232,   284,     6,   114,   236,     7,   234,    63,    64,    65,
     184,   148,   285,    63,    64,    65,   186,    67,   308,   310,
     184,    30,    31,   183,    67,   175,   186,   184,   113,    63,
      64,    65,   185,   186,    67,   187,   188,   176,   218,    63,
      64,    65,   184,    30,    31,   187,   188,     8,   186,    63,
      64,    65,   187,   188,   337,   339,    63,    64,    65,    72,
      42,     1,     9,     2,    43,   253,   254,   187,   188,   287,
      73,    63,    64,    65,   -22,   -22,   184,   289,    30,    31,
     288,   323,   186,   220,   212,   213,   215,    52,   290,   327,
     328,   329,   331,   332,   333,   334,   336,    53,    23,    24,
      56,   187,   188,   148,    34,    63,    64,    65,    57,    37,
      58,   148,   148,   148,   148,   148,   148,   148,   148,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   173,   235,
     228,   170,    61,   179,   184,   181,   174,   231,   175,   171,
     186,   184,    62,   180,   237,   182,   102,   186,   184,   198,
     176,   153,   241,    13,   186,   103,    33,   154,   199,   187,
     188,   242,   353,    63,    64,    65,   187,   188,    26,    10,
      63,    64,    65,   187,   188,    27,   157,    63,    64,    65,
     268,   239,   158,    14,   148,   184,   349,   273,   291,   269,
      44,   186,   184,    85,    45,   293,   274,    86,   186,   184,
      88,    15,   295,    70,    89,   186,   184,    30,    31,   297,
     187,   188,   186,   184,    63,    64,    65,   187,   188,   186,
      25,    63,    64,    65,   187,   188,   243,   244,    63,    64,
      65,   187,   188,   249,   250,    63,    64,    65,   187,   188,
      35,   299,    63,    64,    65,   184,   135,    38,   301,    17,
     136,   186,   184,   166,    18,   303,    95,   167,   186,   184,
      36,    96,   305,   263,    41,   186,   184,    46,   -27,   307,
     187,   188,   186,   184,    63,    64,    65,   187,   188,   186,
      47,    63,    64,    65,   187,   188,   324,   326,    63,    64,
      65,   187,   188,   292,   294,    63,    64,    65,   187,   188,
      48,   309,    63,    64,    65,   184,    49,    54,   338,    55,
      51,   186,   184,    50,   296,   298,   300,   302,   186,   184,
     251,   252,   304,   306,    59,   186,   325,    60,    82,    76,
     187,   188,    80,    83,    63,    64,    65,   187,   188,    84,
      87,    63,    64,    65,   187,   188,    92,   138,    63,    64,
      65,   139,   140,   138,    90,    91,   141,   139,   140,   -65,
      93,    94,   141,    98,    99,   142,   100,   143,   144,   101,
     225,   142,   104,   143,   139,   140,   -65,   138,   106,   141,
     330,   139,   140,   112,   139,   140,   141,   335,   142,   141,
     143,   139,   140,   123,   107,   142,   141,   143,   142,   108,
     143,   109,   119,   126,   127,   142,   169,   143,   245,   246,
     247,   248,   249,   250,   128,   129,   130,   131,   137,   151,
     152,   156,   160,   161,   162,   163,   164,   165,   203,   351,
     168,   197,   200,   201,   202,   172,   149,     0,   204,   223,
       0,   205,   206,   207,   208,   209,   224,   233,   255,   256,
     257,   258,   259,   260,   261,   262,   276,   226,     0,     0,
     265,   266,   267,     0,   271,   270,   272,   275,   277,   322,
     278,   279,   282,   283,   286,   311,   312,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,   352,     0,     0,
       0,   350
};

static const yytype_int16 yycheck[] =
{
     117,   140,     1,     1,   187,   188,     5,     1,    94,    95,
      96,    18,   144,    99,    52,    50,     1,    15,   104,    54,
      14,    56,    57,   140,     1,     1,   112,     1,    13,   146,
       1,    16,    17,   119,     4,     1,    74,    13,    12,   178,
     172,   173,   174,    81,    51,    52,    12,   179,   180,   181,
     182,     1,     1,    91,   186,     4,     1,    34,    35,    36,
       5,   178,    12,    34,    35,    36,    11,    74,   251,   252,
       5,    16,    17,     1,    81,    11,    11,     5,     1,    34,
      35,    36,    10,    11,    91,    30,    31,    23,     1,    34,
      35,    36,     5,    16,    17,    30,    31,     0,    11,    34,
      35,    36,    30,    31,   287,   288,    34,    35,    36,     1,
       1,     1,     5,     3,     5,   201,   202,    30,    31,     1,
      12,    34,    35,    36,    16,    17,     5,     1,    16,    17,
      12,   270,    11,    12,   169,   170,   171,     1,    12,   278,
     279,   280,   281,   282,   283,   284,   285,    11,    14,    15,
       1,    30,    31,   270,    20,    34,    35,    36,     9,    25,
      11,   278,   279,   280,   281,   282,   283,   284,   285,   255,
     256,   257,   258,   259,   260,   261,   262,   263,     1,   186,
       1,     1,     1,     1,     5,     1,     9,     1,    11,     9,
      11,     5,    11,    11,     1,    11,     1,    11,     5,     1,
      23,     1,     1,     6,    11,    10,     7,     7,    10,    30,
      31,    10,   351,    34,    35,    36,    30,    31,     1,     5,
      34,    35,    36,    30,    31,     8,     1,    34,    35,    36,
       1,     1,     7,     6,   351,     5,   322,     1,     1,    10,
       1,    11,     5,     1,     5,     1,    10,     5,    11,     5,
       1,     6,     1,    12,     5,    11,     5,    16,    17,     1,
      30,    31,    11,     5,    34,    35,    36,    30,    31,    11,
       6,    34,    35,    36,    30,    31,    24,    25,    34,    35,
      36,    30,    31,    30,    31,    34,    35,    36,    30,    31,
       7,     1,    34,    35,    36,     5,     1,    13,     1,     3,
       5,    11,     5,     1,     8,     1,     1,     5,    11,     5,
       7,     6,     1,     1,     5,    11,     5,     7,     6,     1,
      30,    31,    11,     5,    34,    35,    36,    30,    31,    11,
       5,    34,    35,    36,    30,    31,   276,   277,    34,    35,
      36,    30,    31,   243,   244,    34,    35,    36,    30,    31,
       5,     1,    34,    35,    36,     5,     5,     9,     1,    11,
      11,    11,     5,     9,   245,   246,   247,   248,    11,     5,
      32,    33,   249,   250,    11,    11,    12,    11,     5,    12,
      30,    31,    12,     5,    34,    35,    36,    30,    31,     5,
      10,    34,    35,    36,    30,    31,     6,     1,    34,    35,
      36,     5,     6,     1,    12,    18,    10,     5,     6,     7,
      12,     6,    10,    10,     6,    19,    10,    21,    22,    10,
       1,    19,     6,    21,     5,     6,     7,     1,    14,    10,
       1,     5,     6,     6,     5,     6,    10,     1,    19,    10,
      21,     5,     6,    12,    14,    19,    10,    21,    19,    14,
      21,    14,     6,    12,    15,    19,     9,    21,    26,    27,
      28,    29,    30,    31,    15,    15,    15,    15,     7,     7,
       7,     7,     5,     5,     5,     5,     5,     5,    12,    20,
       7,   146,     7,     6,     6,    11,   118,    -1,    12,     5,
      -1,    12,    12,    12,    12,    12,     7,    10,     6,     6,
       6,     6,     6,     6,     6,     6,    18,   178,    -1,    -1,
      10,    10,    10,    -1,    10,    12,    10,    12,    11,     6,
      12,    12,    12,    12,    12,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,    -1,     7,    -1,    -1,
      -1,    12
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    38,    39,     4,     1,     4,     0,     5,
       5,     1,     5,     6,     6,     6,    40,     3,     8,    41,
      42,    43,    44,    41,    41,     6,     1,     8,     1,    13,
      16,    17,    50,     7,    41,     7,     7,    41,    13,     1,
      13,     5,     1,     5,     1,     5,     7,     5,     5,     5,
       9,    11,     1,    11,     9,    11,     1,     9,    11,    11,
      11,     1,    11,    34,    35,    36,    68,    50,    51,    52,
      12,    51,     1,    12,    47,    68,    12,    68,     1,    68,
      12,    45,     5,     5,     5,     1,     5,    10,     1,     5,
      12,    18,     6,    12,     6,     1,     6,    51,    10,     6,
      10,    10,     1,    10,     6,    51,    14,    14,    14,    14,
       1,    14,     6,     1,    51,    50,    53,    54,    55,     6,
      53,    53,    53,    12,    53,    53,    12,    15,    15,    15,
      15,    15,     1,    15,    53,     1,     5,     7,     1,     5,
       6,    10,    19,    21,    22,    56,    58,    59,    60,    54,
      53,     7,     7,     1,     7,    48,     7,     1,     7,    46,
       5,     5,     5,     5,     5,     5,     1,     5,     7,     9,
       1,     9,    11,     1,     9,    11,    23,    57,    58,     1,
      11,     1,    11,     1,     5,    10,    11,    30,    31,    60,
      62,    63,    64,    65,    66,    67,    68,    56,     1,    10,
       7,     6,     6,    12,    12,    12,    12,    12,    12,    12,
       1,    12,    68,    68,     1,    68,    62,    62,     1,    62,
      12,    61,    62,     5,     7,     1,    57,    62,     1,    62,
      62,     1,    62,    10,     1,    50,    62,     1,    66,     1,
      66,     1,    10,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    53,    53,     6,     6,     6,     6,     6,
       6,     6,     6,     1,    49,    10,    10,    10,     1,    10,
      12,    10,    10,     1,    10,    12,    18,    11,    12,    12,
       1,    12,    12,    12,     1,    12,    12,     1,    12,     1,
      12,     1,    63,     1,    63,     1,    64,     1,    64,     1,
      64,     1,    64,     1,    65,     1,    65,     1,    66,     1,
      66,     7,     7,    53,    53,    53,    53,    53,    53,    53,
      53,    53,     6,    58,    61,    12,    61,    58,    58,    58,
       1,    58,    58,    58,    58,     1,    58,    66,     1,    66,
       7,     7,     7,     7,     7,     7,     7,     7,     7,    53,
      12,    20,     7,    58
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 61 "tjc.y"
    {
				classDecl = new ClassDeclaration( yylineno, (yyvsp[(3) - (3)].sval) );
				}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 66 "tjc.y"
    {
				yyerror("Expected Identifier in class declaration");
				}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 70 "tjc.y"
    {
				yyerror("Expected 'class' in class declaration");
				}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 74 "tjc.y"
    {
				yyerror("Expected 'public' in class declaration");
				}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 78 "tjc.y"
    {
				yyerror("Error in class declaration");
				}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 90 "tjc.y"
    {
				classDecl->addMember( new FieldDeclaration( yylineno, (yyvsp[(3) - (6)].sval), (yyvsp[(2) - (6)].ival), (LiteralExpression *)(yyvsp[(5) - (6)].xval) ) );
				}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 94 "tjc.y"
    {
					yyerror("Expected ';' in field declaration");
				}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 98 "tjc.y"
    {
				yyerror("Expected literal in field declaration");
				}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 102 "tjc.y"
    {
				yyerror("Expected '=' in field declaration");
				}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 106 "tjc.y"
    {
				yyerror("Expected identifier in field declaration");
				}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 110 "tjc.y"
    {
				yyerror("Expected type in field declaration");
				}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 115 "tjc.y"
    {
				methodDecl = new MethodDeclaration( yylineno, (yyvsp[(3) - (4)].sval), (yyvsp[(2) - (4)].ival) );
				classDecl->addMember ( methodDecl );
				}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 120 "tjc.y"
    {
				methodDecl->setParameters( (yyvsp[(6) - (7)].vdval) );
				}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 125 "tjc.y"
    {
				methodDecl = new MethodDeclaration( yylineno, (yyvsp[(3) - (4)].sval), AstNode::TVOID );
				classDecl->addMember( methodDecl );
				}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 130 "tjc.y"
    {
				methodDecl->setParameters( (yyvsp[(6) - (7)].vdval) );
				}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 135 "tjc.y"
    {
				methodDecl = new MethodDeclaration(yylineno, (yyvsp[(3) - (8)].sval), (yyvsp[(2) - (8)].ival));
				classDecl->addMember( methodDecl );
				}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 140 "tjc.y"
    {
				methodDecl = new MethodDeclaration( yylineno, (yyvsp[(3) - (8)].sval), AstNode::TVOID );
				classDecl->addMember( methodDecl );
				}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 147 "tjc.y"
    {
	  ParameterDeclaration *pd = NULL;
	  if( strcmp( (yyvsp[(6) - (10)].sval), "String" ) == 0 ) {
		pd = new ParameterDeclaration( yylineno, (yyvsp[(9) - (10)].sval), AstNode::TSTRINGA );
	  }
	  else {
	    pd = new ParameterDeclaration( yylineno, (yyvsp[(9) - (10)].sval), 0 );
	  }
	  vector<Declaration*> *pv = new vector<Declaration*>();
	  pv->push_back( pd );
          methodDecl = new MethodDeclaration( yylineno, (yyvsp[(4) - (10)].sval), AstNode::TVOID );
	  methodDecl->setParameters( pv );
	  methodDecl->setPublicMethod( true );
	 classDecl->addMember(methodDecl );
	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 164 "tjc.y"
    {
				yyerror("Expected '(' in method declaration");
				}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 168 "tjc.y"
    {
				yyerror("Expected identifier in method declaration");
				}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 172 "tjc.y"
    {
					yyerror("Expected '}' in method declaration");
				}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 176 "tjc.y"
    {
				yyerror("Expected Identifier in method declaration");
				}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 180 "tjc.y"
    {
					yyerror("Expected '}' in method declaration");
				}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 184 "tjc.y"
    {
				yyerror("Expected '{' in method declaration");
				}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 188 "tjc.y"
    {
				yyerror("Expected ')' in method declaration");
				}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 192 "tjc.y"
    {

				yyerror("Expected '(' in method declaration");
				}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 198 "tjc.y"
    {
				yyerror("Expected '{' in method declaration");
				}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 202 "tjc.y"
    {
				yyerror("Expected ')' in method declaration");
				}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 207 "tjc.y"
    {
				yyerror("Expected identifier in method declaration");
				}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 211 "tjc.y"
    {
				yyerror("Expected ']' in method declaration");
				}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 215 "tjc.y"
    {
				yyerror("Expected '[' in method declaration");
				}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 219 "tjc.y"
    {
				yyerror("Expected identifier in method declaration");
				}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 223 "tjc.y"
    {
				yyerror("Expected '(' in method declaration");
				}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 227 "tjc.y"
    {
				yyerror("Expected 'void' in method declaration");
				}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 231 "tjc.y"
    {
				yyerror("Expected 'static' in method declaration");
				}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 325 "tjc.y"
    {
			(yyval.ival) = AstNode::TINT;
			}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 329 "tjc.y"
    {
			(yyval.ival) = AstNode::TFLOAT;
			}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 335 "tjc.y"
    {
				(yyval.vdval) = new vector<Declaration*>();
				(yyval.vdval)->push_back( (yyvsp[(1) - (1)].dval) );
				}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 340 "tjc.y"
    {
				(yyval.vdval) = (yyvsp[(3) - (3)].vdval);
				(yyval.vdval)->insert( (yyval.vdval)->begin(), (yyvsp[(1) - (3)].dval) );
				}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 345 "tjc.y"
    {
				yyerror("Error in formal parameter list");
				}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 350 "tjc.y"
    {
				(yyval.dval) = new ParameterDeclaration( yylineno, (yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].ival) );
				}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 354 "tjc.y"
    {
					yyerror("Expected identifier in formal parameter");
				}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 359 "tjc.y"
    {
				methodDecl->setVariables( (yyvsp[(1) - (2)].vdval) );
				methodDecl->setBody( (yyvsp[(2) - (2)].bval) );
				}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 365 "tjc.y"
    {
				(yyval.vdval) = (yyvsp[(2) - (2)].vdval);
				(yyval.vdval)->push_back( (yyvsp[(1) - (2)].dval) );
				}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 369 "tjc.y"
    {
				(yyval.vdval) = new vector<Declaration*>();
				}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 374 "tjc.y"
    {
				(yyval.dval) = new VariableDeclaration( yylineno, (yyvsp[(2) - (5)].sval), (yyvsp[(1) - (5)].ival),(LiteralExpression*) (yyvsp[(4) - (5)].xval) );
				}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 378 "tjc.y"
    {
					yyerror("Expected ';' in local declaration");
				}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 382 "tjc.y"
    {
					yyerror("Expected literal in local declaration");
				}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 386 "tjc.y"
    {
					yyerror("Expected '=' in lcoal declaration");
				}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 390 "tjc.y"
    {
					yyerror("Expected identifier in local declaration");
				}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 395 "tjc.y"
    {
				(yyval.bval) = (yyvsp[(2) - (2)].bval);
				(yyval.bval)->prependStatement( (yyvsp[(1) - (2)].tval) );
				}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 400 "tjc.y"
    {
				(yyval.bval) = new BlockStatement(yylineno);
				(yyval.bval)->addStatement( (yyvsp[(1) - (1)].tval) );
				}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 406 "tjc.y"
    {
			(yyval.bval) = (yyvsp[(2) - (2)].bval);
			(yyval.bval)->prependStatement( (yyvsp[(1) - (2)].tval) );
			}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 411 "tjc.y"
    {
				yyerror("Error in statement list");
				}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 415 "tjc.y"
    {
			(yyval.bval) = new BlockStatement( yylineno );
			}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 420 "tjc.y"
    {
				(yyval.tval) = new AssignStatement( yylineno, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].xval) );
				}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 424 "tjc.y"
    {
				(yyval.tval) = new IfStatement( yylineno, (yyvsp[(3) - (5)].xval), (yyvsp[(5) - (5)].tval), NULL );
				}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 428 "tjc.y"
    {
				(yyval.tval) = new IfStatement( yylineno, (yyvsp[(3) - (7)].xval), (yyvsp[(5) - (7)].tval), (yyvsp[(7) - (7)].tval) );
				}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 432 "tjc.y"
    {
				(yyval.tval) = new WhileStatement( yylineno, (yyvsp[(3) - (5)].xval), (yyvsp[(5) - (5)].tval) );
				}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 436 "tjc.y"
    {
				(yyval.tval) = new MethodCallStatement( yylineno, (yyvsp[(1) - (2)].xval) );
				}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 440 "tjc.y"
    {
					yyerror("Expected ';' in statement");
				}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 444 "tjc.y"
    {
				(yyval.tval) = (yyvsp[(2) - (3)].bval);
				}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 448 "tjc.y"
    {
				(yyval.tval) = new EmptyStatement( yylineno );
				}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 452 "tjc.y"
    {
					yyerror("Expected ';' in statement");
				}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 456 "tjc.y"
    {
				yyerror("Expected expression after '='");
				}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 460 "tjc.y"
    {
				yyerror("Expected '=' in statement");
				}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 464 "tjc.y"
    {
				yyerror("Expected statement in IF");
				}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 468 "tjc.y"
    {
				yyerror("Expected ')' in IF");
				}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 472 "tjc.y"
    {
				yyerror("Expected expression in IF");
				}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 476 "tjc.y"
    {
				yyerror("Expected '(' in IF statement");
				}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 480 "tjc.y"
    {
				yyerror("Expected 'while' or 'if'");
				}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 484 "tjc.y"
    {
				yyerror("Expected statement within while loop");
				}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 488 "tjc.y"
    {
				yyerror("Expected ')' in while loop");
				}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 492 "tjc.y"
    {
				yyerror("Expected expression within parentheses of while loop");
				}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 496 "tjc.y"
    {
				yyerror("Expected '(' after while");

				}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 504 "tjc.y"
    {
			(yyval.tval) = new ReturnStatement( yylineno, NULL , (yyvsp[(2) - (3)].xval) );
			}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 508 "tjc.y"
    {
			(yyval.tval) = new ReturnStatement( yylineno, NULL, NULL );
			}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 512 "tjc.y"
    {
					yyerror("Expected ';' in return statement");
				}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 516 "tjc.y"
    {
				yyerror("Expected expression in return statement");
				}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 520 "tjc.y"
    {
					yyerror("Expected ';' in return statement");
				}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 525 "tjc.y"
    {
			(yyval.xval) = new MethodCallExpression(yylineno, NULL, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].aval) );
			}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 529 "tjc.y"
    {
			(yyval.xval) = new MethodCallExpression(yylineno, NULL, (yyvsp[(1) - (3)].sval), (vector<Expression*> *)NULL );
			}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 533 "tjc.y"
    {
			(yyval.xval) = new MethodCallExpression(yylineno, (yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].aval) );
			}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 537 "tjc.y"
    {
			(yyval.xval) = new MethodCallExpression(yylineno, (yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].sval), (vector<Expression*> *) NULL) ;
			}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 554 "tjc.y"
    {
				(yyval.aval) = new vector<Expression *>();
				(yyval.aval)->push_back( (yyvsp[(1) - (1)].xval) );
				}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 559 "tjc.y"
    {
				(yyval.aval) = (yyvsp[(3) - (3)].aval);
				(yyval.aval)->push_back( (yyvsp[(1) - (3)].xval) );
				}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 566 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 570 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::EQOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 574 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::NEOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 578 "tjc.y"
    {
				yyerror("Expected expression after '=='");
				}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 582 "tjc.y"
    {
				yyerror("Expected expression after '!='");
				}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 587 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 591 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::LTOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 595 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::GTOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 599 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::LEOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 603 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::GEOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 607 "tjc.y"
    {

				yyerror("Expected expression after '<'");
				}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 612 "tjc.y"
    {
				yyerror("Expected expression after '>'");
				}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 616 "tjc.y"
    {
				yyerror("Expected expression after '<='");
				}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 620 "tjc.y"
    {
				yyerror("Expected expression after '>='");
				}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 625 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 629 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::ADDOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 633 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno, AstNode::SUBOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 637 "tjc.y"
    {
				yyerror("Expected multiplicative expression after '+'");
				}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 641 "tjc.y"
    {
				yyerror("Expected multiplicative expression after '-'");
				}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 646 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 650 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno,AstNode::MULOP ,(yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) ); 
			}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 654 "tjc.y"
    {
			(yyval.xval) = new BinaryExpression(yylineno,AstNode::DIVOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval) );
			}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 658 "tjc.y"
    {
				yyerror("Expected unary expression in multiplicative expression");
				}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 662 "tjc.y"
    {

				yyerror("Expected unary expression in multiplicative expression");
				}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 668 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 672 "tjc.y"
    {
			(yyval.xval) = new UnaryExpression(yylineno,AstNode::ADDOP,(yyvsp[(2) - (2)].xval) );
			}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 676 "tjc.y"
    {
			(yyval.xval) = new UnaryExpression(yylineno, AstNode::SUBOP, (yyvsp[(2) - (2)].xval) );
			}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 680 "tjc.y"
    {
			(yyval.xval) = new CastExpression(yylineno,(yyvsp[(2) - (4)].ival),(yyvsp[(4) - (4)].xval));
			}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 684 "tjc.y"
    {
					yyerror("Expected unary expression in unary expression");

				}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 689 "tjc.y"
    {

				yyerror("Expected ')' in unary expression");
				}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 694 "tjc.y"
    {
				yyerror("Expected unary expression after '+'");
				}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 698 "tjc.y"
    {
				yyerror("Expected unary expression after '-'");
				}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 703 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 707 "tjc.y"
    {
			(yyval.xval) = new ReferenceExpression(yylineno,(yyvsp[(1) - (1)].sval));
			}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 711 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(1) - (1)].xval);
			}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 715 "tjc.y"
    {
			(yyval.xval) = (yyvsp[(2) - (3)].xval);
			}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 719 "tjc.y"
    {
					yyerror("Expected expression in primary expression");
				}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 724 "tjc.y"
    {
					yyerror("Expected ')' in primary expression");
				}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 729 "tjc.y"
    {
			(yyval.xval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TINT);
			}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 733 "tjc.y"
    {
			(yyval.xval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TFLOAT);
			}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 737 "tjc.y"
    {
			(yyval.xval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TSTRING);
			}
    break;



/* Line 1455 of yacc.c  */
#line 2935 "y.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 741 "tjc.y"

int yyerror( const char *msg) {
cerr << "Line: " << yylineno << ": " << msg << endl; cerr.flush();
}

