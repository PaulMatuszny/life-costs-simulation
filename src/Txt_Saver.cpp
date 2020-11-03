#include <string>
#include <vector>
#include "macros.h"
#include "Employment.h"
#include "Txt_Saver.h"
#include <fstream>
#include <iostream>

using namespace std;

void Txt_Saver::Open(string ffilename){
        filename=ffilename;
        cout<<"Opening txt of filename:"<<filename<<endl;
        file.open(filename,ios::out);
        if (file.is_open())
        {
                cout<<"Successfully oppened txt file"<<endl;
        }
        else cout << "Unable to open file";
}

void Txt_Saver::Save(Person &person){
        if(file.is_open()) {
                cout<<"Saving to txt file: "<<filename<<endl;
                file<<person.getFullName()<<"\n"<<person.getAddress()<<endl;
        }
}

void Txt_Saver::Close(){
        if(file.is_open()) {
                file.close();
                cout<<"Closing txt file: "<<filename<<endl;
        }
}

void Txt_Saver::saveString(string s){
        if(file.is_open())
                file<<s;
}
