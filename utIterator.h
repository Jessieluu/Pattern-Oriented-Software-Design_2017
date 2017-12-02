#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "variable.h"
#include "atom.h"
#include "number.h"
#include "list.h"
#include "struct.h"
#include "iterator.h"

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });

    Iterator *itStruct = s.createIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    // StructIterator it(&s);
    Iterator *itStruct = s.createIterator();
    itStruct->first();
    itStruct->next();
    Struct *s2 = dynamic_cast<Struct *>(itStruct->currentItem());
    Iterator *itStruct2 = s2->createIterator();
    // StructIterator it2(s2);

    itStruct2->first();
    ASSERT_EQ("X", itStruct2->currentItem()->symbol());
    ASSERT_FALSE(itStruct2->isDone());
    itStruct2->next();
    ASSERT_EQ("2", itStruct2->currentItem()->symbol());
    ASSERT_FALSE(itStruct2->isDone());
    itStruct2->next();
    ASSERT_TRUE(itStruct2->isDone());
}

TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    // ListIterator it(&l);
    Iterator* itList = l.createIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator){
    Number one(1);
    NullIterator nullIterator(&one);
    nullIterator.first();
    ASSERT_TRUE(nullIterator.isDone());
    Iterator * it = one.createIterator();
    it->first();
    ASSERT_TRUE(it->isDone());
}



#endif