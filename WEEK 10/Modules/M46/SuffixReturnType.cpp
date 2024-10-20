// also called trailing return type
#include <iostream>
using namespace std;

// template<class T, class U>
// decltype (*(T*)(0)) * (*(U*)(0)) mul(T x, U y){
    // instantiating a null pointer of both types --> (T*)(0)
    // and then dereferncing them with a prefix *
    // and multiplying them

    // doesn't work as in most compilers dereferencing a nullptr is invalid
//     return x*y;
// }

template<class T, class U>
auto multiply(T x, U y) -> decltype(x*y){
    return x*y;
}

template<class T, class U>
auto multiply2(T x, U y){
    return x*y;
}

template<class T, class U>
decltype(auto) multiply3(T x, U y){
    return x*y;
}

int main(){
    int a = 2; double b = 4.3;

    // cout << mul(a,b) << endl;
    cout << multiply(a,b) << endl;
    cout << multiply2(a,b) << endl;
    cout << multiply3(a,b) << endl;

}