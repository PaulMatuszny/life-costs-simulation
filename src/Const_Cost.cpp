#include <string>
#include <vector>
#include "macros.h"
#include "Const_Cost.h"
#include <iostream>

using namespace std;

Const_Cost::Const_Cost(ui fvalue, string fname, ui fstart) : Cost(){
								value=fvalue;
								name=fname;
								start_month=fstart;
								end_month=100000;
}

string Const_Cost::getCostName(){
								return name;
}

string Const_Cost::getCostType(){
								return type;
}

ui Const_Cost::getCostValue(){
								return value;
}

void Const_Cost::displayCostData(){
								cout<<"Name:"<<name<<"\nValue:"<<getCostValue()<<endl;
}

ui Const_Cost::getStartMonth(){
								return start_month;
}

ui Const_Cost::getEndMonth(){
								return end_month;
}
