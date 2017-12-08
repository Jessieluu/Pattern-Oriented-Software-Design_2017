#ifndef TERM_H
#define TERM_H

#include <string>
#include <sstream>
using std::string;

template<typename T>
class Iterator;
class Term{
public:
  virtual string symbol() const {return _symbol;}
  virtual string value() const {return symbol();}
  virtual bool match(Term & a);
  virtual int arity() { return 0; }
  virtual Term * args(int index) { return nullptr; }
  virtual Iterator<Term*> * createIterator();

protected:

  Term (string s=""):_symbol(s) {}
  string _symbol;
};

#endif