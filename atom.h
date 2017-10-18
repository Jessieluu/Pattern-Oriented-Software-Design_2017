#pragma once
#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
#include "variable.h"
using std::string;

class Atom : public Term{
public:
  Atom (string s):_symbol(s) {}

  string symbol() const{
    return _symbol;
  }
  
  string value() const { 
    return _symbol; 
  }

  bool match(Term & term) {
    return symbol() == term.symbol();
  }

  bool match (Variable & var){ return var.match(*this);}

  string _symbol;
};


#endif
