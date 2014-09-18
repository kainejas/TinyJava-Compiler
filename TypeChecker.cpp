// Gnu Emacs C++ mode:  -*- C++ -*-



#include <iostream>
#include "TypeChecker.h"

using namespace std;

Method *currentMethod;
void 
TypeChecker::visit( MethodDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "TypeChecker::visit: MethodDeclaration: NULL argument" );

  if( aDeclNode->getBody() == NULL )
    throw AstException( "TypeChecker::visit: MethodDeclaration: body is NULL" );


currentMethod =((Method*)( aDeclNode->getEntry()));
	symtab->pushScope(((Method*)(aDeclNode->getEntry()))->getDictionary());
	
  // print (visit) the parameters
  if( aDeclNode->getParameters() != NULL ) {
    for( int i = 0; i < aDeclNode->getParameters()->size(); i++ ) {
      
      aDeclNode->getParameters()->at( i )->accept( this );
      
    }
  }

  // print (visit) the variables
  if( aDeclNode->getVariables() != NULL ) {
    for( int i = 0; i < aDeclNode->getVariables()->size(); i++ ) {
      
      aDeclNode->getVariables()->at( i )->accept( this );
      
    }
  }
	
  
  aDeclNode->getBody()->accept( this );
  
symtab->popScope();
}

void
TypeChecker::visit( FieldDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "TypeChecker::visit: FieldDeclaration: NULL argument" );



	if(((Field*)(aDeclNode->getEntry()))->getFType() != aDeclNode->getInitLiteral()->getType())
	{
	cout << "Error " << aDeclNode->getLineNo() << ": Illegal Field Initialization: " << aDeclNode->getName() << endl;
	err = true;
	}


}

void
TypeChecker::visit( ParameterDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "TypeChecker::visit: ParameterDeclaration: NULL argument" );
  



}
void 
TypeChecker::visit( VariableDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "TypeChecker::visit: VariableDeclaration: NULL argument" );

 	if(((Variable*)(aDeclNode->getEntry()))->getVType() != aDeclNode->getInitLiteral()->getType())
	{
	cout << "Error " << aDeclNode->getLineNo() << ": Illegal Variable initialization: " << aDeclNode->getName() << endl;
	err = true;
	}


}

void
TypeChecker::visit( ClassDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "TypeChecker::visit: ClassDeclaration: NULL argument" );

    if(strcmp(aDeclNode->getName(), fileName) != 0)
    {
        std::cout << "Error " << aDeclNode->getName() << " not same name as file." << std::endl;
		err = true;
	}

	
	
  if( aDeclNode->getMembers() == NULL ) {
  }
  else {
    // print (visit) members
    for( int i = 0; i < aDeclNode->getMembers()->size(); i++ ) {
      // check if this member is really there
      if( aDeclNode->getMember( i ) == NULL )
	throw AstException( "TypeChecker::visit: DCLASS: member is NULL" );
      // now, visit the next class member
      
      aDeclNode->getMember( i )->accept( this );
      
    }
  }
}


void
TypeChecker::visit( LiteralExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: NULL argument in LiteralExpression" );

	
}

void
TypeChecker::visit( ReferenceExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: ReferenceExpression: NULL argument" );



		
  // print (visit) the index expression, if provided
  if( anExpNode->getExpression() != NULL ) {
    anExpNode->getExpression()->accept( this );

  }
	anExpNode->setEntry(symtab->lookup(anExpNode->getName()));	
	if(symtab->lookup(anExpNode->getName()) == 0)
	{
	cout << "Error " << anExpNode->getLineNo() << ": unknown identifier \"" << anExpNode->getName() << "\"" << endl;
	err = true;
	}
	else
	{
		
		switch(anExpNode->getEntry()->getType())
		{
		case 0: 
			anExpNode->setType(((Variable*)(anExpNode->getEntry()))->getVType());
			break;
		case 3:
			anExpNode->setType(((Field*)(anExpNode->getEntry()))->getFType());
			break;
		case 4:
			anExpNode->setType(((Parameter*)(anExpNode->getEntry()))->getPType());
			break;	
		default:
			cout << "Error " << anExpNode->getLineNo() << " Expected variable, field, or parameter in reference expression \"" << anExpNode->getEntry()->getName() << "\"" << endl;
			err = true;
		}
		
		
	}
}

void
TypeChecker::visit( NewExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: NewExpression: NULL argument" );

  if( anExpNode->getExpression() == NULL )
    throw AstException( "TypeChecker::visit: NewExpression: size expression is NULL" );


  
  anExpNode->getExpression()->accept( this );
  
	if(anExpNode->getExpression()->getType() == AstNode::TINT)
	{
	anExpNode->setType(AstNode::TINT);
	}
	else if(anExpNode->getExpression()->getType() == AstNode::TFLOAT)
	{
	anExpNode->setType(AstNode::TFLOAT);
	}
	else
	{
	cout << "Error: Incorrect type for new expression" << endl;
	}
}

void
TypeChecker::visit( UnaryExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: UnaryExpression: NULL argument" );

  if( anExpNode->getOperand() == NULL )
    throw AstException( "TypeChecker.visit: UnaryExpression: operand is NULL" );

/*
  if( anExpNode->isPostfix() )
    cout << " postfix" << endl;
  else
    cout << " prefix" << endl;
*/


  anExpNode->getOperand()->accept( this );

	if(anExpNode->getOperand()->getType() != AstNode::TINT && anExpNode->getOperand()->getType() != AstNode::TFLOAT)
	{
	cout << "Error "  << anExpNode->getLineNo() << ": Unary operator applied to non-numeric value." << endl;
	err = true;
	}
	else
	{
	anExpNode->setType(anExpNode->getOperand()->getType());
	}
}

void
TypeChecker::visit( BinaryExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: BinaryExpression: NULL argument" );

  if( anExpNode->getLeftOperand() == NULL )
    throw AstException( "TypeChecker.visit: EBINARY left operand is NULL" );

  if( anExpNode->getRightOperand() == NULL )
    throw AstException( "TypeChecker.visit: EBINARY right operand is NULL" );


  anExpNode->getLeftOperand()->accept( this );
  anExpNode->getRightOperand()->accept( this );

	int t1 = anExpNode->getLeftOperand()->getType();
	int t2 = anExpNode->getRightOperand()->getType();
	
	if(t1 != AstNode::TINT && t1 != AstNode::TFLOAT)
	{
	cout << "Error "  << anExpNode->getLineNo() << ":  Binary operator applied to non-numeric value. " << AstNode::type2string(t1) <<	endl;
	err = true;
	return;
	}
	if(t2 != AstNode::TINT && t2 != AstNode::TFLOAT)
	{
	cout << "Error "  << anExpNode->getLineNo() << ": Binary operator applied to non-numeric value (Right hand side). " << AstNode::type2string(t2) << endl;
	err = true;
	return;
	}

	
	
if(t1 == AstNode::TFLOAT)
	{
		if(t2 != AstNode::TFLOAT && t2 != AstNode::TINT)
		{
		cout << "Error " << anExpNode->getLineNo() << ":  Incompatible operands to a binary operator: " << AstNode::operator2string(anExpNode->getOperator()) << endl;
		err = true;
		}

	}
	/*
	if(t1 == AstNode::TINT && t2 != t1)
	{
	cout << "bError " << anExpNode->getLineNo() << ": Incompatible operands to a binary operator: " <<   AstNode::operator2string(anExpNode->getOperator()) << endl;
	}
	*/
	
	if(anExpNode->getOperator() >= 4)
	{
	anExpNode->setType(AstNode::TBOOL);

	}
	else
	{
	if(t1 != t2)
	{
	anExpNode->setType(AstNode::TFLOAT);
	}
	else
	{
	anExpNode->setType(t1);
	}

	}
}

void
TypeChecker::visit( CastExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: CastExpression: NULL argument" );

  if( anExpNode->getOperand() == NULL )
    throw AstException( "TypeChecker::visit: ECAST operand is NULL" );


  anExpNode->getOperand()->accept( this );
	

	if(anExpNode->getCastToType() != AstNode::TINT && anExpNode->getCastToType() != AstNode::TFLOAT)
	{

	cout << "Error " <<  anExpNode->getLineNo() << " Cast applied to non-numeric value \"" << AstNode::type2string(anExpNode->getOperand()->getType()) << "\"" <<  endl;
	err = true;
	}
	else
	{
	anExpNode->setType(anExpNode->getCastToType());
	}


}

void
TypeChecker::visit( MethodCallExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "TypeChecker::visit: NULL argument in MethodCallExpression" );



  if( anExpNode->getClassName() != NULL ) {

  	if(symtab->simpleIOlookup(anExpNode->getClassName(),anExpNode->getMethodName()) == 0) 
	{
	cout << "Error " <<  anExpNode->getLineNo() << ": a non-method name was used as a method \""  << anExpNode->getMethodName()  << "\"" <<  endl;
	err = true;
	}
	else
	{
	anExpNode->setEntry(symtab->lookup(anExpNode->getMethodName()));
	}
  
  
 }
 else
 {
	if(symtab->lookup(anExpNode->getMethodName())->getEType() != Entry::MET)
	{
	cout << "Error " <<  anExpNode->getLineNo() << ": a non-method name was used as a method \""  << anExpNode->getMethodName()  << "\"" <<endl;
	err = true;
	}
	else
	{
	anExpNode->setEntry(symtab->lookup(anExpNode->getMethodName()));
	}
	
}
  // check if any arguments have been provided
  if( anExpNode->getArguments() == NULL ) {
		
  }
  else {

	std::vector<int> p = (*(((Method*)(symtab->lookup(anExpNode->getMethodName())))->getParams()));
    	if(p.size() != anExpNode->getArguments()->size())
	{
	cout << "Error " <<  anExpNode->getLineNo() << ": Incorrect number of arguments for method \""  << anExpNode->getMethodName()  << "\"" << endl;
	err = true;
	return;	
	}
	
	for( int i = 0; i < anExpNode->getArguments()->size(); i++ ) {
      
      anExpNode->getArgument( i )->accept( this );	
if(anExpNode->getArgument(i)->getType() != ((Method*)(symtab->lookup(anExpNode->getMethodName())))->getParams()->at(i))
	{
	cout << "Error " << anExpNode->getLineNo() << ": Incompatible argument in a call to: "  << anExpNode->getMethodName() << endl;
	err = true;
	/*
	expected param of type " << AstNode::type2string(((Method*)(anExpNode->getEntry()))->getParams()->at(i)) 
	<< " in method \"" << anExpNode->getMethodName() << "\" but received type " << AstNode::type2string(anExpNode->getArgument(i)->getType()) << endl;
*/
	}

	
    }
  }
}

void
TypeChecker::visit( AssignStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: AssignStatement: NULL argument" );
      
  if( anStmtNode->getExpression() == NULL )
      throw AstException( "PrintStatementVisitor::visit: AssignStatement: NULL expression" );





  // print (visit) the index expression, if given
  if( anStmtNode->getIndex() != NULL ) {

    anStmtNode->getIndex()->accept( this );
 
	  
}

// print (visit) the right-hand side expression
  anStmtNode->getExpression()->accept( this );
	
	  	
	anStmtNode->setEntry(symtab->lookup(anStmtNode->getLHSName()));
	
	if(anStmtNode->getEntry() == 0)
	{
	cout << "Error " <<  anStmtNode->getLineNo() << ":  unknown identifier \""<< anStmtNode->getLHSName() << "\"" << endl;
	err = true;
	return;
	}

	int t1 = 0;
		int t2 =0;
	switch(anStmtNode->getEntry()->getEType())
	{
	case 0: t1 = ((Variable*)(anStmtNode->getEntry()))->getVType();
		break;
	
	case 3: t1 = ((Field*)(anStmtNode->getEntry()))->getFType();
		break;
	
	case 4: t1 = ((Parameter*)(anStmtNode->getEntry()))->getPType();
		break;
	default: 	cout << "Error " << anStmtNode->getLineNo() << " Expected variable, field, or parameter in assignment statement: " << anStmtNode->getLHSName() << endl;
err = true;	
	return;
	
	}
	t2 = anStmtNode->getExpression()->getType();
	
	if(t1 == AstNode::TFLOAT)
	{
		if(t2 != AstNode::TFLOAT && t2 != AstNode::TINT)
		{
		cout << "Error " << anStmtNode->getLineNo() << ": Illegal assignment: " << anStmtNode->getLHSName() << endl;
		err = true;
		}

	}
	if(t1 == AstNode::TINT && t2 != t1)
	{
	cout << "Error " << anStmtNode->getLineNo() << ": Illegal assignment: " << anStmtNode->getLHSName() << endl;
	err = true;
	}
}

void
TypeChecker::visit( WhileStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: WhileStatement: NULL argument" );

  if( anStmtNode->getExpression() == NULL )
      throw AstException( "TypeChecker::visit: WhileStatement: expression is NULL" );

  if( anStmtNode->getBodyStatement() == NULL )
      throw AstException( "TypeChecker::visit: WhileStatement: statement is NULL" );



  // print (visit) the control expression
  anStmtNode->getExpression()->accept( this );
	if(anStmtNode->getExpression()->getType() != AstNode::TBOOL)
	{
	cout << "Error  " << anStmtNode->getLineNo() << ": a boolean expression expected in while loop" << endl;
	err = true;
	}
  // now, print (visit) the while statement body
  anStmtNode->getBodyStatement()->accept( this );
}

void
TypeChecker::visit( ForStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: ForStatement: NULL argument" );

  if( anStmtNode->getInit() == NULL )
    throw AstException( "TypeChecker::visit: ForStatement: initiatlization expression is NULL" );

  if( anStmtNode->getTerm() == NULL )
    throw AstException( "TypeChecker::visit: ForStatement: termination expression is NULL" );

  if( anStmtNode->getUpd() == NULL )
    throw AstException( "TypeChecker::visit: ForStatement: update expression is NULL" );

  if( anStmtNode->getBodyStatement() == NULL )
    throw AstException( "TypeChecker::visit: ForStatement: statement is NULL" );


  
	if(symtab->lookup(anStmtNode->getLHSName()) == 0)
	{
	cout << "Error " << anStmtNode->getLineNo() << ": unknown identifier: " << anStmtNode->getLHSName() << endl;
	err = true;
	}
	int lt = 0;
	switch(symtab->lookup(anStmtNode->getLHSName())->getEType())
	{
	case 0: lt = ((Variable*)(symtab->lookup(anStmtNode->getLHSName())))->getVType();
		break;
	
	case 3:  lt = ((Field*)(symtab->lookup(anStmtNode->getLHSName())))->getFType();
		break;
	
	case 4:   lt = ((Parameter*)(symtab->lookup(anStmtNode->getLHSName())))->getPType();
		break;
	default: 	cout << "Error " << anStmtNode->getLineNo() << " Expected variable, field, or parameter in for statement:  " << anStmtNode->getLHSName();
				err = true;
				return;
	
	}
	


  // print (visit) the index expression, if given
  if( anStmtNode->getIndex() != NULL ) {
    
    anStmtNode->getIndex()->accept( this );
    
  }

  // print (visit) the initialization expression
  
  anStmtNode->getInit()->accept( this );
  
	
		int t2 = anStmtNode->getInit()->getType();
		if(lt == AstNode::TFLOAT)
	{
		if(t2 != AstNode::TFLOAT && t2 != AstNode::TINT)
		{
		cout << "Error: incompatible type used with type int" << endl;
		}

	}
	if(lt == AstNode::TINT && t2 != lt)
	{
	cout << "Error: incompatible type used with type int" << endl;
	}




  // print (visit) the termination expression
  
  anStmtNode->getTerm()->accept( this );
  

	if(anStmtNode->getTerm()->getType() != AstNode::TBOOL)
	{
	cout << "Error " <<  anStmtNode->getLineNo() << ": a boolean expression expected in for statement" << endl;
	err = true;
	}

  // print (visit) the update expression
  
  anStmtNode->getUpd()->accept( this );
  

  // now, visit the while statement body
  
  anStmtNode->getBodyStatement()->accept( this );
  
}

void
TypeChecker::visit( IfStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: IfStatement: NULL argument" );

  if( anStmtNode->getExpression() == NULL )
    throw AstException( "TypeChecker::visit: IfStatement: expression is NULL" );

  if( anStmtNode->getThenStatement() == NULL )
    throw AstException( "TypeChecker::visit: IfStatement: then statement is NULL" );



  // print (visit) the control expression
  anStmtNode->getExpression()->accept( this );
	
	if(anStmtNode->getExpression()->getType() != AstNode::TBOOL)
	{
	cout << "Error " << anStmtNode->getLineNo() << " : expected expression of type boolean in control expression of if-statement" << endl;
	err = true;
	}


  // print (visit) the if's then statement
  anStmtNode->getThenStatement()->accept( this );

  // print (visit) the if's else statement, if present
  if( anStmtNode->getElseStatement() != NULL ) {
    anStmtNode->getElseStatement()->accept( this );
  }
}

void
TypeChecker::visit( ReturnStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: NULL argument in ReturnStatement" );
	int methodReturn = 0;
	if(currentMethod== 0)
	{
		std::cout << "Could not find method associated with return statement " << std::endl;

	}
	else
		{
		methodReturn = currentMethod->getRetType();
		}

  // print (visit) the return value expression
  if( anStmtNode->getExpression() != NULL ) {
    anStmtNode->getExpression()->accept( this );
		
	//if return statement has expression
		 if(methodReturn == AstNode::TVOID)
		{
			std::cout << "Error " << anStmtNode->getLineNo() << ": Return with a value from a void method" << std::endl;
			err = true;
		}
		 
		else  if( methodReturn != anStmtNode->getExpression()->getType())
		{
			int t2 = anStmtNode->getExpression()->getType();
			

	if(methodReturn == AstNode::TFLOAT)
	{
		if(t2 != AstNode::TFLOAT && t2 != AstNode::TINT)
		{
		cout << "Error " << anStmtNode->getLineNo() << ": incompatible value returned from a method: " << currentMethod->getName() << endl;
		err = true;
		}

	}
	if(methodReturn == AstNode::TINT && t2 != methodReturn)
	{
	cout << "Error " << anStmtNode->getLineNo() << ": incompatible value returned from a method: " << currentMethod->getName() << endl;
	err = true;
	}

		
	}
	
		
	
  }else{

		if(methodReturn != AstNode::TVOID)
		{
			std::cout << "Error " << anStmtNode->getLineNo() << ": Return with no value from  non-void method" << std::endl;
			err = true;
		}
  }
}

void
TypeChecker::visit( BlockStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: BlockStatement: NULL argument" );

  if( anStmtNode->getStatements() == NULL )
    throw AstException( "TypeChecker::visit: BlockStatement: statements are NULL" );



  // visit (print) all statements
  for( int i = 0; i < anStmtNode->getStatements()->size(); i++ ) {

    // check if this Statement is OK to visit
    if( anStmtNode->getStatements()->at( i ) == NULL )
      throw AstException( "TypeChecker::visit: BlockStatement: operand statement at position %d is NULL" );

    // visit the block's next statement
    anStmtNode->getStatements()->at( i )->accept( this );
  }
}

void
TypeChecker::visit( MethodCallStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: MethodCallStatement: NULL argument" );

  if( anStmtNode->getExpression() == NULL )
    throw AstException( "PrintStatementVisitor::visit: MethodCallStatement: MethodCallExpression is NULL" );



  // print (visit) the MethodCallExpression (MethodCallStatement serves as a wrapper only)
  anStmtNode->getExpression()->accept( this );
}

void
TypeChecker::visit( EmptyStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: EmptyStatement: NULL argument" );

}
