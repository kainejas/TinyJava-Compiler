#ifndef PARAMETER_H
#define PARAMETER_H
#include "Entry.h"
class Parameter: public Entry {
public:
Parameter(const char*,int);
int tp;
int index;
Etype getType();
int getPType();
void setPType(int);
const char*getName();
int getIndex();
void setIndex(int);
};
#endif
