#include <iostream>
#include <string>
using namespace std;

class B{
    public:
        B() { cout << "B::B()" <<endl;}
        B(int a) {cout << "B::B(int)" << endl;}
        void f(int a) { cout << "B::f(int)" << endl;}
};

class D : public B{
    public:
    using B::f;
        void f(string a) { cout << "D::f(string)" << endl;}
        void f(int a) { cout << "D::f(int)" << endl;}
    using B::B;
        D(const string& a) { cout << "D::D(const string&)" <<endl;}
        D(int a) : B(a) {cout << "D::D(int)" << endl;}
};

int main(){
    B b(5);
    D d;
    D d1(2);
    D d2("shb");
    b.f(3);
    d1.f(1);
    d2.f("shb");
}