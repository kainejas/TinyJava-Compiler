#include "Method.h"
#include <iostream>
Method::Method(const char *nm, int type, std::vector<int>* prms,std::map<const char*, Entry *,Entry::comparestring>* dict)
{
method_def = "";
method_call = "";
index =0;
count = 0;
name = nm;
params = new std::vector<int>();
//addParams(prms);
retType = type;
dictionary = new std::map<const char *, Entry *,Entry::comparestring>();
dictionary = dict;
EType = MET;
}

Method::Method(const char *nm, int type)
{
method_def = "";
method_call = "";
index = 0;
count = 0;
name = nm;
params = new std::vector<int>();
dictionary = new std::map<const char *, Entry *, Entry::comparestring>(); 
retType = type;
EType = MET;
}

int Method::getCount()
{
return count;
}

void Method::setCount(int n)
{
count = n;
}

void Method::addParam(int p)
{
params->push_back( p);
index++;
}

std::vector<int> *Method::getParams()
{
return params;
}

int Method::getRetType()
{
return retType;
}

Entry::Etype Method::getType()
{
return Entry::MET;
}

std::map<const char *, Entry *, Entry::comparestring> *Method::getDictionary()
{
return dictionary;
}

int Method::getIndex()
{
return index;
}

void Method::setIndex(int n)
{
index = n;
}
const char * Method::getMethodDesc()
{
return method_def;
}
const char * Method::getMethodCallDesc()
{
return method_call;
}
void Method::setMethodDesc(const char * methodDesc)
{
method_def = methodDesc;
}

void Method::setMethodCallDesc(const char * methodDesc)
{
method_call = methodDesc;
}