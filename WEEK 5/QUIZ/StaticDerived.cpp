#include <iostream>
using namespace std;

class Base{
    protected:
        int number;
        static int counter;
        int counter;
    public:
        Base()
        {
            number = ++counter;
            cout << number << "-" << counter << ", ";
        }
};

class Derived1: public Base {
    public:
        Derived1() {
            ++counter;
            cout << counter << ", ";
        }
};

class Derived2: public Derived1 {
    public:
        Derived2() {
            ++counter;
            cout << counter << ", ";
        }
};

int Base::counter = 0;
// int counter=0;

int main()
{
    Derived2 dObj[2];
    return 0;
}