#include <iostream>
#include <typeinfo>
using namespace std;

class C1 {public: virtual ~C1() {} };
class C2 : public C1 {};

int main(){
    C1 b; C2 d;
    C2 *dp = &d;
    C1 *bp = dp;
    C2 *dpp = (C2*)dp;

    cout << dp << " " << bp << " " << dpp << endl;
    
    cout << typeid(bp).name() << ", " <<  typeid(dpp).name() <<endl;
    cout << typeid(*bp).name() << ", " <<  typeid(*dpp).name() <<endl;
    cout << typeid(dp).name() << ", " <<  typeid(dpp).name() <<endl;
    cout << typeid(*dp).name() << ", " <<  typeid(*dpp).name() <<endl;


    cout << (typeid(bp).name() == typeid(dpp).name() );
    cout << (typeid(*bp).name() == typeid(*dpp).name() );
    cout << (typeid(dp).name() == typeid(dpp).name() );
    cout << (typeid(*dp).name() == typeid(*dpp).name() );
}