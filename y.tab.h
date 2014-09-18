
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 139 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


