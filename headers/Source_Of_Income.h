#pragma once
#include <string>
#include <vector>
#include "macros.h"

using namespace std;

class Source_Of_Income {
const string type="";
public:
Source_Of_Income(){
}
virtual ui getIncomeValue()=0;
virtual string getIncomeName()=0;
virtual string getIncomeType()=0;
virtual void displayIncomeData()=0;
virtual ui getIncomeStartMonth()=0;
virtual ui getIncomeEndMonth()=0;
};
