// Gnu Emacs C++ mode:  -*- C++ -*-


#ifndef JASMINTRANSLATOR_H
#define JASMINTTRANSLATOR_H


#include <iostream>
#include <stdio.h>	
#include <fstream>
#include <sstream>
using namespace std;

#include "SymbolTable.h"
#include "Ast.h"


class JasminTranslator: public AstVisitor {

public:
	Class *classEntry;
	  FILE *code;
	int labelCount;
  JasminTranslator( )
  {
	labelCount = 0;
	
  }

  
  void emitInstruction( const char *name ); // e.g. for iadd
void emitInstruction( const char *name, int index ); // e.g. for iload 0
void emitInstruction( const char *name, const char *label ); // e.g. for goto Label1
void emitLabel( const char *name ); // e.g. for Label1
void emitDirective( const char *name, const char *arg ); //e.g. for.end method 
  void visit( MethodDeclaration *aDeclNode );
  void visit( FieldDeclaration *aDeclNode );
  void visit( ParameterDeclaration *aDeclNode );
  void visit( VariableDeclaration *aDeclNode );
  void visit( ClassDeclaration *aDeclNode );
  void visit( LiteralExpression *anExpNode );
  void visit( ReferenceExpression *anExpNode );
  void visit( NewExpression *anExpNode );
  void visit( UnaryExpression *anExpNode );
  void visit( BinaryExpression *anExpNode );
  void visit( CastExpression *anExpNode );
  void visit( MethodCallExpression *anExpNode );
  void visit( AssignStatement *anStmtNode );
  void visit( WhileStatement *anStmtNode );
  void visit( ForStatement *anStmtNode );
  void visit( IfStatement *anStmtNode );
  void visit( ReturnStatement *anStmtNode );
  void visit( BlockStatement *anStmtNode );
  void visit( MethodCallStatement *anStmtNode );
  void visit( EmptyStatement *anStmtNode );
};



#endif
