#include <iostream>
using namespace std;

class Base{
    public:
        Base() {}
        ~Base() {}
    private: 
        Base(const Base& obj){}
        Base& operator=(const Base&);
};

class Derived:public Base {
    int data;
    public:
        Derived() {}
    
        Derived(const int& data_) : data(data_) {}

        void print() {
            cout << data << " ";
        }
};

int main()
{
    Derived d1(30);
    Derived d2(40);
    d1 = d2;
    d1.print();
    d2.print();

    return 0;
}