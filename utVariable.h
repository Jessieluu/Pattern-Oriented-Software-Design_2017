#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "variable.h"
#include "struct.h"
#include "atom.h"
#include "number.h"

TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X.symbol());
}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "X", X.symbol());
  ASSERT_EQ( "tom", X.value());
}

TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
  tom.match(X);
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX){
  Variable X("X");
  Number E(2.7182);
  X.match(E);
  EXPECT_TRUE(X.match(E));
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX) {
  Variable X("X");
  Variable Y("Y");
  Number E(1);
  X.match(Y);
  X.match(E);
  // ASSERT_EQ("1",Y.value());
  EXPECT_TRUE(Y.match(E));
}
  
// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY) {
  Variable X("X");
  Variable Y("Y");
  Number E(1);
  Y.match(E);
  X.match(Y);
  EXPECT_TRUE(X.match(E));
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX) {
  Variable X("X");
  Number E(1);
  X.match(E);  
  X.match(X);
  EXPECT_TRUE(X.match(E));
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY) {
  Variable Y("Y");
  Variable X("X");
  Number E(1);
  Y.match(E);
  X.match(Y);
  EXPECT_TRUE(X.match(E));
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX) {
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  Number E(1);
  Z.match(E);
  Y.match(Z);
  X.match(Y);
  EXPECT_TRUE(X.match(E));
  EXPECT_TRUE(Y.match(E));
  EXPECT_TRUE(Z.match(E));
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX) {
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  Number E(1);
  X.match(Y);
  X.match(Z);
  Z.match(E);
  EXPECT_TRUE(X.match(E));
  EXPECT_TRUE(Y.match(E));
  EXPECT_TRUE(Z.match(E));
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1) {
  Variable X("X");
  std::vector<Term *> v ={&X};
  Struct s(Atom("s"), v);
  Variable Y("Y");
  Y.match(s);
  ASSERT_EQ("Y",Y.symbol());
  ASSERT_EQ("s(X)",Y.value());  
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2) {
  Variable X("X");
  Variable Y("Y");
  Atom teddy("teddy");
  X.match(teddy);
  std::vector<Term *> v ={&X};
  Struct s(Atom("s"), v);
  Y.match(s);
  ASSERT_EQ("Y", Y.symbol());
  ASSERT_EQ("s(teddy)",Y.value()); 
}

#endif