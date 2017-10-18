#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
#include "variable.h"
using namespace std;
using std::string;

class Number : public Term{
public:
    Number (double value):_symbol(to_string(value)) {}
  
    string symbol() const{
        return _symbol;
    }

    bool match (Variable & var){ return var.match(*this);}

    string _symbol;
};


#endif
