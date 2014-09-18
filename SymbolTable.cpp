#include "SymbolTable.h"
SymbolTable::SymbolTable()
{
//defaultPackage = NULL;
}


SymbolTable::SymbolTable(std::map<const char*,Entry*,Entry::comparestring> *defaultScope )
{
count = 0;
top=-1;
symtab = new std::vector<std::map<const char *, Entry*,Entry::comparestring>*>(3);
defaultPackage = new std::map<const char *, Entry*,Entry::comparestring>();
defaultPackage = defaultScope;
pushScope(defaultPackage);
}



Entry *  SymbolTable::simpleIOlookup(const char * className, const char* methodName){
				int index = top;
		while(top > -1)
		{
	
			if((*symtab->at(top))[methodName] != NULL)
			{
			if(top == 0 &&  (strcmp(className,"SimpleIO")) == 0 )
			{
					Entry *ent = (*symtab->at(top))[methodName];
					top = index;
					return ent;
			}
			else
				{
							top = index;
				return NULL;
				}
			}
		popScope();

		}
		top = index;
		return NULL;

}






Entry *  SymbolTable::lookup(const char * name){
		int index = top;
		while(top > -1)
		{
			
			if((*symtab->at(top))[name] != NULL)
			{
					Entry *ent = (*symtab->at(top))[name];
					top = index;
					return ent;
			}
		popScope();

		}

		top = index;
		return NULL;
		
}


void SymbolTable::pushScope(std::map<const char*, Entry*,Entry::comparestring>* scope){
	top++;
	symtab->at(top) = scope;
		
}
void SymbolTable::popScope(){
		
		top--;
}
bool SymbolTable::install(const char *name, Entry *ent) {
	// check if name is already in top most scope. if so, error
	//	other wise, install it into the top most scope.
	std::map<const char*, Entry*,Entry::comparestring>::iterator iter;			
	std::map<const char*,Entry*,Entry::comparestring> temp  = (*symtab->at(top));
	for(iter = temp.begin(); iter != temp.end(); iter++)
	{
		if(strcmp(iter->first,name) == 0)
		{	
		return false; //install failed
		}
	}

	(*symtab->at(top))[name] = ent;		
	return true;
}
