#include <string>
#include <vector>
#include "Cost.h"
#include "macros.h"
#include <iostream>

using namespace std;

class Const_Cost : public Cost {
private:
string name;
ui value;
ui start_month;
ui end_month;
const string type="const_cost";

public:
Const_Cost(ui fvalue, string fname, ui fstart);
virtual ui getCostValue();
virtual string getCostName();
virtual void displayCostData();
virtual string getCostType();
virtual ui getStartMonth();
virtual ui getEndMonth();
};
