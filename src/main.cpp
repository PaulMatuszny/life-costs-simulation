#include <iostream>
#include <string>
#include "macros.h"

#include "Person.h"

#include "Source_Of_Income.h"
#include "Employment.h"
#include "One_Time_Impact.h"

#include "Saver.h"
#include "Txt_Saver.h"
#include "Csv_Saver.h"

#include "Cost.h"
#include "Const_Cost.h"
#include "Period_Cost.h"

#include "Simulator.h"

#include "Importer.h"
#include "Json_Importer.h"

using namespace std;


int main(int argc, char * argv[]){
        string filename_out="data.csv";
        string filename_in="test.json";
        //cout<<argc<<" : "<<argv[1]<<" arg2:"<<argv[2]<<endl;
        if(argc==3) {
                filename_in=argv[1];
                filename_out=argv[2];
        }
        else if(argc==2) {
                cout<<"Podano tylko 1 argument"<<endl;
                return 0;
        }
        else {
                cout<<"Prosze podac w oddzielnych argumentach nazwy plikow: in out, np: in.json out.csv"<<endl;
                return 0;
        }

        Person person;
        Address address;

        Csv_Saver csv_saver;
        //csv_saver.openOut("data.csv");
        //csv_saver.Close();
        csv_saver.Open(filename_out);

        Json_Importer json_importer;
        json_importer.Open(filename_in);

        json_importer.importIncomes(&person);
        json_importer.importCosts(&person);

        json_importer.importPerson(&person);

        json_importer.importAddress(&address);
        person.setAddress(address);


        Simulator simulate;
        simulate.addSaver(&csv_saver);
        simulate.addPerson(person);
        simulate.Simulate(1,15);
        simulate.closeSavers();
        return 0;
}
