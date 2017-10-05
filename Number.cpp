#include "number.h"
#include "atom.h"
#include "variable.h"
using namespace std;

Number::Number (int num) :_symbol (to_string(num)) {}

string Number::symbol(){ return _symbol;}

string Number::value(){ return _symbol;}

bool Number::match (Number num){ return _symbol == num.symbol();}

bool Number::match (Atom atom){ return false;}

bool Number::match (Variable & var){ return var.match(this->symbol());}
