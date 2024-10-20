#include <iostream>
using namespace std;

template<class T, class U>
decltype (*(T*)(0)) * (*(U*)(0)) mul(T x, U y){
    // doesn't work on most compilers as dereferncing a nullptr is invalid
    return x * y;
}

int main(){
    int a = 2;
    double b = 4.3;

    cout << mul(a, b) << endl;  // Output will be 8.6
}
