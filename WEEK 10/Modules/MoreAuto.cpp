#include <iostream>
using namespace std;

int main(){

    int a = 5;
    int& b = a;
    const int c = 7;
    const int& d = c;

    // Auto never deduces adornments like cv-qualifier or reference

    auto a_auto = a; // int
    auto b_auto = b; // int
    auto c_auto = c; // int
    auto d_auto = d; // int

    auto& b_ = a; // int&
    const auto c_ = a; // const int

    // However, decltype is too rad and accepts cv-qualifiers or references implicity!

    decltype(a) a_dt; // int
    decltype(b) b_dt; // int&
    decltype(c) c_dt; // const int
    decltype(d) d_dt; // const int&

}