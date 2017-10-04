#ifndef UTTERM_H
#define UTTERM_H
#include "variable.h"
#include "number.h"


//test Number.value()
TEST (Number, ctor) {
    Number N(21);
    ASSERT_EQ("21",N.value());
}
//test Number.symbol()
TEST (Number, symbol) {
    Number N(21);
    ASSERT_EQ("21",N.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number N(25);
    Number X(25);
    ASSERT_TRUE(N.match(X));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number N(25);
    Number X(20);
    ASSERT_FALSE(N.match(X));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number N(25);
    Atom tom("tom");
    ASSERT_FALSE(N.match(tom));

}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
    Number N(25);
    Variable X("X");
    ASSERT_TRUE(N.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Atom tom("tom");
    Number N(25);
    ASSERT_FALSE(tom.match(N));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
    Atom tom("tom");
    Variable X("X");
    ASSERT_TRUE(tom.match(X));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
    Variable X("X");
    Atom tom("tom");
    ASSERT_TRUE(X.match(tom) && tom.match(X));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Variable X("X");
    Atom jerry("jerry");
    Atom tom("tom");
    ASSERT_FALSE(X.match(jerry) && tom.match(X));
}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
    Variable X("X");
    Number N(5);
    ASSERT_TRUE(X.match(N)); 
}

// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
    Variable X("X");
    Number N(25);
    Number M(100);
    ASSERT_FALSE(X.match(N) && X.match(M));

}

// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
    Variable X("X");
    Atom tom("tom");
    Number N(25);
    ASSERT_FALSE(X.match(tom) && X.match(N));

}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
    Atom tom("tom");
    Variable X("X");
    Number N(25);
    ASSERT_FALSE(tom.match(X) && N.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){
    Variable X("X");
    Atom tom("tom");
    ASSERT_TRUE(X.match(tom) && X.match(tom));
}
#endif