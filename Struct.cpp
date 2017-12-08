#include "struct.h"
#include "iterator.h"

Iterator<Term*> * Struct::createIterator(){
  return CreateRangeIterator(begin(),end());
}

Iterator<Term*> * Struct::createDFSIterator(){
  return new DFSIterator<Term *>(this);
}

Iterator<Term*> * Struct::createBFSIterator(){
  return new BFSIterator<Term *>(this);
}

bool Struct::match(Term & term){
  Struct * s = dynamic_cast<Struct *>(&term);
  if(s){
    if(_name.symbol() != s->_name.symbol()) return false;
    if(arity() != s->arity()) return false;
    Iterator<Term *> * itSelf = createIterator();
    Iterator<Term *> * itOther = term.createIterator();
    for(itSelf->first(), itOther->first(); !itSelf->isDone(); itSelf->next(), itOther->next()){
      if(!itSelf->currentItem()->match(*itOther->currentItem()))
        return false;
    }
    return true;
  }
  return Term::match(term);
}