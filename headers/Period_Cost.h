#include <string>
#include <vector>
#include "Cost.h"
#include "macros.h"

using namespace std;

class Period_Cost : public Cost {
private:
string name;
ui value;
ui start_month;
ui end_month;
const string type="period_cost";

public:
Period_Cost(ui fvalue, string fname, ui fstart, ui fend);
Period_Cost(const Period_Cost&);
virtual ui getCostValue();
virtual string getCostName();
virtual void displayCostData();
virtual string getCostType();
virtual ui getStartMonth();
virtual ui getEndMonth();
};
