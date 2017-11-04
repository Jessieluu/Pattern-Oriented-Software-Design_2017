#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "term.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
          _scanner.nextToken() ;
          vector<Term*> terms;
          while(_scanner.currentChar() != ')'){
            Term * pushTerm = createTerm();
            if(pushTerm != NULL)
              terms.push_back(pushTerm);
          }
          return new Struct(*atom, terms);
        }
        else
          return atom;
    }else if(_scanner.currentChar() == '['){
      _scanner.nextToken() ;
      vector<Term*> terms;
      while(_scanner.bufferSize() > _scanner.position() && _scanner.currentChar() != ']'){
        Term * pushTerm = createTerm();
        if(pushTerm != NULL)
          terms.push_back(pushTerm);
      }
      if (_scanner.bufferSize() == _scanner.position())
        throw string("unexpected token");
      if (_scanner.currentChar() == ']')
        _scanner.nextToken();
      return new List(terms);
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    vector<Term*> args;
    while(_scanner.bufferSize() > _scanner.position()){
      Term* term = createTerm();
      if (term != NULL)
        args.push_back(term);
    }
    // if(term)
    //   args.push_back(term);
    // while((_currentToken = _scanner.nextToken()) == ',') { 
    //   args.push_back(createTerm());
    // }
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif
