#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "Entry.h"
#include "Method.h"
#include "Variable.h"
#include "Parameter.h"
#include "Field.h"
#include "Class.h"
#include <map>
#include <vector>
#include <string.h>
#include <iostream>
class SymbolTable{
public:
int count;
SymbolTable();
SymbolTable(std::map<const char*, Entry*,Entry::comparestring>*  );
std::map<const char*,Entry*,Entry::comparestring> *defaultPackage;
std::vector<std::map<const char*,Entry*,Entry::comparestring>* >* symtab; 
int top; //Index pointing to top of the stack
Entry * lookup(const char *); //Lookup entry by name
void pushScope(std::map<const char*,Entry*,Entry::comparestring>* ); //Push scope on top
void popScope(); //Pop the top scope off 
bool install(const char*, Entry*); //Install an entry to the symbol table
Entry *  simpleIOlookup(const char * className, const char* methodName); //Look up for when there is a class name

};
#endif
