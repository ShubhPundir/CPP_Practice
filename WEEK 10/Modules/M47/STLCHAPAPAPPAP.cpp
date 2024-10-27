#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
using namespace std;

int main(){

    vector<double> v = {1,2,3.14,5.2}; // vector of doubles
    list<pair<string, string>> languages = {
        {"Shubh", "Englihs"},
        {"Akshat", "French"},
        {"Amartya", "Malyallam"}
    };

    map<vector<string>, vector<int>> people_years = {
        {{"Maurice", "Vincent"}, {1993, 1997}},
        {{"Shubh", "Akshat", "Amartya"}, {2004, 2004, 2004}},
        {{"Shubh", "Shivesh", "Toshan"}, {2004, 2004,2003}}
    };

    people_years.insert({{"Johnny","B","Goode"},{1956}});

    for (const auto& entry : people_years) {
        cout << "People: ";
        for (const auto& person : entry.first) {
            cout << person << ", ";
        }
        cout << "--> Years: ";
        for (const auto& year : entry.second) {
            cout << year << ", ";
        }
        cout << endl;
    }
    
}