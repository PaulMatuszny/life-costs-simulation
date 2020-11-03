#include <string>
#include <vector>
#include "macros.h"
#include "Importer.h"
#include "Json_Importer.h"
#include "Employment.h"
#include "One_Time_Impact.h"

#include "Const_Cost.h"
#include "Period_Cost.h"

#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void Json_Importer::Open(string ffilename){
        filename=ffilename;
        cout<<"Opening json of filename:"<<filename<<endl;
        ifstream i(filename);
        i >> j;
        i.close();
}

void Json_Importer::importIncomes(Person *person){

        for (auto& element : j["incomes"]) {
                //cout << element << '\n';
                string type=element["type"];
                string name=element["name"];
                if(type=="employment") {
                        ui value_per_hour=element["value_per_hour"];
                        ui hours_in_month=element["hours_in_month"];
                        ui start_month=element["start_month"];
                        ui end_month=element["end_month"];
                        Source_Of_Income *temp_income;
                        temp_income=new Employment(value_per_hour,hours_in_month,name,start_month,end_month);
                        person->addIncome(temp_income);
                        cout<<"EMPLOY"<<endl;
                }
                else if(type=="one_time_impact") {
                        ui value=element["value"];
                        ui month=element["month"];
                        Source_Of_Income *temp_income;
                        temp_income=new One_Time_Impact(value,name,month);
                        person->addIncome(temp_income);
                        cout<<"ONE TIME IMPACT"<<endl;
                }
        }
        //cout<<j["incomes"][0]["name"]<<endl;saf
}

void Json_Importer::importCosts(Person *person){
        for (auto& element : j["costs"]) {
                //cout << element << '\n';
                string type=element["type"];
                string name=element["name"];
                if(type=="const_cost") {
                        ui value=element["value"];
                        ui start_month=element["start_month"];
                        Cost *temp_cost;
                        temp_cost=new Const_Cost(value,name,start_month);
                        person->addCost(temp_cost);
                        cout<<"CONST COST"<<endl;
                }
                else if(type=="period_cost") {
                        ui value=element["value"];
                        ui start_month=element["start_month"];
                        ui end_month=element["end_month"];
                        Cost *temp_cost;
                        temp_cost=new Period_Cost(value,name,start_month,end_month);
                        person->addCost(temp_cost);
                        cout<<"PERIOD COST"<<endl;
                }
        }
}

void Json_Importer::importPerson(Person *person){
        for (auto& element : j["person"]) {
                //cout << element << '\n';
                string name=element["name"];
                string surname=element["surname"];
                ui age=element["age"];
                string sex=element["sex"];

                person->setPersonData(name,surname,age,sex[0]);
        }
}

void Json_Importer::importAddress(Address *address){
        for (auto& element : j["address"]) {
                //cout << element << '\n';
                string street=element["street"];
                string city=element["city"];
                string country=element["country"];

                address->setAddress(street,city,country);
        }
}
