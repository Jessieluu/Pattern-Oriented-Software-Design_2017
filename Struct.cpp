#include "struct.h"
#include "iterator.h"

Iterator * Struct::createIterator(){
  return CreateRangeIterator(begin(),end());
}

Iterator * Struct::createDFSIterator(){
  return new DFSIterator<Term *>(this);
}

Iterator * Struct::createBFSIterator(){
  return new BFSIterator<Term *>(this);
}