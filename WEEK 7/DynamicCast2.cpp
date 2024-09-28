#include <iostream>
using namespace std;

class A {public: virtual ~A() { } };
class B : public A { };
class C {public: virtual ~C() { } };