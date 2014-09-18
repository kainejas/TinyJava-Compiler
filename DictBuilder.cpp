// Gnu Emacs C++ mode:  -*- C++ -*-
#include "DictBuilder.h"

using namespace std;


SymbolTable *DictBuilder::getSymbolTable()
{
return symtab;
}
void 
DictBuilder::visit( MethodDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "DictBuilder::visit: MethodDeclaration: NULL argument" );

  if( aDeclNode->getBody() == NULL )
    throw AstException( "DictBuilder::visit: MethodDeclaration: body is NULL" );
  
		if(!symtab->install(aDeclNode->getName(),new Method(aDeclNode->getName(),aDeclNode->getRetType())))
			{
		
			std::cout << "Error " << aDeclNode->getLineNo() << ":  " << aDeclNode->getName() << " already declared in this scope" << std::endl;
			err = true;
	//		return;
			}
			
			int count = 0;
	aDeclNode->setEntry(symtab->lookup(aDeclNode->getName()));	
	symtab->pushScope(((Method*)(symtab->lookup(aDeclNode->getName())))->getDictionary());
	std::string tempCallDesc = std::string(classEntry->getName());
	std::string tempDesc = std::string(aDeclNode->getName()) + std::string("/");
	tempDesc += std::string("(");
	std::vector<int> *tempP = new std::vector<int>(aDeclNode->getParameters()->size());
  // print (visit) the parameters
  if( aDeclNode->getParameters() != NULL ) {
    for( int i = 0; i < aDeclNode->getParameters()->size(); i++ ) {
		count++;
      aDeclNode->getParameters()->at( i )->accept( this );
	  Method * met = ((Method*)(aDeclNode->getEntry()));
	
		((Parameter*)(((ParameterDeclaration*)(aDeclNode->getParameters()->at(i)))->getEntry()))->setIndex( met->getIndex() );
		

	((Method*)((aDeclNode->getEntry())))->addParam(((ParameterDeclaration*)(aDeclNode->getParameters()->at(i)))->getType()); //index++
		switch(((int)(((ParameterDeclaration*)(aDeclNode->getParameters()->at(i)))->getType())))
		{
			case AstNode::TINT:
			tempDesc += std::string("I");
			break;
				
			case AstNode::TFLOAT:
			tempDesc += std::string("F");
			break;
			
			case AstNode::TSTRINGA:
			tempDesc += std::string("[Ljava/lang/String;");
			break;
			default:			
			break;
		}
		
    }
	
	tempDesc += std::string(")");	
	switch(((Method*)(aDeclNode->getEntry()))->getRetType())
	{
		case AstNode::TINT:
		tempDesc+= std::string("I");
		break;
		case AstNode::TFLOAT:
		tempDesc+= std::string("F");
		break;
		case AstNode::TVOID:
		tempDesc+= std::string("V");
		break;
		default:
		break;
		
	}
	tempCallDesc += tempDesc;
	((Method*)(aDeclNode->getEntry()))->setMethodCallDesc(tempCallDesc.c_str());
	((Method*)(aDeclNode->getEntry()))->setMethodDesc(tempDesc.c_str());
 }

	
  // print (visit) the variables
  if( aDeclNode->getVariables() != NULL ) {
    for( int i = 0; i < aDeclNode->getVariables()->size(); i++ ) {
	count++;
      aDeclNode->getVariables()->at( i )->accept( this );
		((Variable*)(((VariableDeclaration*)(aDeclNode->getVariables()->at(i)))->getEntry()))->setIndex( ((Method*)(aDeclNode->getEntry()))->getIndex() );
		((Method*)(aDeclNode->getEntry()))->setIndex( ((Method*)(aDeclNode->getEntry()))->getIndex() + 1);


    }
}
((Method*)(aDeclNode->getEntry()))->setCount(count);
symtab->popScope();
}

void
DictBuilder::visit( FieldDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "DictBuilder::visit: FieldDeclaration: NULL argument" );

	
	if(!symtab->install(aDeclNode->getName(),new Field(aDeclNode->getName(),aDeclNode->getType())))
	{
		std::cout << "Error " << aDeclNode->getLineNo() << ":  " << aDeclNode->getName() << " already declared in this scope" << std::endl;
		err = true;
	//		return;
	}
		
	aDeclNode->setEntry(symtab->lookup(aDeclNode->getName()));
	((Field*)(aDeclNode->getEntry()))->setFieldSpec(std::string( std::string(classEntry->getName()) + std::string("/") + std::string(aDeclNode->getName())).c_str());
	classEntry->addField(((Field*)(aDeclNode->getEntry())));

}

void
DictBuilder::visit( ParameterDeclaration *aDeclNode )
{
  // verify the integrity of the nodeja
  if( aDeclNode == NULL )
    throw AstException( "DictBuilder::visit: ParameterDeclaration: NULL argument" );

	
	if(!symtab->install(aDeclNode->getName(),new Parameter(aDeclNode->getName(),aDeclNode->getType())))
	{
		std::cout << "Error " << aDeclNode->getLineNo() << ":  " << aDeclNode->getName() << " already declared in this scope" << std::endl;
		err = true;
	}
	aDeclNode->setEntry(symtab->lookup(aDeclNode->getName()));
 
}

void 
DictBuilder::visit( VariableDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "DictBuilder::visit: VariableDeclaration: NULL argument" );

  
	
	if(!symtab->install(aDeclNode->getName(),new Variable(aDeclNode->getName(),aDeclNode->getType())))
	{
		std::cout << "Error " << aDeclNode->getLineNo() << ":  " << aDeclNode->getName() << " already declared in this scope" << std::endl;
		err = true;
	
	}
	aDeclNode->setEntry((symtab->lookup(aDeclNode->getName())));
 
}

void
DictBuilder::visit( ClassDeclaration *aDeclNode )
{
  // verify the integrity of the node
  if( aDeclNode == NULL )
    throw AstException( "DictBuilder::visit: ClassDeclaration: NULL argument" );

	
	//instantiate class entry
	classEntry = new Class(aDeclNode->getName());
	Class *  sio = new Class("SimpleIO");	
	Method *  m1 = new Method("readInt",AstNode::TINT);
	Method *  m2 = new Method("readFloat",AstNode::TFLOAT);
	Method *  m3 = new Method("println",AstNode::TVOID);
	Method *  m4 = new Method("printInt",AstNode::TVOID);
	m4->addParam(AstNode::TINT);
	Method *  m5 = new Method("printFloat",AstNode::TVOID);
	m5->addParam(AstNode::TFLOAT);
	Method *  m6 = new Method("printString",AstNode::TVOID);
	m6->addParam(AstNode::TSTRING);	
	sio->addMethod(m1);
	sio->addMethod(m2);
	sio->addMethod(m3);
	sio->addMethod(m4);
	sio->addMethod(m5);
	sio->addMethod(m6);
	std::map<const char*,Entry*, Entry::comparestring> *simpleIO = new std::map<const char *, Entry *, Entry::comparestring>();
	simpleIO->insert(std::pair<const char*,Entry*>(sio->getName(),sio));
	simpleIO->insert(std::pair<const char*,Entry*>("readInt",m1));
	simpleIO->insert(std::pair<const char*,Entry*>("readFloat",m2));
	simpleIO->insert(std::pair<const char*,Entry*>("println",m3));
	simpleIO->insert(std::pair<const char*,Entry*>("printInt",m4));
	simpleIO->insert(std::pair<const char*,Entry*>("printFloat",m5));
	simpleIO->insert(std::pair<const char*,Entry*>("printString",m6));
	symtab = new SymbolTable(simpleIO);
	//symtab->pushScope((classEntry->getDictionary()));
	if(!symtab->install(classEntry->getName(), classEntry))
	{
		std::cout << "Error " << aDeclNode->getLineNo() << ":  " << aDeclNode->getName() << " already declared in this scope" << std::endl;
		err = true;
	}else
	{
	symtab->pushScope((classEntry->getDictionary()));
	}

	if( aDeclNode->getMembers() == NULL ) {;
    cout << "No members" << endl;
    cout.flush();
  }
  else {
    // print (visit) members
    for( int i = 0; i < aDeclNode->getMembers()->size(); i++ ) {
      // check if this member is really there
      if( aDeclNode->getMember( i ) == NULL )
	throw AstException( "DictBuilder::visit: DCLASS: member is NULL" );
      // now, visit the next class member

     aDeclNode->getMember( i )->accept( this );
	}
	//symtab->popScope();
	
  }
}

void DictBuilder::visit( LiteralExpression *anExpNode ){}

void DictBuilder::visit( ReferenceExpression *anExpNode ){}

void DictBuilder::visit( NewExpression *anExpNode ){}

void DictBuilder::visit( UnaryExpression *anExpNode ){}

void DictBuilder::visit( BinaryExpression *anExpNode ){}

void DictBuilder::visit( CastExpression *anExpNode ){}

void DictBuilder::visit( MethodCallExpression *anExpNode ){}

void DictBuilder::visit( AssignStatement *anStmtNode ){}

void DictBuilder::visit( WhileStatement *anStmtNode ){}

void DictBuilder::visit( ForStatement *anStmtNode ){}

void DictBuilder::visit( IfStatement *anStmtNode ){}

void DictBuilder::visit( ReturnStatement *anStmtNode ){}

void DictBuilder::visit( BlockStatement *anStmtNode ){}

void DictBuilder::visit( MethodCallStatement *anStmtNode ){}

void DictBuilder::visit( EmptyStatement *anStmtNode ){}