#include <iostream>
using namespace std;

struct LHS{
    int i {10};
    int operator() () {return i;}
};

struct RHS{
    int i {10};
    int& operator() () {return i;}
};

template <typename T>
// decltype(auto) caller(T& rf){ // auto caller(T& rf) -> decltype(rf())
auto caller(T& rf) -> decltype(rf()){
    return rf();
}

int main(){
    LHS f1;
    RHS f2;
    cout << caller(f1) << " ";
    cout << (caller(f2) = 100);
    return 0;
}