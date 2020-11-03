#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Saver.h"
using namespace std;

class Simulator {
private:
vector <Person> list_of_people;
vector <Saver*> list_of_savers;

//vector <Cost> costs;
//vector <Source_Of_Income> incomes;
//Adress adress;
// vector <Cost*> costs;
//vector <Source_Of_Income*> incomes;
public:

Simulator();
void Simulate(ui,ui);
void addSaver(Saver *saver);
void addPerson(Person &person);
void closeSavers();
};
