#include <iostream>
using namespace std;

struct A { // converting ctor & operator 
    A(int) { } 
    A(int, int) { } // C++11 
    operator bool() const 
    { return true; } 
};
struct B { // explicit converting ctor & operator
    explicit B(int) { }
    explicit B(int, int) { }
    explicit operator bool() const { return true; }
};
int main() {
    A a1 = 1; // OK: copy-initialization selects A::A(int)
    A a2(2); // OK: direct-initialization selects A::A(int)
    A a3 {4, 5}; // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1; // OK: explicit cast performs static_cast
    cout << (a1) << endl; // OK: A::operator bool()
    
    bool na1 = a1; // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization
    cout << na1 << " " << na2 << endl;

    // B b1 = 1; // error: copy-initialization does not consider B::B(int)
    B b2(2); // OK: direct-initialization selects B::B(int)
    B b3 {4, 5}; // OK: direct-list-initialization selects B::B(int, int)
    // B b4 = {4, 5}; // error: copy-list-initialization does not consider B::B(int,int)
    
    B b5 = (B)1; // OK: explicit cast performs static_cast
    if (b2); // OK: B::operator bool()
    // bool nb1 = b2; // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b2); // OK: static_cast performs direct-initialization
    cout << nb2;
}