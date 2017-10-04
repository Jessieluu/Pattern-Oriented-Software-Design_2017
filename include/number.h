#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
#include "variable.h"
using std::string;
class Atom;
class Variable;

class Number{
public: Number(int num);

public: string symbol();

public: string value();

public: bool match (Number num);

public: bool match (Atom atom);

public: bool match (Variable &var);

private: string const _symbol;   

};


#endif
