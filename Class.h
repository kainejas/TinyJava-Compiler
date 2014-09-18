#ifndef CLASS_H
#define CLASS_H
#include "Field.h"
#include "Method.h"

#include <vector>
#include <map>

class Class: public Entry {
public:
Class(const char *);
std::vector<Field *> fv;
std::vector<Method *> mv;
std::map<const char *, Entry*,Entry::comparestring> *dictionary;
Entry::Etype getType();
void addMethod( Method * const);
void addField(Field *);
std::map<const char *,Entry*,Entry::comparestring> *getDictionary();
const char *getName();
std::vector<Method *> getMethods();
};
#endif
