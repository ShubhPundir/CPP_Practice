#include <iostream>
using namespace std;

class Base{
    public:
        Base() { cout << "B1 ";}
        Base& operator=(const Base& b) {cout << "Copy Assign - B1 "; return *this;}
        Base (const Base& b) {cout << "Copy Ctor - B1 ";}
        virtual ~Base(){ cout << "D1 ";}
};

class Derived : public Base{
    public:
        Derived() {cout << "B2 ";}
        virtual ~Derived() {cout << "D2 ";}
};

void fun(Base b){ // Copy Ctor is called at line-8 --> Base (const Base& b)
    cout << "F ";
}
int main(){
    Derived d;
    fun(d);
    return 0;
}
// B1 B2 F D1 D2 D1