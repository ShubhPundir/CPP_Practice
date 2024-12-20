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

    // However, decltype is too RAD and accepts cv-qualifiers or references implicity!

    decltype(a) a_dt = a; // int
    decltype(b) b_dt = b; // int&
    decltype(c) c_dt = c; // const int
    decltype(d) d_dt = d; // const int&

    decltype(auto) d_hmm = d; // int

    decltype(d_hmm)::lmaoanythingworkshere_waisebhiwillbeanerrorLOL;
}