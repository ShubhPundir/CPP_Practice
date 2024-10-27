#include <iostream>
class Data { int i; public: Data(): i(0) {} }; // a UDT
void g(const int&) { std::cout << "int& in g" << "; "; } // binds with lvalue parameter
void g(int&&) { std::cout << "int&& in g" << "; "; } // binds with rvalue parameter
void h(const Data&) { std::cout << "Data& in h" << std::endl; } // binds with lvalue parameter
void h(Data&&) { std::cout << "Data&& in h" << std::endl; } // binds with rvalue parameter

template<typename T1, typename T2>
void f(T1&& p1, T2&& p2) { // universal ref. gets lvalue or rvalue from arg by template type deduction
    g(std::forward<T1>(p1)); // std::forward forwards lvalue arg to lvalue param and
    h(std::forward<T2>(p2)); // rvalue arg to rvalue param
}
int main() { int i {0}; Data d;
    f(i, d); // (lvalue, lvalue) binds with int& in g; Data& in h
    f(std::move(i), d); // (rvalue, lvalue) binds with int&& in g; Data& in h
    f(i, std::move(d)); // (lvalue, rvalue) binds with int& in g; Data&& in h
    f(std::move(i), std::move(d)); // (rvalue, rvalue) binds with int&& in g; Data&& in h
}
// Lvalue arg passed to p1 ) g(const int&) receives Lvalue
// Rvalue arg passed to p1 ) g(int&&) receives Rvalue
// Lvalue arg passed to p2 ) h(const Data&) receives Lvalue
// Rvalue arg passed to p2 ) h(Data&&) receives Rvalue