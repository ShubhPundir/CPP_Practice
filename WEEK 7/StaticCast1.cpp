#include <iostream>
using namespace std;

// Performs a non-polymorphic cast
// Usually performs computation to change value
// convert from void* to any pointer type
// convert integers, floats to enums and vice-versa
// can UPCAST and DOWNCAST both

// NO CHECKS ARE PERFORMED during RUN-TIME to  guarantee that the
// object being converted is in fact a full object of the destination type

// Explicitly call a single-argument constructor or a conversion operator --> User-Defined Cast
// convert to rvalue reference
 
class A {};
class B : public A {};

int main(){
    A a; B b;

    A *p = 0;
    p = &b // UPCAST --> OKAY
    p = static_cast<A*>(&b); // static_cast
    p = (A*)(&b); // C-style --> OKAY

    B *q = 0;
    q = &a; // DOWNCAST --> ERROR
    q = static_cast<B*>(&a); // static_cast --> OKAY --> BUT NOT RECOMMENDED --> should use dynamic_cast
    q = (B*)(&a); // C-style --> OKAY

}