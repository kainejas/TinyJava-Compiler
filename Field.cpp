#include "Field.h"

Field::Field(const char* nm, int type) {
name = nm;
tp = type;
EType = FLD;
}

const char *Field::getFieldSpec()
{
return fieldspec;
}
void Field::setFieldSpec(const char *field)
{
	fieldspec = field;
}
const char *Field::getName()
{
return name;
}
Entry::Etype Field::getType()
{
return FLD;
}

int Field::getFType()
{
return tp;
}

int Field::getIndex()
{
return index;
}
void Field::setIndex(int n)
{
index = n;
}

