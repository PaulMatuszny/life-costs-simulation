#include <string>
#include <vector>
#include "macros.h"

using namespace std;

class Address {
private:
string street;
string city;
string country;

public:
Address();
Address(string, string, string);
void displayAddress();
void setAddress(string,string,string);
string getAddress();
};
