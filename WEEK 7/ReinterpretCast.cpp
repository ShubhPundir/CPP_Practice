// reinterpret cast converts any pointer type to another, even of unrelated classes
// The operation result is a simple binary copy of the value from one pointer to the other
// It can also cast pointers to or from integer types
// The only guarantee is that a pointer cast to an integer type large enough to fully contain it

// leads to platform specific representation as it depends upon the machine --> BINARY LEVEL

// (such as intptr_t) --> is guaranteed to be able to be cast back to a valid pointer
// The conversions that can be performed by reinterpret_cast but not by static_cast are low-level operations
// based on reinterpreting the binary representations of the types,
// which on most cases results in code which is system-specific, and thus non-portable

#include <iostream>
using namespace std;

class A{};
class B{};

int main(){

    long i = 2;
    double d = 3.7, *pd = &d;
    
    i = pd; // IMPLICIT --> ERROR
    i = reinterpret_cast<long>(pd); // OKAY
    i = (long)pd; // C-Style --> okay
    cout << pd << " " << i << endl;

    A *pA;
    B *pB;

    pA = pB; // IMPLICIT --> ERROR
    pA = reinterpret_cast<A*>(pB); // OKAY
    pd = (A*)pB; // C-Style --> OKAY

    return 0;

}