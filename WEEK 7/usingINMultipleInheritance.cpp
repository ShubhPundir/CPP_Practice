#include <iostream>
using namespace std;

class Base1 {
    public:
        Base1(int a, int b) {}
        void f(int) { cout << "Base1::f(int) "; }
        void g() { cout << "Base1::g() "; }
};

class Base2 {
    public:
        Base2(int a, int b) {}
        void f(int) { cout << "Base2::f(int) "; }
        void g(int) { cout << "Base2::g(int) "; }
};
class Derived: public Base1, public Base2 {
    int k;
    public:
        Derived(int x, int y, int u, int v, int z) : Base1(x,y), Base2(u,v), k(z) {}
        using Base1::f; // Hides Base2::f
        using Base2::g; // Hides Base1::g
};

int main(){
    Derived c(1, 2, 3, 4, 5);
    c.f(5); // Base1::f(int)
    c.g(5); // Base2::g(int)
    c.Base2::f(3); // Base2::f(int)
    c.Base1::g(); // Base1::g()

}