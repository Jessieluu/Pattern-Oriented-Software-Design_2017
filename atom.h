#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include <string>
#include <sstream>
#include <typeinfo>
#include "variable.h"
using std::string;

class Atom : public Term{
public:
  Atom(string s):Term(s) {}
  bool match(Term & a){
    if (typeid(a) ==  typeid(Variable))
      return a.match(*this);
    else
      return symbol() == a.symbol();
  }
};

#endif
