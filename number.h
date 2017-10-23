#include "atom.h"
#include <string>
using std::string;

class Number : public Term{
public:
  Number(double db):Term(db) {}
};
