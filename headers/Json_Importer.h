#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Person.h"
#include "Cost.h"
#include "Source_Of_Income.h"
#include "Importer.h"
#include "json.hpp"
#include <fstream>
using namespace std;

using json = nlohmann::json;


class Json_Importer : public Importer {
private:
fstream file;
string filename;
json j;
public:

Json_Importer(){
};
virtual void importCosts(Person *);
virtual void importIncomes(Person *);
virtual void importPerson(Person *);
virtual void importAddress(Address *);
virtual void Open(string);
};
