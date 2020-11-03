#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Person.h"
#include "Saver.h"
#include <fstream>
using namespace std;

class Csv_Saver : public Saver {
private:
fstream file;
string filename;
public:

Csv_Saver(){
};
virtual void Save(Person &person);
virtual void saveString(string);
virtual void Open(string ffilename);
virtual void Close();
};
