#include <iostream>
#include <string>
using namespace std;

class Employee{
    string name; int salary;
    public: Employee(int _sal, string _name) : salary(_sal), name(_name) {}
    void update(int s, string na) const{
        ((Employee*)(this))->name = na;
        ((Employee*)(this))->salary = s;
        // DA FUQ, this works
        

        // const_cast<Employee*>(this)->name=na; // LINE-1
        // const_cast<Employee*>(this)->salary=s; // LINE-2
    }
    void showInfo() const{
        cout << name << " : "<< salary;
    }
};
int main(){
    const Employee e(1,"h");
    e.update(2,"r");
    e.showInfo();
    return 0;

}