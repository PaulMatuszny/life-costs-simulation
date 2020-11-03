#include <string>
#include <vector>
#include "macros.h"
#include "One_Time_Impact.h"
#include <iostream>

using namespace std;

One_Time_Impact::One_Time_Impact(ui fvalue, string fname, ui fmonth) : Source_Of_Income(){
								value=fvalue;
								name=fname;
								month=fmonth;
}

string One_Time_Impact::getIncomeName(){
								//cout<<"Getting One-Time Impact name:"<<name<<endl;
								return name;
}

string One_Time_Impact::getIncomeType(){
								//cout<<"Getting One-Time Impact name:"<<name<<endl;
								return type;
}

ui One_Time_Impact::getIncomeValue(){
								//cout<<"Getting One-Time Impact Value:"<<value<<endl;
								return value;
}

void One_Time_Impact::displayIncomeData(){
								cout<<"Name:"<<name<<"\nValue:"<<value<<endl;
}

ui One_Time_Impact::getIncomeEndMonth(){
								return month;
}

ui One_Time_Impact::getIncomeStartMonth(){
								return month;
}
