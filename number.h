#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
#include "variable.h"
using namespace std;
using std::string;

// class Atom;
// class Variable;

class Number : public Term{
public: 
    Number (double value) :_symbol (to_string(value)) {}

    string symbol() const{ return _symbol;}

    // string value() const { return _symbol;}

    // bool match (Number num){ return _symbol == num.symbol();}

    // bool match (Atom atom){ return false;}

    // bool match (Variable & var){ return var.match(this->symbol());}
    string _symbol;   

};

#endif
