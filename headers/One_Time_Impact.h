#include <string>
#include <vector>
#include "Source_Of_Income.h"
#include "macros.h"

using namespace std;

class One_Time_Impact : public Source_Of_Income {
private:
string name;
ui value;
ui month;
const string type="one_time_impact";

public:
One_Time_Impact(ui, string, ui);
virtual ui getIncomeValue();
virtual string getIncomeName();
virtual string getIncomeType();
virtual void displayIncomeData();
virtual ui getIncomeStartMonth();
virtual ui getIncomeEndMonth();
};
