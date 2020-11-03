#include <string>
#include <vector>
#include "macros.h"
#include "Employment.h"
#include <iostream>

using namespace std;

Employment::Employment(ui fvalue, ui fhour, string fname, ui fstart, ui fend) : Source_Of_Income(){
								value_per_hour=fvalue;
								hours_in_month=fhour;
								name=fname;
								start_month=fstart;
								end_month=fend;
}

string Employment::getIncomeName(){
								return name;
}

string Employment::getIncomeType(){
								//cout<<"Getting One-Time Impact name:"<<name<<endl;
								return type;
}


ui Employment::getIncomeValue(){
								return value_per_hour*hours_in_month;
}

void Employment::displayIncomeData(){
								cout<<"Name:"<<name<<" Value:"<<getIncomeValue()<<endl;
}

ui Employment::getIncomeEndMonth(){
								return end_month;
}

ui Employment::getIncomeStartMonth(){
								return start_month;
}
