#include <iostream>
using namespace std;

class employee{
    string name; int salary;
    public:
        employee(int sal, string n) : salary(sal), name(n) {}
        void update(int s, string na) const {
            const_cast<employee*>(this)->name = na;
            const_cast<employee*>(this)->salary = s;
        }
        void showInfo() const{
            cout << name << " : " << salary; 
        }
};

int main(void){
    const employee e(1,"HAHAHAH");
    e.update(2,"ROFLFLLF");
    e.showInfo();
}