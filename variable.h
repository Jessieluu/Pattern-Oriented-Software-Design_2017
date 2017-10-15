#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
#include "struct.h"
using std::string;

class Atom;
class Number;

class Variable : public Term{
public:
  Variable (string s): _value(s) {}

  string symbol() const{ return _symbol;}

  string value() const { return _value;}

  bool match(Variable var){
    if(_assignable || _value == var.symbol()){
        _value = var.symbol();
        _assignable = false;
        return true;
    }
    return false;
}

  bool match(Atom atom){
      if(_assignable || _value == atom.symbol()){
          _value = atom.symbol();
          _assignable = false;
          return true;
      }
      return false;
  }

  bool match(Number num){
      if(_assignable || _value == num.symbol()){
          _value = num.symbol();
          _assignable = false;
          return true;
      }
      return false;
  }

  bool match(Struct str){
    if(_assignable || _value == str.symbol()){
        _value = str.symbol();
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
