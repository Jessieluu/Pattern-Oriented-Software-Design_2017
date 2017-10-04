#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "number.h"
#include "variable.h"
using std::string;

class Number;

class Atom {
public: Atom (string atom);

public: string symbol();

public: bool match(Number num);

public: bool match(Variable &var);

private: string const _symbol;
};  

#endif
