#include <iostream>
using namespace std;

class A{};
class B : public A{};

A *pa = 0;
B*pb = 0;
void *pv = 0

pa = pb; // UPCAST : OKAY
pb = pa; // DOWNCAST : NOT OKAY --> ERROR

pv = pa; // OKAY
pv = pb; // OKAY

pa = pv; // ERROR
pb = pv; // ERROR
