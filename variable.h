#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"
#include "struct.h"
using std::string;
using std::vector;

class Variable : public Term{
public:
  Variable (string s) {
    _symbol = s;
    _value = _symbol;
  }

  string symbol() const{ return _symbol;}

  string value() const { 	if ( _save != 0)
		return _save ->value();
	else
		return _value;}

  bool match(Term & term){
    bool re = _assignable;
    Variable * var = dynamic_cast<Variable *>(&term);
    Struct * ps = dynamic_cast < Struct * > ( &term );
    if(_symbol == term.symbol()){
      return true;
    }      

    if ( _assignable || _value == term.symbol() ){
      if(var){ //if it's variable
        if(var->_assignable){ // if var2 could be match
          _value = var -> value(); // match with var2
          (var -> _trace).push_back(this); //add this element to end of vector, co trace
          _trace.push_back(var); // add var2's element to end of this vector, co trace
  
          if (_trace.size()){ // if this has been traced, let two variable have the same element
            for (int i=0;i<_trace.size();i++){
              (var->_trace).push_back(_trace[i]);
            }              
          }
          if ((var->_trace).size()){ // if var2 has been traced, let two variable have the same element
            for (int i=0;i<(var->_trace).size();i++){
              _trace.push_back((var->_trace)[i]);
            }              
          }	
        }else{//if var2 couldn't be match
          _value = var->value();
          _assignable = false;
        }
        return true;
      }
      if ( ps ){
        _save = ps;
        return true; 
      }
      //if itn't variable
      _value = term.symbol();
      if(_trace.size()){
        for (int i=0;i<_trace.size();i++){
          _trace[i]->_value = term.symbol();
        }          
      }
      _assignable = false;	
      return true;
    }
    return false;
  }

// private:
  string _symbol;
  string _value;
  bool _assignable = true;  
  vector <Variable *> _trace;
  Struct * _save = 0;
};

#endif