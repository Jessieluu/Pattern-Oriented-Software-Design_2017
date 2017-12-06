#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include <stack>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

template <class Type>
class Iterator 
{
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term * currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class NullIterator : public Iterator<Term*>
{
public:
  NullIterator(Term * n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};


template<typename T>
class DFSIterator : public Iterator<Term*>{

public:
  DFSIterator(T term){DFS(term);}
  void first(){index=1;}
  T currentItem() const {return terms[index];}
  bool isDone() const {return index==terms.size();}
  void next(){++index;}

private:
  std::vector<Term*> terms;
  int index=0;
  void DFS(Term* currentNode){
    terms.push_back(currentNode);
    
    Struct* s = dynamic_cast<Struct*>(currentNode);
    if(s){for(Term* child : *s)DFS(child);}
    
    List* l = dynamic_cast<List*>(currentNode);
    if(l){for(Term* child : *l)DFS(child);}
  }
};


template<typename T>
class BFSIterator : public Iterator<Term*>{

public:
  BFSIterator(T term){BFS(term);}
  void first(){index=1;}
  T currentItem() const {return terms[index];}
  bool isDone() const {return index==terms.size();}
  void next(){++index;}

private:
  std::vector<Term*> terms;
  int index=0;
  
  void BFS(Term* root){
    std::queue<Term*> pending_nodes;
    pending_nodes.push(root);

    while(pending_nodes.size()!=0){
      Term* current = pending_nodes.front();
      pending_nodes.pop();

      terms.push_back(current);

      Struct* s = dynamic_cast<Struct*>(current);
      if(s){for(Term* child : *s)pending_nodes.push(child);}
      
      List* l = dynamic_cast<List*>(current);
      if(l){for(Term* child : *l)pending_nodes.push(child);}
    }
  }
};


template<typename It>
class RangeIterator: public Iterator<Term*>{
public:
  RangeIterator(It begin,It end):begin(begin),end(end){}
  void first(){current=begin;}
  void next(){++current;}
  Term * currentItem() const { return *current;}
  bool isDone() const { return current == end;}
  
private:  
  It begin,end,current;
};

template<typename It>
RangeIterator<It>* CreateRangeIterator(It begin,It end){
  return new RangeIterator<It>(begin,end);
}

#endif