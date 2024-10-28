#include <iostream>
using namespace std;
class X { int *ptr; public:
explicit X(int *ptr = nullptr): ptr(ptr) { }
explicit operator bool() const { cout << "X::operator bool()" << ' '; return nullptr == ptr; }
};
int main() { X x1; X x2(new int(5));
// contextual conversions - permitted in spite of explicit
if (x1) cout << "NULL" << endl; // X::operator bool() NULL
cout << (x2? "NULL": "not-NULL") << endl; // X::operator bool() not-NULL
// non-contextual conversions - permitted only on absence of explicit
cout << (x1 == x2? "Equal": "not-Equal") << endl;
// Without explicit: x1 and x2 are implicitly converted to bool and compared by bool::operator==
// X::operator bool() X::operator bool() not-Equal
// With explicit: implicit conversion of x1 and x2 to bool are disallowed and hence operator== fails
// error: no match for operator== (operand types are X and X)
}