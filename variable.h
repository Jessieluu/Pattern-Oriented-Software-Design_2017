#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"

using std::string;

class Variable : public Term{
public:
  Variable (string s) {
    _symbol = s;
    _value = s;
  }

  string symbol() const{ return _symbol;}

  string value() const { return _value;}

  bool match(Term & term){
    bool re = _assignable;
    Variable * var = dynamic_cast<Variable *>(&term);
    if(_assignable){
      if(var){
        if(var->_assignable)
          var->_value = _value;
        else
          _value = var->_value; 
      }else{ //非變數
        * ptr = term.value();
        _assignable = false;
      }
    }else{
      return * ptr == term.value();
    }
    return re;
}

// private:
  string _symbol;
  string _value;
  string * ptr;
  bool _assignable = true;  

};

#endif