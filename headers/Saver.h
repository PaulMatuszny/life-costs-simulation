#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Person.h"
#include <iostream>
using namespace std;

class Saver {
private:
public:

Saver(){
}
virtual void Save(Person &person){
								cout<<"nothing to save";
}
virtual void Open(string filename){
								cout<<"nothing to open";
}
virtual void Close(){
								cout<<"nothing to close";
}
virtual void saveString(string)=0;

};
