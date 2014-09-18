##
## Version:     1
##
## Date:        02/22/2012
##
## Abstract Syntax Tree example
##
## Makefile
##
## K.J. Kochut
##


CXX		= g++
CPPFLAGS	= -I/home/profs/kochut/csx570/ast
CXXFLAGS	= -g #-DYYDEBUG 
LDFLAGS		= -L/home/profs/kochut/csx570/ast
LDLIBS		= -lAst -lfl
YACC            = bison -y
LEX             = flex


SRCS            = main-tree.cpp lex.yy.c y.tab.c Variable.cpp Parameter.cpp Method.cpp Field.cpp Class.cpp SymbolTable.cpp DictBuilder.cpp TypeChecker.cpp JasminTranslator.cpp

HDRS            =  y.tab.h Ast.h Entry.h Variable.h Parameter.h Method.h Field.hClass.h SymbolTable.h DictBuilder.h TypeChecker.h JasminTranslator.h

OBJS	        = main-tree.o y.tab.o lex.yy.o Variable.o Parameter.o Method.o Field.o Class.o SymbolTable.o DictBuilder.o TypeChecker.o JasminTranslator.o



# compile rules
#
COMPILE.cpp     = $(CXX) $(CPPFLAGS) $(CXXFLAGS)  -c
LINK.cpp        = $(CXX) $(CXXFLAGS) $(LDFLAGS)

.SUFFIXES: .cpp

.cpp.o:
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

all: tjc

tjc: Makefile $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

# non-standard target dependencies
y.tab.o: Makefile y.tab.c /home/profs/kochut/csx570/ast/Ast.h
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) y.tab.c

lex.yy.o: Makefile lex.yy.c y.tab.h /home/profs/kochut/csx570/ast/Ast.h
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) lex.yy.c
JasminTranslator.o: Makefile JasminTranslator.h JasminTranslator.cpp /home/profs/kochut/csx570/ast/Ast.h
TypeChecker.o: Makefile TypeChecker.h TypeChecker.cpp /home/profs/kochut/csx570/ast/Ast.h
	$(CXX) -c $(CPPFLAGS) TypeChecker.cpp
DictBuilder.o: Makefile DictBuilder.h DictBuilder.cpp /home/profs/kochut/csx570/ast/Ast.h
	$(CXX) -c $(CPPFLAGS) DictBuilder.cpp
SymbolTable.o: Makefile SymbolTable.h SymbolTable.cpp
	$(CXX) -c SymbolTable.cpp
Class.o: Makefile Class.h Class.cpp
	$(CXX) -c Class.cpp
Field.o: Makefile Field.h Field.cpp
	$(CXX) -c Field.cpp
Method.o: Makefile Method.h Method.cpp
	$(CXX) -c Method.cpp
Parameter.o: Makefile Parameter.h Parameter.cpp
	$(CXX) -c Parameter.cpp
Variable.o: Makefile Variable.h Variable.cpp
	$(CXX) -c Variable.cpp
y.tab.c y.tab.h: Makefile tjc.y
	$(YACC) -dv tjc.y

lex.yy.c: Makefile spec.l
	$(LEX) spec.l

#clean targets
clean:
	/bin/rm -f *.o

realclean: clean
	/bin/rm -f arith

#################################################################
#################################################################
## Dependencies
##
main-tree.o: main-tree.cpp /home/profs/kochut/csx570/ast

