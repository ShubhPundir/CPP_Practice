#include <iostream>
#include <string>
using namespace std;

// enum E_TYPE {Er, Mgr};

class Engineer{
    protected: string name_;
    // E_TYPE type_;
    public: 
    Engineer(const string &name): name_(name), type_(e) {}
    E_TYPE getType() {return type_;}
    virtual void ProcessSalary() {cout << name_ << ": Process Salary for Engineer" << endl;}
};

class Manager : public Engineer{
    Engineer *_reports_[10];
    // int i=12;
    // double d=123.3;
    public: 
    Manager(const string &name): Engineer(name) {}
    void ProcessSalary() {cout << name_ << ": Process Salary for Managaer" <<endl;}
};

int main()
{
    Engineer e1("Rohit"), e2("Kavita"), e3("Shambu");
    Manager m1("Kamla"), m2("Rajib");


    
    Engineer *staff[] = {&e1, &m1, &m2, &e2, &e3};

    // cout << sizeof(m1) << endl;
    // cout << sizeof(e1) << endl;


    for(int i = 0; i < sizeof(staff)/sizeof(Engineer*); ++i){
        // E_TYPE t = staff[i]->getType();

        staff[i]->ProcessSalary();
    }
    return 0;
}