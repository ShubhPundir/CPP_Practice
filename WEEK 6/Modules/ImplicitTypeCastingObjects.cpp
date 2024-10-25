#include <iostream>
using namespace std;

class A { public: int i;};
class B { public: double d;};

int main(){
    A a; a.i = 10;
    B b; b.d = 21.132;

    A *p = &a;
    B *q = &b;

    cout << p << " " << q << endl;
    
    // a = b; // error
    // a = (A)b; // error

    // b = a; // error
    // b = (B)a; // error

    // p = q; // error
    // q = p; // error

    p = (A*)&b;
    q = (B*)&a;

    cout << p << " " << q << endl;
    cout << p->i << " " << q->d << endl; // GARBAGE values
}