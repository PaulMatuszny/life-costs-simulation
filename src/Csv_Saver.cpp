#include <string>
#include <vector>
#include "macros.h"
#include "Employment.h"
#include "Csv_Saver.h"
#include <fstream>
#include <iostream>

using namespace std;

void Csv_Saver::Open(string ffilename){
        filename=ffilename;
        cout<<"Opening csv of filename:"<<filename<<endl;
        file.open(filename,ios::app);
        if (file.is_open())
        {
                cout<<"Successfully oppened csv file"<<endl;
        }
        else cout << "Unable to open file";
}

void Csv_Saver::Save(Person &person){
        if(file.is_open()) {
                cout<<"Saving to csv file: "<<filename<<endl;
                file<<person.getFullName()<<"\n"<<person.getAddress()<<endl;
        }
}

void Csv_Saver::Close(){
        if(file.is_open()) {
                file.close();
                cout<<"Closing csv file: "<<filename<<endl;
        }
}

void Csv_Saver::saveString(string s){
        if(file.is_open())
                file<<s;
}
