#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
    protected: string name_;
    vector <Employee*> reports_;
    static vector<Employee*> staffs; // collection of all employee pointers/references
    public:
        Employee(const string& name) : name_(name) {}
        virtual void ProcessSalary() = 0; // pure virtual function 
        virtual ~Employee() {}
        void AddStaff(Employee* e) {staffs.push_back(e);}
        static void Print(){
            vector<Employee*>::const_iterator it; // iterator over staffs
            for(it = Employee::staffs.begin(); it < Employee::staffs.end(); ++it){       
                (*it)->ProcessSalary();
            }
        }
};

class Engineer : public Employee{
    public: 
        Engineer(const string &name): Employee(name) {AddStaff(this);}
        virtual void ProcessSalary() {cout << name_ << ": Process Salary for Engineer" << endl;}
};

class Manager : public Engineer{
    Employee* _reports_[10];
    public: 
        Manager(const string &name): Engineer(name) {}
        void ProcessSalary() {cout << name_ << ": Process Salary for Managaer" <<endl;}
};

class Director : public Manager{
    public: 
        Director(const string &name): Manager(name) {}
        void ProcessSalary() {cout << name_ << ": Process Salary for Director" <<endl;}
};

class SalesExecutive : public Employee{
    public:
        SalesExecutive(const string& name) : Employee(name) {AddStaff(this);}
        void ProcessSalary() {cout <<name_ << ": Process Salary for Sales Executive" <<endl;}
};

vector<Employee*> Employee::staffs;

int main()
{
    Engineer e1("Rohit"), e2("Kavita"), e3("Shambu");
    Manager m1("Kamla"), m2("Rajib");
    Director d("Ranjana");
    SalesExecutive s1("Hari"), s2("Bishnu");

    
    
    Employee::Print();


    return 0;
}