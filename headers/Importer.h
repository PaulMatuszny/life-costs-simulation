#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Person.h"
#include <iostream>
using namespace std;

class Importer {
private:
public:

Importer(){
}
virtual void importCosts(Person *){
};
virtual void importIncomes(Person *){
};
virtual void importPerson(Person *){
};
virtual void importAddress(Person *){
};
virtual void Open(string ){
								cout<<"nothing to open";
}

};
