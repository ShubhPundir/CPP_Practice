#include <iostream>
using namespace std;

class A {public: virtual ~A() { } };
class B : public A { };
class C {public: virtual ~C() { } };

int main(){
    A a; B b; C c;
    try{
        B &rb1 = b;
        A &ra2 = dynamic_cast<A&>(rb1);
        cout << "Up-cast: Valid" << endl;

        A &ra3 = b;
        B &rb4 = dynamic_cast<B&>(ra3);
        cout << "Down-cast: Valid" << endl;
        // only time the downcast is valid is 
        // when the RHS pointer/reference was already pointing to LHS
        try{
            A &ra5 = a;
            B &rb6 = dynamic_cast<B&>(ra5);
        }catch(bad_cast e){
            cout << "Down-cast: Invalid: " << e.what() << endl;
        }

        try{
            A &ra7 = (A&)c;
            C &rc8 = dynamic_cast<C&>(ra7);
        }catch(bad_cast e){
            cout << "Unrelated-cast: Invalid: " << e.what() << endl; 
        }
    }catch(bad_cast e){
        cout << "Bad-Cast: " << e.what() << endl;
    }
}