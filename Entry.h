#ifndef ENTRY_H
#define ENTRY_H
#include <functional>
#include <cstring>
class Entry {
public:

struct comparestring : public std::binary_function<const char *, const char *, bool> {

	bool operator() (const char* str1, const char* str2) const
	{	return std::strcmp(str1,str2) < 0; } 

};
enum Etype {
VAR,
MET,
CLS,
FLD,
PAR
};

Etype EType;
const char *name;
const char* getName() {return name;}
virtual Etype getType() =0;
Etype getEType(){
return EType;
}
};
#endif
