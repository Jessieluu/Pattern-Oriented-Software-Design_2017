#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
using std::string;

class Atom;
class Number;

class Variable{
public: Variable(string s);

public: string symbol();

public: bool match(Atom atom);

public: bool match(Number num);

private: string const _symbol;

private: string _value;

private: bool _assignable = true;

};

#endif
