#ifndef LIST_H
#define LIST_H

#include "atom.h"
#include <vector>
using std::vector;

class List : public Term {
public:
  List() : _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  Term * head() const;
  List * tail() const;
  string symbol() const{
    if(_elements.empty()){
      return "[]";
    }else{
      string ret = "[";
      std::vector<Term *>::const_iterator it = _elements.begin();
      for (; it != _elements.end()-1; ++it)
        ret += (*it)->symbol()+", ";
      ret  += (*it)->symbol()+"]";
      return ret;
    }
  }
  string value() const{
    if(_elements.empty()){
      return "[]";
    }else{
      string ret = "[";
      std::vector<Term *>::const_iterator it = _elements.begin();
      for (; it != _elements.end()-1; ++it)
        ret += (*it)->value()+", ";
      ret  += (*it)->value()+"]";
      return ret;
    }
  }
  // bool match(Term & term);
  // string compare;
  bool compareElementsifexit(string & compare){
    std::vector<Term *>::const_iterator it = _elements.begin();    
    for (; it != _elements.end()-1; ++it){
      if(compare == (*it)->value())
        return true;  
    }
    return false;      
  }
private:
  vector<Term *> _elements;


};

#endif
