#include <string>
#include <vector>
#include "macros.h"
#include "Person.h"
#include "Const_Cost.h"

#include <iostream>

using namespace std;

Person::Person(string fname, string fsurname, ui fage, char fsex){
								name=fname;
								surname=fsurname;
								age=fage;
								sex=fsex;
}

void Person::setPersonData(string fname, string fsurname, ui fage, char fsex){
								name=fname;
								surname=fsurname;
								age=fage;
								sex=fsex;
}

string Person::getFullName(){
								return name+" "+surname;
}

string Person::getName(){
								return name;
}

string Person::getSurname(){
								return surname;
}

ui Person::getAge(){
								return age;
}

char Person::getSex(){
								return sex;
}

void Person::addCost(Cost *fcost){
								list_of_costs.push_back(fcost);
}

Cost* Person::getCostByNumber(int i){
								return list_of_costs[i];
}

void Person::addIncome(Source_Of_Income *fincome){
								list_of_incomes.push_back(fincome);
}

Source_Of_Income* Person::getIncomeByNumber(int i){
								return list_of_incomes[i];
}

string Person::getAddress(){
								return address.getAddress();
}

void Person::displayData(){
								cout<<name<<" "<<surname<<" Age:"<<age<<" Sex:"<<sex<<endl;
								address.displayAddress();
}

void Person::displayCosts(){
								for(int j=0; j<(int)list_of_costs.size(); j++)
																list_of_costs[j]->displayCostData();
}

void Person::displayCostsForMonth(ui fmonth){
								for(int i=0; i<(int)list_of_costs.size(); i++) {
																if(list_of_costs[i]->getCostType()=="const_cost") {
																								ui cost_start_month=list_of_costs[i]->getStartMonth();
																								if(cost_start_month<=fmonth)
																																list_of_costs[i]->displayCostData();
																}
																else if(list_of_costs[i]->getCostType()=="period_cost") {
																								ui cost_start_month=list_of_costs[i]->getStartMonth();
																								ui cost_end_month=list_of_costs[i]->getEndMonth();
																								if(cost_start_month<=fmonth && cost_end_month>=fmonth) {
																																list_of_costs[i]->displayCostData();
																								}
																}
								}
}

void Person::displayIncomes(){
								for(int j=0; j<(int)list_of_incomes.size(); j++)
																list_of_incomes[j]->displayIncomeData();
}

void Person::displayIncomesForMonth(ui fmonth){
								for(int i=0; i<(int)list_of_incomes.size(); i++) {
																string type=list_of_incomes[i]->getIncomeType();
																if(type=="one_time_impact"||type=="employment") {
																								ui income_start_month=list_of_incomes[i]->getIncomeStartMonth();
																								ui income_end_month=list_of_incomes[i]->getIncomeEndMonth();
																								if(income_start_month<=fmonth && income_end_month>=fmonth) {
																																list_of_incomes[i]->displayIncomeData();
																								}
																}
								}
}

void Person::setAddress(Address &faddress){
								address=faddress;
}

int Person::getCostSummary(ui fstart_month,ui fend_month){
								int summary=0;
								for(int i=0; i<(int)list_of_costs.size(); i++) {
																if(list_of_costs[i]->getCostType()=="const_cost") {
																								ui cost_start_month=list_of_costs[i]->getStartMonth();
																								if(cost_start_month<=fstart_month)
																																summary+=list_of_costs[i]->getCostValue();
																}
																else if(list_of_costs[i]->getCostType()=="period_cost") {
																								ui cost_start_month=list_of_costs[i]->getStartMonth();
																								ui cost_end_month=list_of_costs[i]->getEndMonth();
																								if(cost_start_month<=fstart_month && cost_end_month>=fend_month) {
																																summary+=list_of_costs[i]->getCostValue();
																								}
																}
								}
								return summary;
}

int Person::getIncomeSummary(ui fstart_month,ui fend_month){
								int summary=0;
								for(int i=0; i<(int)list_of_incomes.size(); i++) {
																string type=list_of_incomes[i]->getIncomeType();
																if(type=="one_time_impact"||type=="employment") {
																								ui income_start_month=list_of_incomes[i]->getIncomeStartMonth();
																								ui income_end_month=list_of_incomes[i]->getIncomeEndMonth();
																								if(income_start_month<=fstart_month && income_end_month>=fend_month) {
																																summary+=list_of_incomes[i]->getIncomeValue();
																								}
																}
								}
								return summary;
}
