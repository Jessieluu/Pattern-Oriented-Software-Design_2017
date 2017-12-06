#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "variable.h"
#include "atom.h"
#include "number.h"
#include "list.h"
#include "struct.h"
#include "iterator.h"
#include <iostream>
#include <vector>

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });

    Iterator<Term*> *itStruct = s.createIterator();
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
    Iterator<Term*> *itStruct = s.createIterator();
    itStruct->first();
    itStruct->next();
    Struct *s2 = dynamic_cast<Struct *>(itStruct->currentItem());
    Iterator<Term*> *itStruct2 = s2->createIterator();
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

    Iterator<Term*> * itList = l.createIterator();
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
    Iterator<Term*> * it = one.createIterator();
    it->first();
    ASSERT_TRUE(it->isDone());
}

//s(1, 2)
TEST(iterator, DFS_struct){
    Number one(1);
    Number two(2);
    Struct s(Atom("s"), {&one, &two});
    Iterator<Term*> * itStruct = s.createDFSIterator();
    itStruct->first();
    // itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

// s(s1(1, 2), s2(3, s3(4, 5)))
TEST(iterator, DFS_nestStruct){
    Number one(1);
    Number two(2);
    Number three(3);
    Number four(4);
    Number five(5);
    Struct s1(Atom("s1"), {&one, &two});
    Struct s3(Atom("s3"), {&four, &five});
    Struct s2(Atom("s2"), {&three, &s3});    
    Struct s(Atom("s"), {&s1, &s2});
    
    Iterator<Term*> * itStruct = s.createDFSIterator();
    itStruct->first();
    ASSERT_EQ("s1(1, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("s2(3, s3(4, 5))", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("3", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("s3(4, 5)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("4", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("5", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

// [1, 2]
TEST(iterator, DFS_list){
    Number one(1);
    Number two(2);
    List l({&one, &two});
    Iterator<Term*> * itList = l.createDFSIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("2", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

// [1, [2, 3]]
TEST(iterator, DFS_nestList){
    Number one(1);
    Number two(2);
    Number three(3);
    vector<Term *> v2 = {&two, &three};
    List l2(v2);
    vector<Term *> v = {&one, &l2};
    List l(v);

    Iterator<Term*> * itList = l.createDFSIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("[2, 3]", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("2", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("3", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

//s(1, 2)
TEST(iterator, BFS_struct){
    Number one(1);
    Number two(2);
    Struct s(Atom("s"), {&one, &two});
    Iterator<Term*> * itStruct = s.createBFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());    
}

// // s(s1(1, 2), s2(3, s3(4, 5)))
TEST(iterator, BFS_nestStruct){
    Number one(1);
    Number two(2);
    Number three(3);
    Number four(4);
    Number five(5);
    Struct s1(Atom("s1"), {&one, &two});
    Struct s3(Atom("s3"), {&four, &five});
    Struct s2(Atom("s2"), {&three, &s3});    
    Struct s(Atom("s"), {&s1, &s2});
    
    Iterator<Term*> * itStruct = s.createBFSIterator();
    itStruct->first();
    ASSERT_EQ("s1(1, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("s2(3, s3(4, 5))", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("3", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("s3(4, 5)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("4", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("5", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

// [1, 2]
TEST(iterator, BFS_list){
    Number one(1);
    Number two(2);
    vector<Term *> v = {&one, &two};
    List l(v);
    Iterator<Term*> * itList = l.createBFSIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("2", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

// [1, [2, 3]]
TEST(iterator, BFS_nestList){
    Number one(1);
    Number two(2);
    Number three(3);
    vector<Term *> v2 = {&two, &three};
    List l2(v2);
    vector<Term *> v = {&one, &l2};
    List l(v);
    Iterator<Term*> * itList = l.createBFSIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("[2, 3]", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("2", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("3", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

#endif