#include <iostream>
using namespace std;

class Base {
    protected: int i;
    public:
        Base(int a) : i(a) {}
        virtual void display() { cout << "I am Base class object, i = " << i << endl; }
        virtual ~Base() {}
};
class Derived : public Base {
    int j;
    public:
        Derived(int a, int b) : Base(a), j(b) { }
        virtual void display() { cout<< "I am Derived class object, i = " << i << ", j = " << j <<endl; }
        ~Derived() {}
};
// Global method, Base class object is passed by value
void somefunc (Base &obj) { obj.display(); } // now slicing won't occur as it is passed by reference
// had it been void somefunc(Base obj) --> SLICING WOULD HAVE ALWAYS HAPPENED
int main() {
    Base b(33);
    Derived d(45, 54);
    somefunc(b);
    somefunc(d); // Object Slicing, the member j of d is sliced off
}