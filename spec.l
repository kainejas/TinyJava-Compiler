%{
using namespace std;
#include "Ast.h"
#include <string.h>
#include "y.tab.h"
%}
%option yylineno
digit [0-9]
letter [a-zA-Z]
NonZeroDigit [1-9]
DecimalIntegerLiteral 0 | {NonZeroDigit}{Digit}*
exponent [eE]([+-]{Digit}+|{Digit}+)
commentStart "/*"
commentEnd "*/"
%%
[ \t\n\r] ;
{commentStart}(.|[\r\n])*{commentEnd} ;
"//".*\n ;
"+" {  return PLUS;}
"-" { return MINUS;}
"*" { return MULT;}
"/" { return DIVIDE;}
"(" { return LPAR;}
")" { return RPAR;}
"{" { return LBRACE;}
"}" { return RBRACE;}
"[" { return LBRACK;}
"]" { return RBRACK;}
";" { return SEMI;}
"=" { return EQ;}
"==" { return DOUBLEEQ;}
"!=" { return NEQ;}
"<" { return LESS;}
">" { return GREATER;}
"<=" { return LEQ;}
">=" { return GEQ;}
"," { return COMMA;}
"." { return PERIOD;}
 
({digit}+"."{digit}+[fF])|({digit}+"."{digit}+([eE]([+-]{digit}+)|{digit}+)[fF]) { yylval.sval = strdup(yytext); return FCONST;}
"0"|([1-9]|{digit})* { yylval.sval = strdup(yytext); return ICONST;}
\".*\"   { yylval.sval = strdup(yytext); return SCONST;}
"public" { return PUBLIC;}
"class" { return CLASS;}
"static" { return STATIC;}
"void" { return VOID;}
"int" { return INT;}
"float" { return FLOAT;}
"if" { return IF;}
"else" { return ELSE;}
"while" { return WHILE;}
"return" { return RETURN;}
{letter}({letter}|{digit})* { yylval.sval = strdup(yytext);  return IDENT;} 
%%
int yywrap() { return 1;} 
