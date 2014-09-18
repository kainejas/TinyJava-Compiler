#include "Variable.h"

Variable::Variable(const char *nm, int type)
{
name = nm;
tp = type;
EType = VAR;
}


Entry::Etype Variable::getType()
{
return VAR;
}
int Variable::getVType()
{
return tp;
}

//Get variable name
const char *Variable::getName()
{
return name;
}

//Index number for intermediate code generation in Jasmin
int Variable::getIndex()
{
return index;
}
void Variable::setIndex(int n)
{
index = n;
}

