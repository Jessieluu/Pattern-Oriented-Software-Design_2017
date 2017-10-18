#pragma once
#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "term.h"
#include "variable.h"
#include <sstream>

using namespace std;
using std::string;
using std::stringstream;

string doubleToString (double d){
    std :: stringstream ss;
    ss << d;
    return ss.str();
} 

class Number : public Term{

public:

    Number (double value):_symbol(doubleToString(value)) {}
  
    string symbol() const{
        return _symbol;
    }

    bool match (Variable & var){ return var.match(*this);}

    string _symbol;

};


#endif
