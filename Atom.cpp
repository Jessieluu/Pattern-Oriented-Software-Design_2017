#include "include/number.h"
#include "include/atom.h"
#include "include/variable.h"

Atom :: Atom ( string atom ) : _symbol ( atom ) {}

string Atom::symbol(){ return _symbol;}

bool Atom::match(Number num){ return false;}

bool Atom::match(Variable &var){
    return var.match(*this);
}