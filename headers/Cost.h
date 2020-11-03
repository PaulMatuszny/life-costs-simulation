#pragma once
#include <string>
#include <vector>
#include "macros.h"

using namespace std;

class Cost {
const string type="";
public:
Cost(){
}
virtual ui getCostValue()=0;
virtual string getCostName()=0;
virtual void displayCostData()=0;
virtual string getCostType()=0;
virtual ui getStartMonth()=0;
virtual ui getEndMonth()=0;
};
