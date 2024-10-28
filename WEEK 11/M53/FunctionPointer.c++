#include <iostream>
using namespace std;

void f(void(*fp)(int)) { return fp(1);}
void g(void(*fp)(double)) { return fp(2.2);}

int main(){

    auto op = [](auto x) {cout << "x=" << x << endl; };

    f(op);
    g(op);
    
}