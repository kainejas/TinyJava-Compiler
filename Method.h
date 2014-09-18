#ifndef METHOD_H
#define METHOD_H
#include "Entry.h"
#include <vector>
#include <map>
#include <string.h>
class Method: public Entry {
public:
int index;
int count;
const char *method_def;
const char *method_call;
Method(const char*,int, std::vector<int>*,std::map<const char *, Entry*,Entry::comparestring>*);
Method(const char *, int);
int retType;
std::vector<int> *params;
std::map<const char*, Entry*,Entry::comparestring> *dictionary;
Entry::Etype getType();
std::vector<int>* getParams();
void addParam(int);
int getRetType();
std::map<const char*, Entry*,Entry::comparestring> *getDictionary();
int getIndex();
void setIndex(int);
int getCount();
void setCount(int);
const char * getMethodDesc();
const char * getMethodCallDesc();
void setMethodDesc(const char *);
void setMethodCallDesc(const char *);

};
#endif
