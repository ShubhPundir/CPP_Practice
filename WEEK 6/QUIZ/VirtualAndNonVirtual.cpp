#include <iostream>
using namespace std;

class Parent{
    public:
        void method1() {cout << "A";}
        virtual void method2(){ cout << "C";}
};

class Child : public Parent{
    public:
        virtual void method1() {cout << "B";}
        void method2() {cout << "D";}
};

int main(){
    Parent* p = new Child();
    p->method1();
    p->method2();
}