#include <string>
#include <vector>
#include "macros.h"
#include "Simulator.h"
#include "Person.h"
#include <iostream>

using namespace std;

string space="============";

Simulator::Simulator(){
        cout<<"Creating empty simulator"<<endl;
}
void Simulator::Simulate(ui start_month, ui end_month){
        cout<<"Executing simulation..."<<endl;
        for(int i=0; i<(int)list_of_people.size(); i++) {

                cout<<space<<"PERSON"<<space<<endl;
                cout<<"Reading "<<i+1<<" person:"<<endl;
                list_of_people[i].displayData();

                string header_of_data_to_save=list_of_people[i].getName()+" "+list_of_people[i].getSurname()+"\nAge:"+
                                               to_string(list_of_people[i].getAge())+"\nSex:"+list_of_people[i].getSex()+"\nAddress:"+list_of_people[i].getAddress()+"\nmonth;costs_sum;incomes_sum;earn;\n";
                for(int j=0; j<(int)list_of_savers.size(); j++)
                        list_of_savers[j]->saveString(header_of_data_to_save);

                for(ui actual_month=start_month; actual_month<=end_month; actual_month++) {

                        cout<<space<<"INCOMES FOR MONTH: "<<actual_month<<space<<endl;
                        cout<<"All incomes:"<<endl;

                        list_of_people[i].displayIncomesForMonth(actual_month);

                        cout<<space<<"COSTS FOR MONTH: "<<actual_month<<space<<endl;
                        list_of_people[i].displayCostsForMonth(actual_month);

                        int costs_summary=list_of_people[i].getCostSummary(actual_month, actual_month);
                        cout<<"COSTS SUMMARY:"<<costs_summary<<endl;

                        int incomes_summary=list_of_people[i].getIncomeSummary(actual_month, actual_month);
                        cout<<"INCOMES SUMMARY:"<<incomes_summary<<endl;

                        cout<<space<<"SAVING"<<space<<endl;
                        string data_to_save=to_string(actual_month)+";"+to_string(costs_summary)+";"+to_string(incomes_summary)+";"+to_string(incomes_summary-costs_summary)+";\n";
                        for(int j=0; j<(int)list_of_savers.size(); j++)
                                list_of_savers[j]->saveString(data_to_save);
                }
        }

}
void Simulator::addSaver(Saver *saver){
        list_of_savers.push_back(saver);
}

void Simulator::addPerson(Person &person){
        list_of_people.push_back(person);
}

void Simulator::closeSavers(){
        for(int j=0; j<(int)list_of_savers.size(); j++)
                list_of_savers[j]->Close();
}
