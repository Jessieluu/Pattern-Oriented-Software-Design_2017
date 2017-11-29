#ifndef NODE_H
#define NODE_H

#include "term.h"

enum Operators {SEMICOLON, COMMA, EQUALITY, TERM}; //or=0,and=1,match=2,TERM=3

class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t = 0, Node *l = 0, Node *r = 0):payload(op), term(t), left(l), right(r) {}

  bool evaluate(){
    switch(payload){
      case EQUALITY:
        return (left->term)->match(*(right->term));
        break;  
      case COMMA:
        return left->evaluate() & right->evaluate(); //bit and
        break;  
      case SEMICOLON:
        return left->evaluate() & right->evaluate(); //bit and
        break;
      default:
        return false;
    }
  }

  Operators payload;
  Term *term;
  Node *left, *right;

};

#endif