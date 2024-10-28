#include <iostream>
using namespace std;

struct B{
    void f(double){ cout << "B::f(double)" << endl;}
};

struct D : B{
    using B::f;
    void f(int) { cout << "D::f(int)" << endl;}
};

int main(){
    B b; b.f(2.1);
    D d; d.f(2.1);
}