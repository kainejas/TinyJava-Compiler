%{

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
%} 
%token PUBLIC CLASS IDENT LBRACE RBRACE STATIC EQ SEMI LPAR RPAR VOID LBRACK RBRACK INT FLOAT COMMA IF ELSE WHILE RETURN PERIOD DOUBLEEQ NEQ LESS GREATER LEQ GEQ PLUS MINUS MULT DIVIDE ICONST FCONST SCONST
%union
{
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
}
%type <sval> ICONST
%type <sval> FCONST
%type <sval> SCONST
%type <sval> IDENT
%type <xval> literal
%type <xval> primary_expression
%type <xval> unary_expression
%type <xval> multiplicative_expression
%type <xval> additive_expression
%type <xval> relational_expression
%type <xval> expression
%type <tval> statement
%type <tval> return_statement
%type <tval> method_body
%type <xval> method_invocation
%type <bval> statement_list
%type <bval> method_statement_list
%type <aval> argument_list
%type <dval> local_decl
%type <dval> formal_param
%type <vdval> formal_param_list
//%type <vdval> member_decl_list
%type <vdval> local_decl_list
//%type <sval> qualified_name 
%type <ival> type
//%type <dval> class_decl

%%

tiny_java_program	:	class_decl
			;
class_decl		:	PUBLIC CLASS IDENT
				{
				classDecl = new ClassDeclaration( yylineno, $3 );
				}
				LBRACE member_decl_list RBRACE
			|		PUBLIC CLASS error LBRACE member_decl_list RBRACE
				{
				yyerror("Expected Identifier in class declaration");
				}
			|	PUBLIC error IDENT LBRACE member_decl_list RBRACE
				{
				yyerror("Expected 'class' in class declaration");
				}
			|	error CLASS IDENT LBRACE member_decl_list RBRACE
				{
				yyerror("Expected 'public' in class declaration");
				}
			|	error
				{
				yyerror("Error in class declaration");
				}
			
			;
member_decl_list	:	member_decl
			|	member_decl member_decl_list
			;
member_decl		:	field_decl
			|	method_decl
			;
field_decl		:	STATIC type IDENT EQ literal SEMI
				{
				classDecl->addMember( new FieldDeclaration( yylineno, $3, $2, (LiteralExpression *)$5 ) );
				}	
							|	STATIC type IDENT EQ literal error
				{
					yyerror("Expected ';' in field declaration");
				}
			|	STATIC type IDENT EQ error SEMI
				{
				yyerror("Expected literal in field declaration");
				}
			|	STATIC type IDENT error literal SEMI
				{
				yyerror("Expected '=' in field declaration");
				}
			|	STATIC type error EQ literal SEMI
				{
				yyerror("Expected identifier in field declaration");
				}
			|	STATIC error IDENT EQ literal SEMI
				{
				yyerror("Expected type in field declaration");
				}	
			;
method_decl		:	STATIC type IDENT LPAR
				{
				methodDecl = new MethodDeclaration( yylineno, $3, $2 );
				classDecl->addMember ( methodDecl );
				}
				formal_param_list RPAR 
				{
				methodDecl->setParameters( $6 );
				}
				LBRACE method_body RBRACE
			|	STATIC VOID IDENT LPAR 
				{
				methodDecl = new MethodDeclaration( yylineno, $3, AstNode::TVOID );
				classDecl->addMember( methodDecl );
				}
				formal_param_list RPAR 
				{
				methodDecl->setParameters( $6 );
				}
				LBRACE method_body RBRACE
			|	STATIC type IDENT LPAR RPAR LBRACE method_body RBRACE
				{
				methodDecl = new MethodDeclaration(yylineno, $3, $2);
				classDecl->addMember( methodDecl );
				}
			|	STATIC VOID IDENT LPAR RPAR LBRACE method_body RBRACE
				{
				methodDecl = new MethodDeclaration( yylineno, $3, AstNode::TVOID );
				classDecl->addMember( methodDecl );
				}
			|		/* main method */
	PUBLIC STATIC VOID IDENT
	LPAR IDENT LBRACK RBRACK IDENT RPAR 
	{
	  ParameterDeclaration *pd = NULL;
	  if( strcmp( $6, "String" ) == 0 ) {
		pd = new ParameterDeclaration( yylineno, $9, AstNode::TSTRINGA );
	  }
	  else {
	    pd = new ParameterDeclaration( yylineno, $9, 0 );
	  }
	  vector<Declaration*> *pv = new vector<Declaration*>();
	  pv->push_back( pd );
          methodDecl = new MethodDeclaration( yylineno, $4, AstNode::TVOID );
	  methodDecl->setParameters( pv );
	  methodDecl->setPublicMethod( true );
	 classDecl->addMember(methodDecl );
	}	  
	LBRACE  method_body  RBRACE		
			|	STATIC VOID IDENT error formal_param_list RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected '(' in method declaration");
				}
					|	STATIC VOID error LPAR formal_param_list RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected identifier in method declaration");
				}	
			|	STATIC type IDENT LPAR RPAR LBRACE method_body error
				{
					yyerror("Expected '}' in method declaration");
				}
				|	STATIC type error LPAR RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected Identifier in method declaration");
				}
			|	STATIC VOID IDENT LPAR RPAR LBRACE method_body error
				{
					yyerror("Expected '}' in method declaration");
				}
					|	STATIC VOID IDENT LPAR RPAR error method_body RBRACE
				{
				yyerror("Expected '{' in method declaration");
				}
			|	STATIC VOID IDENT LPAR error LBRACE method_body RBRACE
				{
				yyerror("Expected ')' in method declaration");
				}
			|	STATIC VOID IDENT error RPAR LBRACE method_body RBRACE
				{

				yyerror("Expected '(' in method declaration");
				}

			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK RBRACK IDENT RPAR error method_body RBRACE
				{
				yyerror("Expected '{' in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK RBRACK IDENT error LBRACE method_body RBRACE
				{
				yyerror("Expected ')' in method declaration");
				}
	
							|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK RBRACK error RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected identifier in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK error IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected ']' in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT error RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected '[' in method declaration");
				}
			| 	PUBLIC STATIC VOID IDENT LPAR error LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected identifier in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT error IDENT LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected '(' in method declaration");
				}
			|	PUBLIC STATIC error IDENT LPAR IDENT LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected 'void' in method declaration");
				}
			|	PUBLIC error VOID IDENT LPAR IDENT LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected 'static' in method declaration");
				}
/*
			|	STATIC type IDENT LPAR formal_param_list RPAR error method_body RBRACE
				{
					yyerror("Expected '{' in method declaration");
				}
			|	STATIC type IDENT LPAR formal_param_list error LBRACE method_body RBRACE
				{
					yyerror("Expected ')' in method declaration");
				}

			|	STATIC VOID IDENT LPAR formal_param_list RPAR error method_body RBRACE
				{
				yyerror("Expected '{' in method declaration");
				}
			|	STATIC VOID IDENT LPAR formal_param_list error LBRACE method_body RBRACE
				{
				yyerror("Expected ')' in method declaration");
				}
			|	STATIC VOID IDENT error formal_param_list RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected '(' in method declaration");
				}
			|	STATIC VOID error LPAR formal_param_list RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected identifier in method declaration");
				}	
			|	STATIC type IDENT LPAR RPAR LBRACE method_body error
				{
					yyerror("Expected '}' in method declaration");
				}
			|	STATIC type error LPAR RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected Identifier in method declaration");
				}
			|	STATIC VOID IDENT LPAR RPAR LBRACE method_body error
				{
					yyerror("Expected '}' in method declaration");
				}
			|	STATIC VOID IDENT LPAR RPAR error method_body RBRACE
				{
				yyerror("Expected '{' in method declaration");
				}
			|	STATIC VOID IDENT LPAR error LBRACE method_body RBRACE
				{
				yyerror("Expected ')' in method declaration");
				}
			|	STATIC VOID IDENT error RPAR LBRACE method_body RBRACE
				{

				yyerror("Expected '(' in method declaration");
				}

			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK RBRACK IDENT RPAR error method_body RBRACE
				{
				yyerror("Expected '{' in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK RBRACK IDENT error LBRACE method_body RBRACE
				{
				yyerror("Expected ')' in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK RBRACK error RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected identifier in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT LBRACK error IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected ']' in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT LPAR IDENT error RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected '[' in method declaration");
				}
			| 	PUBLIC STATIC VOID IDENT LPAR error LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected identifier in method declaration");
				}
			|	PUBLIC STATIC VOID IDENT error IDENT LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected '(' in method declaration");
				}
			|	PUBLIC STATIC error IDENT LPAR IDENT LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected 'void' in method declaration");
				}
			|	PUBLIC error VOID IDENT LPAR IDENT LBRACK RBRACK IDENT RPAR LBRACE method_body RBRACE
				{
				yyerror("Expected 'static' in method declaration");
				}
*/
		;
type		:	INT
			{
			$$ = AstNode::TINT;
			}
			|	FLOAT
			{
			$$ = AstNode::TFLOAT;
			}
			;
			
formal_param_list	:	formal_param
				{
				$$ = new vector<Declaration*>();
				$$->push_back( $1 );
				}
			|	formal_param COMMA formal_param_list
				{
				$$ = $3;
				$$->insert( $$->begin(), $1 );
				}
						|	formal_param COMMA error
				{
				yyerror("Error in formal parameter list");
				}
			;
formal_param		:	type IDENT
				{
				$$ = new ParameterDeclaration( yylineno, $2, $1 );
				}
					|	type error
				{
					yyerror("Expected identifier in formal parameter");
				}
			;
method_body		:	local_decl_list method_statement_list
				{
				methodDecl->setVariables( $1 );
				methodDecl->setBody( $2 );
				}
			;
local_decl_list		:	local_decl local_decl_list
				{
				$$ = $2;
				$$->push_back( $1 );
				}
			|	{
				$$ = new vector<Declaration*>();
				}
			;
local_decl		:	type IDENT EQ literal SEMI
				{
				$$ = new VariableDeclaration( yylineno, $2, $1,(LiteralExpression*) $4 );
				}
							|	type IDENT EQ literal error
				{
					yyerror("Expected ';' in local declaration");
				}
			|	type IDENT EQ error SEMI
				{
					yyerror("Expected literal in local declaration");
				}
			|	type IDENT error literal SEMI
				{
					yyerror("Expected '=' in lcoal declaration");
				}
			|	type error EQ literal SEMI
				{
					yyerror("Expected identifier in local declaration");
				}
			;
method_statement_list	:	statement method_statement_list
				{
				$$ = $2;
				$$->prependStatement( $1 );
				}
			|	return_statement
				{
				$$ = new BlockStatement(yylineno);
				$$->addStatement( $1 );
				}
			;
statement_list		: statement statement_list
			{
			$$ = $2;
			$$->prependStatement( $1 );
			}
					|	statement error
				{
				yyerror("Error in statement list");
				}
			|/*empty*/
			{
			$$ = new BlockStatement( yylineno );
			}
			;
statement		:	IDENT EQ expression SEMI
				{
				$$ = new AssignStatement( yylineno, $1, $3 );
				}
			|	IF LPAR expression RPAR statement
				{
				$$ = new IfStatement( yylineno, $3, $5, NULL );
				}
			|	IF LPAR expression RPAR statement ELSE statement
				{
				$$ = new IfStatement( yylineno, $3, $5, $7 );
				}
			|	WHILE LPAR expression RPAR statement
				{
				$$ = new WhileStatement( yylineno, $3, $5 );
				}
			|	method_invocation SEMI
				{
				$$ = new MethodCallStatement( yylineno, $1 );
				}
					|	method_invocation error
				{
					yyerror("Expected ';' in statement");
				}
			|	LBRACE statement_list RBRACE
				{
				$$ = $2;
				}
			|	SEMI
				{
				$$ = new EmptyStatement( yylineno );
				}
					|	IDENT EQ expression error
				{
					yyerror("Expected ';' in statement");
				}
			|	IDENT EQ error SEMI
				{
				yyerror("Expected expression after '='");
				}
			|	IDENT error expression SEMI
				{
				yyerror("Expected '=' in statement");
				}
			|	IF LPAR expression RPAR error
				{
				yyerror("Expected statement in IF");
				}
			|	IF LPAR expression error statement
				{
				yyerror("Expected ')' in IF");
				}
			|	IF LPAR error RPAR statement
				{
				yyerror("Expected expression in IF");
				}
			|	IF error expression RPAR statement
				{
				yyerror("Expected '(' in IF statement");
				}
			|	error LPAR expression RPAR statement
				{
				yyerror("Expected 'while' or 'if'");
				}
			|	WHILE LPAR expression RPAR error
				{
				yyerror("Expected statement within while loop");
				}
			|	WHILE LPAR expression error statement
				{
				yyerror("Expected ')' in while loop");
				}
			|	WHILE LPAR error RPAR statement
				{
				yyerror("Expected expression within parentheses of while loop");
				}
			|	WHILE error expression RPAR statement
				{
				yyerror("Expected '(' after while");

				}			
				
				
			;
return_statement	:	RETURN expression SEMI
			{
			$$ = new ReturnStatement( yylineno, NULL , $2 );
			}
			|	RETURN SEMI
			{
			$$ = new ReturnStatement( yylineno, NULL, NULL );
			}
						|	RETURN expression error
				{
					yyerror("Expected ';' in return statement");
				}
			|	RETURN error SEMI
				{
				yyerror("Expected expression in return statement");
				}
			|	RETURN error
				{
					yyerror("Expected ';' in return statement");
				}
			;
method_invocation	:	IDENT LPAR argument_list RPAR
			{
			$$ = new MethodCallExpression(yylineno, NULL, $1, $3 );
			}
			|	IDENT LPAR RPAR
			{
			$$ = new MethodCallExpression(yylineno, NULL, $1, (vector<Expression*> *)NULL );
			}
			| IDENT PERIOD IDENT LPAR argument_list RPAR
			{
			$$ = new MethodCallExpression(yylineno, $1, $3, $5 );
			}
			| IDENT PERIOD IDENT LPAR RPAR
			{
			$$ = new MethodCallExpression(yylineno, $1, $3, (vector<Expression*> *) NULL) ;
			}
			
			;
/*
qualified_name		:	IDENT PERIOD IDENT
			|	IDENT
			|	IDENT PERIOD error
				{

				yyerror("Expected Identifier in qualified name");
				}
			
			;
	*/		
argument_list		:	expression
				{
				$$ = new vector<Expression *>();
				$$->push_back( $1 );
				}
			|	expression COMMA argument_list
				{
				$$ = $3;
				$$->push_back( $1 );
				}
				
			;
expression		:	relational_expression
			{
			$$ = $1;
			}
			|	relational_expression DOUBLEEQ relational_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::EQOP, $1, $3 );
			}
			|	relational_expression NEQ relational_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::NEOP, $1, $3 );
			}
						|	relational_expression DOUBLEEQ error
				{
				yyerror("Expected expression after '=='");
				}
			|	relational_expression NEQ error
				{
				yyerror("Expected expression after '!='");
				}
			;
relational_expression	:	additive_expression
			{
			$$ = $1;
			}
			|	additive_expression LESS additive_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::LTOP, $1, $3 );
			}
			|	additive_expression GREATER additive_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::GTOP, $1, $3 );
			}
			|	additive_expression LEQ additive_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::LEOP, $1, $3 );
			}
			|	additive_expression GEQ additive_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::GEOP, $1, $3 );
			}
						|	additive_expression LESS error
				{

				yyerror("Expected expression after '<'");
				}
			|	additive_expression GREATER error
				{
				yyerror("Expected expression after '>'");
				}
			|	additive_expression LEQ error
				{
				yyerror("Expected expression after '<='");
				}
			|	additive_expression GEQ error
				{
				yyerror("Expected expression after '>='");
				}
			;
additive_expression	:	multiplicative_expression
			{
			$$ = $1;
			}
			|	additive_expression PLUS multiplicative_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::ADDOP, $1, $3 );
			}
			|	additive_expression MINUS multiplicative_expression
			{
			$$ = new BinaryExpression(yylineno, AstNode::SUBOP, $1, $3 );
			}
						|	additive_expression PLUS error
				{
				yyerror("Expected multiplicative expression after '+'");
				}
			|	additive_expression MINUS error
				{
				yyerror("Expected multiplicative expression after '-'");
				}
			;
multiplicative_expression :	unary_expression
			{
			$$ = $1;
			}
			|	multiplicative_expression MULT unary_expression
			{
			$$ = new BinaryExpression(yylineno,AstNode::MULOP ,$1, $3 ); 
			}
			|	multiplicative_expression DIVIDE unary_expression
			{
			$$ = new BinaryExpression(yylineno,AstNode::DIVOP, $1, $3 );
			}
						|	multiplicative_expression MULT error
				{
				yyerror("Expected unary expression in multiplicative expression");
				}
			|	multiplicative_expression DIVIDE error
				{

				yyerror("Expected unary expression in multiplicative expression");
				}
			;
unary_expression	:	primary_expression
			{
			$$ = $1;
			}
			|	PLUS unary_expression
			{
			$$ = new UnaryExpression(yylineno,AstNode::ADDOP,$2 );
			}
			|	MINUS unary_expression
			{
			$$ = new UnaryExpression(yylineno, AstNode::SUBOP, $2 );
			}
			|	LPAR type RPAR unary_expression
			{
			$$ = new CastExpression(yylineno,$2,$4);
			}
						|	LPAR type RPAR error
				{
					yyerror("Expected unary expression in unary expression");

				}
			|	LPAR type error unary_expression
				{

				yyerror("Expected ')' in unary expression");
				}
			|	PLUS error
				{
				yyerror("Expected unary expression after '+'");
				}
			|	MINUS error
				{
				yyerror("Expected unary expression after '-'");
				}
			;
primary_expression	:	literal
			{
			$$ = $1;
			}
			| IDENT
			{
			$$ = new ReferenceExpression(yylineno,$1);
			}
			|	method_invocation
			{
			$$ = $1;
			}
			|	LPAR expression RPAR
			{
			$$ = $2;
			}
			| LPAR error RPAR
				{
					yyerror("Expected expression in primary expression");
				}
	
			|	LPAR expression error
				{
					yyerror("Expected ')' in primary expression");
				}
			;
literal	 	:	ICONST
			{
			$$ = new LiteralExpression(yylineno, $1, AstNode::TINT);
			}
			|	FCONST
			{
			$$ = new LiteralExpression(yylineno, $1, AstNode::TFLOAT);
			}
			|	SCONST
			{
			$$ = new LiteralExpression(yylineno, $1, AstNode::TSTRING);
			}
			;		
%%
int yyerror( const char *msg) {
cerr << "Line: " << yylineno << ": " << msg << endl; cerr.flush();
}
