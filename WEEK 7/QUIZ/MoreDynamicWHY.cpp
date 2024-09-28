#include <iostream>
using namespace std;

class A1{ public: virtual ~A1() {}};
class A2 : public A1 {};
class A3 : public A1 {};

int main(){
    A1 objA; A2 objB;

    A1 *pA = dynamic_cast<A1*>(&objB); // LINE-1
    pA == NULL ? cout << "0" : cout << "1";

    A2 *pB = dynamic_cast<A2*>(pA); // LINE-2
    pB == NULL ? cout << "0" : cout << "1";

    A3 *pC = dynamic_cast<A3*>(new A1); // LINE-3
    pC == NULL ? cout << "0" : cout << "1";

    // pC = dynamic_cast<A3*>(&objB); // LINE-4
    // pC == NULL ? cout << 0 : cout << 1;

    return 0;

}