#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
#include "struct.h"
using std::string;

class Variable : public Term{
public:
  Variable (string s): _symbol(s),_value(s) {}

  string symbol() const{ return _symbol;}

  string value() const { return _value;}

  bool match(Term & term){
    Variable * var = dynamic_cast<Variable *>(&term);
    // if(var){

    // }
    if(_assignable || _value == term.value()){
        _value = term.value();
        _assignable = false;
        return true;
    }
    return false;
}

// private:
  string _symbol;
  string _value;
  bool _assignable = true;  

};

#endif
