#include "Class.h"
#include <iostream>
Class::Class(const char* nm)
{
name = nm;
dictionary = new std::map<const char*,Entry*,Entry::comparestring>();
EType = CLS;
}

Entry::Etype Class::getType()
{
return CLS;
}
void Class::addField(Field *fld)
{
fv.push_back(fld);
}
void Class::addMethod(Method * mtd)
{
mv.push_back(mtd);
//dictionary.insert(std::pair<const char*,Entry*>(name,mtd));
}
std::map<const char*, Entry*,Entry::comparestring> *Class::getDictionary()
{
return dictionary;
}
const char *Class::getName()
{
return name;
}
std::vector<Method*> Class::getMethods()
{
return mv;
}
