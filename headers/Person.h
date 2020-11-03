#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Cost.h"
#include "Source_Of_Income.h"
#include "Address.h"
using namespace std;

class Person {
private:
string name;
string surname;
ui age;
char sex;

//vector <Cost> costs;
//vector <Source_Of_Income> incomes;
Address address;
vector <Cost*> list_of_costs;
vector <Source_Of_Income*> list_of_incomes;
public:
Person() : name("NULL"),surname("NULL"),age(0),sex('M'){
}
Person(string, string, ui, char);

void setPersonData(string,string,ui,char);

string getFullName();

string getName();

string getSurname();

ui getAge();

char getSex();

void addCost(Cost*);

Cost* getCostByNumber(int);

void addIncome(Source_Of_Income*);

Source_Of_Income* getIncomeByNumber(int);

void displayData();

void displayCosts();

void displayIncomes();

void displayIncomesForMonth(ui );

void displayCostsForMonth(ui );

void setAddress(Address&);

string getAddress();

int getCostSummary(ui,ui);

int getIncomeSummary(ui,ui);
};
