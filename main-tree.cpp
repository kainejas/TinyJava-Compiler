#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "Ast.h"
#ifndef DICTBUILDER_H
#include "DictBuilder.h"
#endif
#ifndef TYPECHECKER_H
#include "TypeChecker.h"
#endif
#ifndef JASMINTRANSLATOR_H
#include "JasminTranslator.h"
#endif
void fatal(const char*, const char*);
const char *pgm_name;


#ifdef YYDEBUG
//extern int yydebug;
#endif

extern FILE *yyin;
extern int yylineno;
int yyparse (void);

ClassDeclaration *classDecl= NULL;
Expression *expTree = NULL;
FILE * code;
int main(int argc, const char **argv )
{
pgm_name = argv[0];

#ifdef YYDEBUG
//	yydebug = 1;
#endif
std::string temp;
if( argc > 1) {

if(strstr(argv[1],".java") != NULL && strcmp(strstr(argv[1],".java"),".java") == 0)
{
	yyin = fopen( argv[1], "r");
//	printf("%s\n",argv[1]);
     temp = std::string(argv[1]);
	
	if(yyin == NULL)
	fatal( "Cannot open input file: ", argv[1]);	//fatal error
	}
	else
	{
		fatal( "Invalid file type: ", argv[1]);	//fatal error
	}
	
	}
	else
	{
	fatal("No input file provided: ", argv[0]);
	}

	classDecl = NULL;
	
	yyparse(); 		//Parse the input file, creating the AstTree
	
	DictBuilder *dictBuilder = new DictBuilder(); 
	if(classDecl != NULL)
	{
		classDecl->accept( dictBuilder ); 		//Build the Symbol Table using the AstTree
	}
	else
	{
	 fatal("Error parsing file. Compilation aborted.", "");
	}
		
	TypeChecker *typeCheck = new TypeChecker(dictBuilder->getSymbolTable(), 0,  temp.substr(0,temp.length()-5).c_str());

	if(!dictBuilder->getError())
	{
		classDecl->accept(typeCheck); //Perform Various Semantic Checks
	}
	else
	{
		fatal("Error while building scopes. Compilation aborted.", "");
	}
	
	if(!typeCheck->getError())
	{
		classDecl->accept(new JasminTranslator());  //Translate Program to .class file
	}
	else
	{
		fatal("Error during type checking. Compilation aborted.", "");
	}
	return 0;
}

void fatal( const char *msg1, const char *msg2) 
{
	printf("%s%s\n",msg1,msg2);
	exit(1);
}