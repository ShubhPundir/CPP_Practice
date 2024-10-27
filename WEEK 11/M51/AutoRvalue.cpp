#include <iostream>
using namespace std;

int calcVal(){ return 12;}
int x;

int main(){
    
    auto&& v1 = calcVal(); // deduces type from rvalue => v1's type is int&&
    auto&& v2 = x; // deduces type from lvalue => v1's type is int&

    // HOWEVER decltype()&& does not behave like universal references as it does not use
    // template type deduction

    cout << typeid(v1).name() << " " << typeid(v2).name();
}