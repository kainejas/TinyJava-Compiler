#ifndef VARIABLE_H
#define VARIABE_H
#include "Entry.h"
#include <string.h>

class Variable: public Entry {
public:
	Variable(const char*,int);
	int tp; //variable's type (int,float)
	int index;
	Etype getType(); //Entry type (VAR)
	int getVType(); //int Entry type
	const char*getName();
	int getIndex();
void setIndex(int);
};
#endif
