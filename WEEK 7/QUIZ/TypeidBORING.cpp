#include <iostream>
#include <typeinfo>
using namespace std;

class C1 {public: virtual ~C1() {} };
class C2 : public C1 {};

// C1 --> base
// C2 --> derived

int main(){
    C1 b; C2 d;
    C2 *dp = &d;
    C1 *bp = dp;
    C2 *dpp = (C2*)dp;

    cout << dp << ", " << bp << ", " << dpp << endl;
    // cout << *dp << ", " << *bp << ", " << *dpp << endl;
    
    cout << typeid(bp).name() << ", " <<  typeid(dpp).name() <<endl; // C1 and C2
    cout << typeid(*bp).name() << ", " <<  typeid(*dpp).name() <<endl; // *bp is  dp
                                                                       // *dpp is dp
    cout << typeid(dp).name() << ", " <<  typeid(dpp).name() <<endl; // C2 and C2
    cout << typeid(*dp).name() << ", " <<  typeid(*dpp).name() <<endl; // *dp is &d
                                                                       // *dpp is (C2*)dp which essentialy is &d


    cout << (typeid(bp).name() == typeid(dpp).name() ); // P2C1, P2C2
    cout << (typeid(*bp).name() == typeid(*dpp).name() ); // 2C2, 2C2
    cout << (typeid(dp).name() == typeid(dpp).name() ); // P2C2, P2C2
    cout << (typeid(*dp).name() == typeid(*dpp).name() ); // 2C2, 2C2
}