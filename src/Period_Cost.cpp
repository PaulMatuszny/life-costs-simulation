#include <string>
#include <vector>
#include "macros.h"
#include "Period_Cost.h"
#include <iostream>

using namespace std;

Period_Cost::Period_Cost(ui fvalue, string fname, ui fstart, ui fend) : Cost(){
								value=fvalue;
								name=fname;
								start_month=fstart;
								end_month=fend;
}

Period_Cost::Period_Cost(const Period_Cost &temp) : Cost(){
								value=temp.value;
								name=temp.name;
								start_month=temp.start_month;
								end_month=temp.end_month;
}

string Period_Cost::getCostName(){
								return name;
}

string Period_Cost::getCostType(){
								return type;
}

ui Period_Cost::getCostValue(){
								return value;
}

void Period_Cost::displayCostData(){
								cout<<"Name:"<<name<<"\nValue:"<<getCostValue()<<endl;
}

ui Period_Cost::getStartMonth(){
								return start_month;
}

ui Period_Cost::getEndMonth(){
								return end_month;
}
