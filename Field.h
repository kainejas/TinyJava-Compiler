#ifndef FIELD_H
#define FIELD_H
#include "Entry.h"
class Field : public Entry {
public:
	Field(const char*,int);
	int tp;
	int index;
	const char* fieldspec;
	Etype getType();
	int getFType();
	int getKind();
	const char*getName();
	const char *getFieldSpec();
	void setFieldSpec(const char *);
	int getIndex();
void setIndex(int);
};
#endif
