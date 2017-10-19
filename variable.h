#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"

using std::string;

class Variable : public Term{
public:
  Variable (string s) {
    _symbol = s;
    _value = _symbol;
  }

  string symbol() const{ return _symbol;}

  string value() const { return _value;}

  bool match(Term & term){
    bool re = _assignable;
    Variable * var = dynamic_cast<Variable *>(&term);

    if(_symbol == term.symbol())
      return true;

      if ( _assignable || _value == term.symbol() ){
        if ( var ){// match is variable
          if ( var -> _assignable ){ // other is not match 
            _value = var -> value();
            ( var -> _follow ).push_back ( this );
            _follow.push_back ( var );
    
            if ( _follow.size() ) { // exist each other follow this
              for (int i = 0 ; i < _follow.size() ; i++)
                ( var -> _follow ).push_back ( _follow[i] );
            }
            if ( ( var -> _follow ).size() ){ // exist each other follow var
              for (int i = 0 ; i < ( var -> _follow ).size() ; i++)
                _follow.push_back ( ( var -> _follow )[i] );
            }	
          }
          else{// other is match
            _value = var -> value();
            _assignable = false;
          }
          return true;
        }
        _value = term.symbol();
        if ( _follow.size() ) {
          for (int i = 0 ; i < _follow.size() ; i++)
            _follow[i] -> _value = term.symbol();
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
  std :: vector < Variable * > _follow;

};

#endif