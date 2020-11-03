#include <string>
#include <vector>
#include "macros.h"
#include "Address.h"
#include <iostream>

using namespace std;


Address::Address(){
        street="Null";
        city="Null";
        country="Null";
}

Address::Address(string fstreet, string fcity, string fcountry){
        street=fstreet;
        city=fcity;
        country=fcountry;
}

void Address::displayAddress(){
        cout<<"Country:"<<country<<"\nCity:"<<city<<"\nStreet:"<<street<<endl;
}

string Address::getAddress(){
        return "Country:"+country+"\nCity:"+city+"\nStreet:"+street+"\n";
}

void Address::setAddress(string fstreet, string fcity, string fcountry){
        street=fstreet;
        city=fcity;
        country=fcountry;
}
