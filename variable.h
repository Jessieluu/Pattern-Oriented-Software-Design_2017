#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
#include "struct.h"
using std::string;

class Number;

class Variable : public Term{
public:
  Variable (string s): _symbol(s) {}

  string symbol() const{ return _symbol;}

  string value() const { return _value;}

  bool match(Variable var){
    if(_assignable || _value == var.value()){
        _value = var.value();
        _assignable = false;
        return true;
    }
    return false;
}

  bool match(Atom atom){
      if(_assignable || _value == atom.value()){
          _value = atom.value();
          _assignable = false;
          return true;
      }
      return false;
  }

  bool match(Number num){
    if(_assignable || _value == num.value()){
        _value = num.value();
        _assignable = false;
        return true;
    }
    return false;
  }

  bool match(Struct str){
    if(_assignable || _value == str.value()){
        _value = str.value();
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
