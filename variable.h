#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include "list.h"

#include <typeinfo>
#include <string>
using std::string;

class Variable : public Term {
public:
  Variable(string s):Term(s), _inst(0){}
  string value() const {
    if (_inst)
      return _inst->value();
    else
      return Term::value();
  }
  bool match( Term & term ){
    List * li = dynamic_cast<List *>(&term);        
    if (this == &term)
      return true;
    if(!_inst){
      if(typeid(term) == typeid(List)){
        return li->compareElementsifexit(this->symbol());  
      }
      _inst = &term ;
      return true;
    }
    return _inst->match(term);
  }
private:
  Term * _inst;
};

#endif
