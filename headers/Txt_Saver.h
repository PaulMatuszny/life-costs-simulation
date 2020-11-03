#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Person.h"
#include "Saver.h"
#include <fstream>
using namespace std;

class Txt_Saver : public Saver {
private:
fstream file;
string filename;
public:

Txt_Saver(){
};
virtual void Save(Person &person);
virtual void Open(string ffilename);
virtual void Close();
virtual void saveString(string);
};
