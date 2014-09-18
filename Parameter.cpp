#include "Parameter.h"
Parameter::Parameter(const char *nm, int type)
{
name = nm;
tp = type;
EType = PAR;
}

Entry::Etype Parameter::getType() 
{
return PAR;
}

int Parameter::getPType()
{
return tp;
}

const char *Parameter::getName()
{
return name;
}

void Parameter::setPType(int newTP)
{
tp = newTP;
}

int Parameter::getIndex()
{
return index;
}
void Parameter::setIndex(int n)
{
index = n;
}
