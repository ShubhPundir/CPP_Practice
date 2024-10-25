#include <iostream>
using namespace std;

class A{
    public:
        void f(){ cout << "A::f()" << endl;}
};

class B : public A {
    public:
        using A::f;
        void f(int) { cout << "B::f(int)" << endl;}
};

int main(){
    B b;
    b.f(3);
    b.f();
}