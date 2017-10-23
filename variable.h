#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <iostream>
#include <typeinfo>
#include "atom.h"
#include "list.h"
using std::string;

class List;
class Variable : public Term {
public:
  Variable(string s):Term(s), _inst(0){}
  string value() const {
    if (_inst) // is variable
      return _inst->value();      
    else 
      return Term::value();
  }
  bool match( Term & term ){
    List * li = dynamic_cast<List *>(&term);    
    if (this == &term) //variable match variable
      return true;
    if(!_inst){ ////variable match anything else
      if(typeid(term) == typeid(List)){
        return li->compareElementsifexit(this->symbol());  
      }
      _inst = &term ; // pointer to any else
      return true;
    }
    return _inst->match(term);
  }
private:
  Term * _inst;
};

#endif
