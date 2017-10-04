#include "include/number.h"
#include "include/atom.h"
#include "include/variable.h"

Variable::Variable (string s): _value(s) {}

string Variable::symbol(){ return _value;}

bool Variable::match(Atom atom){
    if(_assignable || _value == atom.symbol()){
        _value = atom.symbol();
        _assignable = false;
        return true;
    }
    return false;
}

bool Variable::match(Number num){
    if(_assignable || _value == num.symbol()){
        _value = num.symbol();
        _assignable = false;
        return true;
    }
    return false;
}
