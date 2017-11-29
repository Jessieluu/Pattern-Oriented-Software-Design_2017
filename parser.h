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
#include "node.h"
#include <map>

#include "utParser.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  std::map<std::string,Term*> inScopeVariables;
  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;

    if(token == VAR){
      string name = symtable[_scanner.tokenValue()].first;
      if(!inScopeVariables[name])inScopeVariables[name] = new Variable(name);
      return inScopeVariables[name];
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }
    return nullptr;

  }



  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }

  void matchings(){
    Term * term = createTerm();
    _terms.push_back(term);

    while( (_currentToken = _scanner.nextToken())== '=' || _currentToken == ',' || _currentToken == ';' ){
      if(_currentToken == '='){ //if currentToken == '='
        Node * left = new Node(TERM, _terms.back(), nullptr, nullptr); //catch left of '='
        _terms.push_back(createTerm()); //search next
        Node * right = new Node(TERM, _terms.back(), nullptr, nullptr); //catch right of '='
        _expressionTree = new Node(EQUALITY, nullptr, left, right); //make tree
      }else { //if currentToken == ',' or ';'
        auto op = COMMA;
        if(_currentToken == ';'){
          inScopeVariables={};
          op = SEMICOLON;
        }
        Node * left = _expressionTree;
        matchings();
        Node * right = _expressionTree;
        _expressionTree = new Node(op, nullptr, left, right);          
      }
    }
  }

  Node * expressionTree() {
    return _expressionTree;
  }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest, ListOfTermsEmpty);
  FRIEND_TEST(ParserTest, listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  Node * _expressionTree;
  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
};
#endif