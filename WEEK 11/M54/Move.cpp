#include <iostream>
using namespace std;

class X {
    public:
    X() { std::cout << "Ctor "; }
    X(const X&) { std::cout << "C-Ctor "; }
    X& operator=(const X&) { std::cout << "C= "; return *this; }
    X(X&&) { std::cout << "Mtor "; }
    X& operator=(X&&) { std::cout << "M= "; return *this; }
    ~X() {}
};

int main(){
    X x1;
    X x2 {x1};
    x1 = x2;
    X x3 {std::move(x1)};
    x2 = std::move(x3);
}