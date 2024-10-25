#include <iostream>
using namespace std;

class A { public: int dataA_; };
class B : public A { public: int dataB_; };

int main(){
    A a;
    B b;
    a.dataA_ = 2;
    b.dataA_ = 3;
    b.dataB_ = 5;

    B *pb = (B*)&a; // Forced downcast
    
    cout << pb->dataA_ << endl; // prints 2
    cout << pb->dataB_ << endl; // Compilation okay. Prints garbage for 'dataB_' -- no 'dataB_' in 'A' object
}