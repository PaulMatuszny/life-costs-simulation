#include <string>
#include <vector>
#include "Source_Of_Income.h"
#include "macros.h"

using namespace std;

class Employment : public Source_Of_Income {
private:
string name;
ui value_per_hour;
ui hours_in_month;
ui start_month;
ui end_month;
const string type="employment";

public:
Employment(ui, ui, string,ui,ui);
virtual ui getIncomeValue();
virtual string getIncomeName();
virtual string getIncomeType();
virtual void displayIncomeData();
virtual ui getIncomeStartMonth();
virtual ui getIncomeEndMonth();

};
