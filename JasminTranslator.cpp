// Gnu Emacs C++ mode:  -*- C++ -*-



#include <iostream>
#include "JasminTranslator.h"

using namespace std;



void JasminTranslator::emitInstruction( const char *name ) // e.g. for iadd
{
	fprintf(code, "\t%s\n",name);
	fflush(code);
}
void JasminTranslator::emitInstruction( const char *name, int index ) // e.g. for iload 0
{
	fprintf(code,"\t%s\t%i\n",name,index);
	fflush(code);
}
void JasminTranslator::emitInstruction( const char *name, const char *label ) // e.g. for goto Label1
{
	fprintf(code,"\t%s\t%s\n",name,label);
	fflush(code);
}
void JasminTranslator::emitLabel( const char *name ) // e.g. for Label1
{
	fprintf(code,"\t%s:\n",name);
	fflush(code);
}
void JasminTranslator::emitDirective( const char *name, const char *arg ) //e.g. for.end method 
{
	fprintf(code,"\t.%s\t%s\n",name,arg);
	fflush(code);
}

void JasminTranslator::visit( MethodDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "JasminTranslator::visit: MethodDeclaration: NULL argument" );

  if( aDeclNode->getBody() == NULL )
    throw AstException( "JasminTranslator::visit: MethodDeclaration: body is NULL" );
	

	
	int count = 0;
	std::string desc = std::string(aDeclNode->getName()+ std::string("("));
  // print (visit) the parameters
  if( aDeclNode->getParameters() != NULL ) {
    for( int i = 0; i < aDeclNode->getParameters()->size(); i++ ) {
	count++;
      aDeclNode->getParameters()->at( i )->accept( this );
	  switch(((Parameter*)( ((ParameterDeclaration*)(aDeclNode->getParameters()->at(i)))->getEntry()))->getPType())
	  {
	  case AstNode::TINT:
	  desc += std::string("I");
	  break;
	  
	  case AstNode::TFLOAT:
	   desc += std::string("F");
	  break;
	  
	  case AstNode::TINTA:
	   desc += std::string("[I");
	  break;
	  
	  case AstNode::TFLOATA:
	   desc += std::string("[F");
	  break;
	  
	  case AstNode::TSTRING:
	   desc += std::string("Ljava/lang/String;");
	  break;
	  
	  case AstNode::TSTRINGA:
	  desc += std::string("[Ljava/lang/String;");
	  break;
	  
	  }
      
    }
	desc += std::string(")");
  }
  
  else
  {
  	desc += std::string(")");
  }
  
  switch(((Method*)(aDeclNode->getEntry()))->getRetType())
  {
	case AstNode::TINT:
	desc += std::string("I");
	break;
	
	case AstNode::TFLOAT:
	desc += std::string("F");
	break;
	
	case AstNode::TVOID:
	desc += std::string("V");
	break;
  
  }
  
  
  if(aDeclNode->isPublicMethod())
  {
   emitDirective("method public static", desc.c_str());
  }
  else{
  
  emitDirective("method static", desc.c_str());
  }
    emitDirective("limit stack", std::string("25").c_str());
  std::stringstream ss;
  ss << ((Method*)(aDeclNode->getEntry()))->getCount();
  emitDirective("limit locals", ss.str().c_str()); //TODO:: ???
  ss.str("");
  // print (visit) the variables
  if( aDeclNode->getVariables() != NULL ) {
    for( int i = 0; i < aDeclNode->getVariables()->size(); i++ ) {
	count++;
      aDeclNode->getVariables()->at( i )->accept( this );
      
    }
  }
  // print (visit) the body
  aDeclNode->getBody()->accept( this );
  emitDirective("end", "method");
}

void JasminTranslator::visit( FieldDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "JasminTranslator::visit: FieldDeclaration: NULL argument" );
	
	std::string desc = std::string(std::string(aDeclNode->getName()) + std::string(" "));
	if(aDeclNode->getType() == AstNode::TINT)
	{
	desc += std::string("I");
	}
	else if(aDeclNode->getType() == AstNode::TINT)
	{
	desc += std::string("F");
	}
	
	emitDirective("field static ", desc.c_str());
	
}

void
JasminTranslator::visit( ParameterDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "JasminTranslator::visit: ParameterDeclaration: NULL argument" );
}

void 
JasminTranslator::visit( VariableDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "JasminTranslator::visit: VariableDeclaration: NULL argument" );

	aDeclNode->getInitLiteral()->accept( this );

 	if(((Variable*)(aDeclNode->getEntry()))->getVType() == AstNode::TINT)
	{
	
	emitInstruction("istore", ((Variable*)(aDeclNode->getEntry()))->getIndex());
	}
	else if(((Variable*)(aDeclNode->getEntry()))->getVType() == AstNode::TFLOAT)
	{
	
	emitInstruction("fstore", ((Variable*)(aDeclNode->getEntry()))->getIndex());
	}
}

void
JasminTranslator::visit( ClassDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "JasminTranslator::visit: ClassDeclaration: NULL argument" );
	std::stringstream ss;
	classEntry = new Class(aDeclNode->getName());
	code = fopen(std::string(std::string(aDeclNode->getName() +std::string(".jsm"))).c_str(),"w");
	
	fprintf(code,"\t;\t%s.jsm\n",aDeclNode->getName());
	fflush(code);
	
	emitDirective("bytecode", "50.0");
	ss.str("");
	
	emitDirective("source", std::string( std::string(aDeclNode->getName()) + std::string(".java")).c_str());
	emitDirective("class public", classEntry->getName());
	emitDirective("super", "java/lang/Object");
  // check if members are present
  bool first = false;
  bool field = false;
  std::vector<LiteralExpression *> literals;
	  std::vector<std::string> descriptors;
  if( aDeclNode->getMembers() != NULL ) {
    // print (visit) members
    for( int i = 0; i < aDeclNode->getMembers()->size(); i++ ) {
      // check if this member is really there
      if( aDeclNode->getMember( i ) == NULL )
	throw AstException( "JasminTranslator::visit: DCLASS: member is NULL" );
      // now, visit the next class member
	  
	  int size;
	  	  
	  if(aDeclNode->getMember(i)->getKind() == AstNode::DFIELD)
	  {
		field = true;
		if(((FieldDeclaration*)(aDeclNode->getMember(i)))->getInitLiteral() != NULL)
		{
			literals.push_back(((FieldDeclaration*)(aDeclNode->getMember(i)))->getInitLiteral());
			if(((FieldDeclaration*)(aDeclNode->getMember(i)))->getType() == AstNode::TINT)
			descriptors.push_back(std::string( std::string(classEntry->getName()) + std::string("/") + std::string(((FieldDeclaration*)(aDeclNode->getMember(i)))->getName()) +  std::string(" I"  )));
			else if(((FieldDeclaration*)(aDeclNode->getMember(i)))->getType() == AstNode::TFLOAT)
			descriptors.push_back(std::string( std::string(classEntry->getName()) + std::string("/") + std::string(((FieldDeclaration*)(aDeclNode->getMember(i)))->getName()) +  std::string(" F"  )));
		
		}
	  }
	  
	   if(  aDeclNode->getMember( i )->getKind() == AstNode::DMETHOD && !first)
	   {
	   	emitDirective("method public <init>()V","");
		emitDirective("limit stack 1", "");
		emitDirective ("limit locals 1","");
		emitInstruction("aload_0");
		emitInstruction("invokespecial", "java/lang/Object/<init>()V");
		emitInstruction("return");
		emitDirective("end method", "");
	   first = true;
	   }
      aDeclNode->getMember( i )->accept( this );
	}
	system(std::string(std::string("java -jar jasmin.jar ") + std::string(aDeclNode->getName()) + std::string(".jsm")).c_str());
	
  }
  if(field)
  {
   emitDirective("method static <clinit>()V","");
	   emitDirective("limit stack 1", "");
	   emitDirective("limit locals 0","");
		//literal initialization here
		
			for(int j = 0; j < literals.size(); j++)
		{
			literals[j]->accept(this);
			emitInstruction("putstatic", descriptors[j].c_str());
		
		}

  	emitInstruction("return");
		emitDirective("end method","");
		
	}
}


void
JasminTranslator::visit( LiteralExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
   throw AstException( "JasminTranslator::visit: NULL argument in LiteralExpression" );
   
	   switch(anExpNode->getType())
	   {
		case AstNode::TINT:
		if(atoi(anExpNode->getLiteral()) > 5)
		{
			emitInstruction("ldc",anExpNode->getLiteral());
		}
		else
		{
			emitInstruction(std::string(std::string("iconst_")+std::string(anExpNode->getLiteral())).c_str());
		}
			break;
		case AstNode::TFLOAT:
		
			emitInstruction("ldc",anExpNode->getLiteral());
			break;
		case AstNode::TSTRING:
			emitInstruction("ldc",anExpNode->getLiteral());
			break;
	   }
}

void
JasminTranslator::visit( ReferenceExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "JasminTranslator::visit: ReferenceExpression: NULL argument" );
	
  // print (visit) the index expression, if provided
  if( anExpNode->getExpression() != NULL ) {
    anExpNode->getExpression()->accept( this );
  }
  
  if(anExpNode->getEntry()->getEType() == Entry::VAR )
  {
		if(anExpNode->getType() == AstNode::TINT)
		{
			emitInstruction("iload", ((Variable*)(anExpNode->getEntry()))->getIndex() );
		}
		else if(anExpNode->getType() == AstNode::TFLOAT)
		{
			emitInstruction("fload", ((Variable*)(anExpNode->getEntry()))->getIndex() );
		}
  }
  else if( anExpNode->getEntry()->getEType() == Entry::PAR )
  {
	if(anExpNode->getType() == AstNode::TINT)
		{
			emitInstruction("iload", ((Parameter*)(anExpNode->getEntry()))->getIndex() );
		}
		else if(anExpNode->getType() == AstNode::TFLOAT)
		{
			emitInstruction("fload", ((Parameter*)(anExpNode->getEntry()))->getIndex() );
		}
	
	}
	else if(anExpNode->getEntry()->getEType() == Entry::FLD)
	{
		if(anExpNode->getType() == AstNode::TINT)
		{
		emitInstruction("getstatic", std::string( std::string(classEntry->getName()) + std::string("/") + std::string(anExpNode->getEntry()->getName())  + std::string(" ") + std::string("I")).c_str());
		}
			else if(anExpNode->getType() == AstNode::TFLOAT)
		{
			emitInstruction("getstatic", std::string( std::string(classEntry->getName()) + std::string("/") + std::string(anExpNode->getEntry()->getName())  + std::string(" ") + std::string("F")).c_str());
		}
	
	}
}

void JasminTranslator::visit( NewExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "JasminTranslator::visit: NewExpression: NULL argument" );

  if( anExpNode->getExpression() == NULL )
    throw AstException( "JasminTranslator::visit: NewExpression: size expression is NULL" );

	anExpNode->getExpression()->accept( this );
}

void JasminTranslator::visit( UnaryExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "JasminTranslator::visit: UnaryExpression: NULL argument" );

  if( anExpNode->getOperand() == NULL )
    throw AstException( "JasminTranslator.visit: UnaryExpression: operand is NULL" );

	anExpNode->getOperand()->accept( this );
	
	if(anExpNode->getOperator() ==  AstNode::SUBOP)
	{
		if(anExpNode->getOperand()->getType() == AstNode::TINT)
		{
			emitInstruction("ineg");
		}
		else if(anExpNode->getOperand()->getType() == AstNode::TFLOAT)
		{
			emitInstruction("fneg");
		}
	}
}

void JasminTranslator::visit( BinaryExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "JasminTranslator::visit: BinaryExpression: NULL argument" );

  if( anExpNode->getLeftOperand() == NULL )
    throw AstException( "JasminTranslator.visit: EBINARY left operand is NULL" );

  if( anExpNode->getRightOperand() == NULL )
    throw AstException( "JasminTranslator.visit: EBINARY right operand is NULL" );
	
  anExpNode->getLeftOperand()->accept( this );
  	if(anExpNode->getLeftOperand()->getType() == AstNode::TINT && anExpNode->getRightOperand()->getType() == AstNode::TFLOAT)
	{
			emitInstruction("i2f");
	}
  anExpNode->getRightOperand()->accept( this );
  if(anExpNode->getLeftOperand()->getType() == AstNode::TFLOAT && anExpNode->getRightOperand()->getType() == AstNode::TINT)
	{
	emitInstruction("i2f");
	}
	
	switch(anExpNode->getOperator())
	{
		case AstNode::MULOP:
	if(anExpNode->getLeftOperand()->getType() == AstNode::TFLOAT || anExpNode->getRightOperand()->getType() == AstNode::TFLOAT)
	{
		emitInstruction("fmul");
	}
	else
	{
		emitInstruction("imul");
	}	
		
		break;
		
		case AstNode::DIVOP:
	if(anExpNode->getLeftOperand()->getType() == AstNode::TFLOAT || anExpNode->getRightOperand()->getType() == AstNode::TFLOAT)
	{
		emitInstruction("fdiv");
	}
	else
	{
		emitInstruction("idiv");
	}	
		break;
		
		case AstNode::ADDOP:
	if(anExpNode->getLeftOperand()->getType() == AstNode::TFLOAT || anExpNode->getRightOperand()->getType() == AstNode::TFLOAT)
	{
		emitInstruction("fadd");
	}
	else
	{
		emitInstruction("iadd");
	}	
		break;
		
		case AstNode::SUBOP:
	if(anExpNode->getLeftOperand()->getType() == AstNode::TFLOAT || anExpNode->getRightOperand()->getType() == AstNode::TFLOAT)
	{
		emitInstruction("fsub");
	}
	else
	{
		emitInstruction("isub");
	}	
		break;
	
	}
}

void JasminTranslator::visit( CastExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "JasminTranslator::visit: CastExpression: NULL argument" );

  if( anExpNode->getOperand() == NULL )
    throw AstException( "JasminTranslator::visit: ECAST operand is NULL" );


  anExpNode->getOperand()->accept( this );
  
  if(anExpNode->getOperand()->getType() != anExpNode->getCastToType())
  {
	if(anExpNode->getCastToType() == AstNode::TFLOAT)
	{
		emitInstruction("i2f");
	}
	else if(anExpNode->getCastToType() == AstNode::TINT)
	{
		emitInstruction("f2i");
	}
  }
}

void JasminTranslator::visit( MethodCallExpression *anExpNode )
{
  // verify the integrity of the node
  if( anExpNode == NULL )
    throw AstException( "JasminTranslator::visit: NULL argument in MethodCallExpression" );
	std::string desc = std::string("");
	if(anExpNode->getClassName() == NULL)
	{
		desc = std::string( std::string(classEntry->getName()) + std::string("/") + std::string(anExpNode->getEntry()->getName()) + std::string("(") );
	}
	else
	{
		desc = std::string( std::string(anExpNode->getClassName()) + std::string("/") + std::string(anExpNode->getEntry()->getName()) + std::string("(") );
	}
	
  // check if any arguments have been provided
  if( anExpNode->getArguments() == NULL ) {
	desc += std::string(")");
  }
  else {
    // visit (print) method call arguments
    for( int i = 0; i < anExpNode->getArguments()->size(); i++ ) {
	anExpNode->getArgument( i )->accept( this );
	  switch(anExpNode->getArgument(i)->getType())
	  {
		case AstNode::TINT:
		desc+= std::string("I");
		break;
		case AstNode::TFLOAT:
		desc+=std::string("F");
		break;
		case AstNode::TSTRING:
		desc+=std::string("Ljava/lang/String;");
		break;
		case AstNode::TSTRINGA:
		desc+=std::string("[Ljava/lang/String;");
		break;
	  }
    }
	desc+=std::string(")");
  }
  
	switch(((Method*)(anExpNode->getEntry()))->getRetType())
	{
		case AstNode::TINT:
		desc += std::string("I");
		break;
		case AstNode::TFLOAT:
		desc += std::string("F");
		break;
		case AstNode::TVOID:
		desc += std::string("V");
		break;
	}
  emitInstruction("invokestatic", desc.c_str()  );
}

void JasminTranslator::visit( AssignStatement *anStmtNode )
{	
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: AssignStatement: NULL argument" );
      
  if( anStmtNode->getExpression() == NULL )
      throw AstException( "PrintStatementVisitor::visit: AssignStatement: NULL expression" );

	  // print (visit) the index expression, if given
  if( anStmtNode->getIndex() != NULL ) {
    anStmtNode->getIndex()->accept( this );
  }

  // print (visit) the right-hand side expression
  anStmtNode->getExpression()->accept( this );
 
  if(anStmtNode->getEntry() != NULL)
  {
	switch(anStmtNode->getEntry()->getEType())
	{
		
	case Entry::VAR:
		if(((Variable*)(anStmtNode->getEntry()))->getVType() == AstNode::TINT)
		{
			int x = ((Variable*)(anStmtNode->getEntry()))->getIndex();
			emitInstruction("istore", x);
		}
		else if(((Variable*)(anStmtNode->getEntry()))->getVType() == AstNode::TFLOAT)
		{
			emitInstruction("fstore",((Variable*)(anStmtNode->getEntry()))->getIndex());
		}
			break;
	case Entry::PAR:
		if(((Parameter*)(anStmtNode->getEntry()))->getPType() == AstNode::TINT)
		{
			emitInstruction("istore",((Parameter*)(anStmtNode->getEntry()))->getIndex());
		}
		else if(((Parameter*)(anStmtNode->getEntry()))->getPType() == AstNode::TFLOAT)
		{
			emitInstruction("fstore",((Parameter*)(anStmtNode->getEntry()))->getIndex());
		}
		break;
	case Entry::FLD:
		std::string field = std::string(std::string(classEntry->getName()) + std::string("/") +  std::string(anStmtNode->getEntry()->getName()));
		if(((Field*)(anStmtNode->getEntry()))->getFType() == AstNode::TINT)
		{
			field += std::string(" I");
			emitInstruction("putstatic", field.c_str());
		
		}
		else if(((Field*)(anStmtNode->getEntry()))->getFType() == AstNode::TFLOAT)
		{
			field += std::string(" F");
			emitInstruction("putstatic", field.c_str());
		}
		break;

	}
  }
}

void JasminTranslator::visit( WhileStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: WhileStatement: NULL argument" );

  if( anStmtNode->getExpression() == NULL )
      throw AstException( "JasminTranslator::visit: WhileStatement: expression is NULL" );

  if( anStmtNode->getBodyStatement() == NULL )
      throw AstException( "JasminTranslator::visit: WhileStatement: statement is NULL" );
	std::stringstream ss;
	ss << labelCount++;
	std::string againLabel = std::string("again") + ss.str();
	ss.str("");
	ss << labelCount++;
	std::string endLabel = std::string("whileEnd") + ss.str();
	
	emitLabel(againLabel.c_str());
	
  // print (visit) the control expression
  anStmtNode->getExpression()->accept( this );
  
  if(anStmtNode->getExpression()->getKind() == AstNode::EBINARY)
  {
	
	if(((BinaryExpression*)(anStmtNode->getExpression()))->getLeftOperand()->getType() == AstNode::TINT && ((BinaryExpression*)(anStmtNode->getExpression()))->getRightOperand()->getType() == AstNode::TINT)
	{
	
		switch(((BinaryExpression*)(anStmtNode->getExpression()))->getOperator())
		{
			case AstNode::EQOP:
				emitInstruction("if_icmpne", endLabel.c_str());
				break; 
		case AstNode::NEOP:
				emitInstruction("if_icmpeq", endLabel.c_str());
				break;
			case AstNode::LTOP:
				emitInstruction("if_icmpge", endLabel.c_str());
				break;
			case AstNode::GTOP:
				emitInstruction("if_icmple", endLabel.c_str());
				break;
			case AstNode::LEOP:
				emitInstruction("if_icmpgt", endLabel.c_str());
				break;
			case AstNode::GEOP:
				emitInstruction("if_icmplt", endLabel.c_str());
				break;
		}
	}
	else
	{
		emitInstruction("fcmpg");
		
		switch(((BinaryExpression*)(anStmtNode->getExpression()))->getOperator())
		{
		case AstNode::EQOP:		
			emitInstruction("ifne", endLabel.c_str());
			break; 
		case AstNode::NEOP:
			emitInstruction("ifeq", endLabel.c_str());
			break;
		case AstNode::LTOP:
			emitInstruction("ifge", endLabel.c_str());
			break;
		case AstNode::GTOP:		
			emitInstruction("ifle", endLabel.c_str());
			break;
		case AstNode::LEOP:	
			emitInstruction("ifgt", endLabel.c_str());
			break;
		case AstNode::GEOP:
			emitInstruction("iflt", endLabel.c_str());
			break;
		}
	  }
	}

  // now, print (visit) the while statement body
  anStmtNode->getBodyStatement()->accept( this );
  emitInstruction("goto", againLabel.c_str());
  emitLabel(endLabel.c_str());
}

void JasminTranslator::visit( ForStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: ForStatement: NULL argument" );

  if( anStmtNode->getInit() == NULL )
    throw AstException( "JasminTranslator::visit: ForStatement: initiatlization expression is NULL" );

  if( anStmtNode->getTerm() == NULL )
    throw AstException( "JasminTranslator::visit: ForStatement: termination expression is NULL" );

  if( anStmtNode->getUpd() == NULL )
    throw AstException( "JasminTranslator::visit: ForStatement: update expression is NULL" );

  if( anStmtNode->getBodyStatement() == NULL )
    throw AstException( "JasminTranslator::visit: ForStatement: statement is NULL" );
 
  // print (visit) the index expression, if given
  if( anStmtNode->getIndex() != NULL ) {
    anStmtNode->getIndex()->accept( this );
  }

  // print (visit) the initialization expression  
  anStmtNode->getInit()->accept( this );
 
  // print (visit) the termination expression 
  anStmtNode->getTerm()->accept( this );
  
  // print (visit) the update expression
  anStmtNode->getUpd()->accept( this );
  
  // now, visit the while statement body
  anStmtNode->getBodyStatement()->accept( this );
}

void JasminTranslator::visit( IfStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: IfStatement: NULL argument" );

  if( anStmtNode->getExpression() == NULL )
    throw AstException( "JasminTranslator::visit: IfStatement: expression is NULL" );

  if( anStmtNode->getThenStatement() == NULL )
    throw AstException( "JasminTranslator::visit: IfStatement: then statement is NULL" );

  // print (visit) the control expression  
  anStmtNode->getExpression()->accept( this );
  
  std::stringstream ss;
  ss << labelCount++;
  std::string elseLabel = std::string(std::string("else") + ss.str());
  ss.str("");
  
   ss << labelCount++;
  std::string endLabel = std::string(std::string("end")+ss.str());
  ss.str("");
  
  if(anStmtNode->getExpression()->getKind() == AstNode::EBINARY)
  {
	
	if(((BinaryExpression*)(anStmtNode->getExpression()))->getLeftOperand()->getType() == AstNode::TINT && ((BinaryExpression*)(anStmtNode->getExpression()))->getRightOperand()->getType() == AstNode::TINT)
	{
		switch(((BinaryExpression*)(anStmtNode->getExpression()))->getOperator())
		{
		case AstNode::EQOP:
			emitInstruction("if_icmpne", elseLabel.c_str());
			break; 
		case AstNode::NEOP:
			emitInstruction("if_icmpeq", elseLabel.c_str());
			break;
		case AstNode::LTOP:
			emitInstruction("if_icmpge", elseLabel.c_str());
			break;
		case AstNode::GTOP:	
			emitInstruction("if_icmple", elseLabel.c_str());
			break;
		case AstNode::LEOP:	
			emitInstruction("if_icmpgt", elseLabel.c_str());
			break;
		case AstNode::GEOP:
			emitInstruction("if_icmplt", elseLabel.c_str());
			break;
		}
	}
	else
	{
	emitInstruction("fcmpg");

		switch(((BinaryExpression*)(anStmtNode->getExpression()))->getOperator())
		{
		case AstNode::NEOP:	
			emitInstruction("ifeq", elseLabel.c_str());
			break; 
		case AstNode::EQOP:
			emitInstruction("ifne", elseLabel.c_str());
			break;
		case AstNode::LTOP:
			emitInstruction("ifge", elseLabel.c_str());
			break;
		case AstNode::GTOP:	
			emitInstruction("ifle", elseLabel.c_str());
			break;
		case AstNode::LEOP:	
			emitInstruction("ifgt", elseLabel.c_str());
			break;
		case AstNode::GEOP:
			emitInstruction("iflt", elseLabel.c_str());
			break;
		}
	}
  }
  // print (visit) the if's then statement
  anStmtNode->getThenStatement()->accept( this );
 
  emitInstruction("goto", endLabel.c_str());
	emitLabel(elseLabel.c_str());
  // print (visit) the if's else statement, if present
  if( anStmtNode->getElseStatement() != NULL ) {
    anStmtNode->getElseStatement()->accept( this );
  }

  emitLabel(endLabel.c_str());  
}

void JasminTranslator::visit( ReturnStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "TypeChecker::visit: NULL argument in ReturnStatement" );

  // print (visit) the return value expression
  if( anStmtNode->getExpression() != NULL ) {
    
    anStmtNode->getExpression()->accept( this );
    if(anStmtNode->getExpression()->getType() == AstNode::TINT)
	{
		emitInstruction("ireturn");
	}
	else if(anStmtNode->getExpression()->getType() == AstNode::TFLOAT)
	{
		emitInstruction("freturn");
	}
  }
  else
  {
	emitInstruction("return");
  }
}

void JasminTranslator::visit( BlockStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: BlockStatement: NULL argument" );

  if( anStmtNode->getStatements() == NULL )
    throw AstException( "JasminTranslator::visit: BlockStatement: statements are NULL" );


  // visit (print) all statements
  for( int i = 0; i < anStmtNode->getStatements()->size(); i++ ) {

    // check if this Statement is OK to visit
    if( anStmtNode->getStatements()->at( i ) == NULL )
      throw AstException( "JasminTranslator::visit: BlockStatement: operand statement at position %d is NULL" );

    // visit the block's next statement 
    anStmtNode->getStatements()->at( i )->accept( this ); 
  }
}

void
JasminTranslator::visit( MethodCallStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: MethodCallStatement: NULL argument" );

  if( anStmtNode->getExpression() == NULL )
    throw AstException( "PrintStatementVisitor::visit: MethodCallStatement: MethodCallExpression is NULL" );
	
  // print (visit) the MethodCallExpression (MethodCallStatement serves as a wrapper only)
  anStmtNode->getExpression()->accept( this ); 
}

void JasminTranslator::visit( EmptyStatement *anStmtNode )
{
  // verify the integrity of the node
  if( anStmtNode == NULL )
    throw AstException( "JasminTranslator::visit: EmptyStatement: NULL argument" );
}
