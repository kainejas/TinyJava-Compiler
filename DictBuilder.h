// Gnu Emacs C++ mode:  -*- C++ -*-


#ifndef DICTBUILDER_H
#define DICTBUILDER_H

#include <iostream>
using namespace std;
#include "Ast.h"
#include "SymbolTable.h"
class DictBuilder: public AstVisitor {

private:
	Class *classEntry;
	SymbolTable *symtab;
	bool err;


public:

  DictBuilder(  )
  {
	err = false;
  }

	bool getError(){ return err;}
	SymbolTable *getSymbolTable();

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
