// also called trailing return type
#include <iostream>
using namespace std;

// template<class T, class U>
// (decltype (*(T*)(0)) * (*(U*)(0))) mul(T x, U y){
//     return x*y;
// }

template<class T, class U>
auto multiply(T x, U y) -> decltype(x*y){
    return x*y;
}

int main(){
    int a = 2; double b = 4.3;

    // cout << mul(a,b) << endl;
    cout << multiply(a,b) << endl;


}