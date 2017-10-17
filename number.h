#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
using namespace std;
using std::string;

class Number : public Term{
public:
    Number (double value):_symbol(to_string(value)) {}
  
    string symbol() const{
        return _symbol;
    }
  
    string _symbol;
    string _value;
};


#endif
