#include <iostream>
using namespace std;

// template<typename T, typename Arg> T CreateObject(Arg& a){return T(a);} // binds lvalues
// template<typename T, typename Arg> T CreateObject(const Arg& a){return T(a);} // binds rvalues

template<typename T, typename Arg>
T CreateObject(Arg&& a){ // UNIVERSAL REFERENCE
    cout << "UNIVERSAL REF ";
    return(T(std::forward<Arg>(a)));
}

int main(){
    int five = 5; // lvalue
    int myFive = CreateObject<int>(five);
    cout << "myFive: " << myFive << endl;

    int myFive2 = CreateObject<int>(5);
    cout << "myFive: " << myFive << endl;
    
}