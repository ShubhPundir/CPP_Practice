#include <iostream>
using namespace std;

class B;
class A{
    int i_;
    public:
    A() {}
    // A(int i = 0) : i_(i) {cout<< "A::A(i)" << endl;}
    operator int() {cout << "A::operator int()" << endl; return i_;}
};

class B{
    public:
    operator A() {cout << "B::operator A()" << endl; return A();}
};

int main(){
    A a; B b; int i = 5;
    cout <<"START SEEING FROM HERE TT" <<endl;

    // B==>A
    a = b;
    a = static_cast<A>(b);
    a = (A)b;

    // A==>int
    i = a;
    i = static_cast<int>(a);
    i = (int)a;


}