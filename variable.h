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

  bool match(Term& var){
    if(_assignable || _value == var.value()){
        _value = var.value();
        _assignable = false;
        return true;
    }
    return value() == var.value();
}

// private:
  string _symbol;
  string _value;
  bool _assignable = true;  

};

#endif
