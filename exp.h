#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include <string>
using std :: string;
#include <iostream>
using namespace std;

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getResultTree() = 0;
    
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  bool evaluate(){
    return (_left->match(*_right));
  }

  string getResultTree(){
    bool logicString = evaluate();
    if(logicString && _left -> symbol() != _right -> symbol()){
      if(_left -> getVariable() != nullptr)
        return _left -> symbol() + " = " + _right -> value();
      else if(_right -> getVariable() != nullptr)
        return _left -> value() + " = " + _right -> symbol();  
        
    }else if(logicString)
      return "true";
    else
      return "false";
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

  string getResultTree(){
    bool logicString = evaluate();
    if (logicString && _left->getResultTree() == "true" && _right->getResultTree() == "true") 
      return "true";
    else if ( logicString && _left->getResultTree() ==  _right->getResultTree())
      return _left->getResultTree();
    else if ( logicString && _left->getResultTree().find( _right->getResultTree()) != string::npos )
      return _left->getResultTree();
    else if ( logicString && _left->getResultTree() == "true" )
      return _right->getResultTree();
    else if ( logicString && _right->getResultTree() == "true" )   
      return _left->getResultTree();
    else if(!logicString)
      return "false";
    else 
      return _left->getResultTree() + ", " + _right->getResultTree();
  }

 

private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }
  string getResultTree(){
    bool legalEva = evaluate();
    if ( _left->getResultTree() == "true" || _left->getResultTree() == "false" )  
      return _right->getResultTree();
    else if ( _right->getResultTree() == "true" || _right->getResultTree() == "false" )
      return _left->getResultTree();
      
    else 
      return _left->getResultTree() + "; " + _right->getResultTree();
  }
  

private:
  Exp * _left;
  Exp * _right;
};
#endif
