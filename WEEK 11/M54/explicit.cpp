#include <iostream>
#include <string>
using namespace std;
struct Y { 
    explicit Y(const string&) { cout << "Y(string)" << '\n'; } 
};

struct X {
    explicit X(int i) { cout << "X(int)" << '\n'; } // C++03 & C++11
    explicit operator int() const { cout << "X::operator int()" << '\n'; return 0; } // C++11 only
    explicit operator Y() const { cout << "X::operator Y()" << '\n'; return Y("ppd"); } // C++11 only
};
void fx(const X&){
    cout << "fx()" << '\n';
} // checker function for conversion to X
void fi(int) { 
    cout << "fi()" << '\n'; 
} // checker function for conversion to int
void fy(const Y&) { 
    cout << "fy()" << '\n';
} // checker function for conversion to Y

int main() {
    int i { 5 }; X x { 1 }; // X(int)

    // fx(i); // X(int) fx(): error with explicit X::X(int)
    fx(static_cast<X>(i)); // X(int) fx()
    cout << endl;
    
    // fi(x); // X::operator int() fi(): error with explicit X::operator int()
    fi(static_cast<int>(x)); // X::operator int() fi()
    cout << endl;
    
    // fy(x); // X::operator Y() Y(string) fy(): error with explicit X::operator Y()
    fy(static_cast<Y>(x)); // X::operator Y() Y(string) fy()
}