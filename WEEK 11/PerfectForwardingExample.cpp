#include <iostream>
using namespace std;
// overloaded functions for test
void test(const int& a) // lvalue ref
{ cout << "lvalue:" << a << endl; }
void test(int&& a) // rvalue ref
{ cout << "rvalue: " << a << endl; }

template <typename T>
class Data {
    T _data; public:
    Data(T data): _data(data) { cout << "ctor " << endl; }
    Data(Data&& obj) { cout << "mtor " << endl; }
    
    // class template
    void f1(T&& v) { // rvalue ref
        test(forward<T>(v));
    }
    template<typename U> // member fn. template
    void f2(U&& v) { // universal ref
        test(forward<U>(v)); //
    }
};

void g(int&& param) // simple fn - rvalue ref
{ test(forward<int>(param)); }

template<typename T>
void f(T&& param) // template fn - universal ref
{test(forward<T>(param)); }
int main() {
    int a = 20;
    //g(a); // cannot bind rvalue reference of
    // type int&& to lvalue of type int
    g(move(a)); // rvalue: 20
    f(a); // lvalue: 20
    g(move(a)); // rvalue: 20
    Data<int> d1(10); // ctor
    Data<int> d2(move(d1)); // mtor: rvalue ref
    //d1.f1(a); // cannot bind rvalue reference of
    // type int&& to lvalue of type int
    d1.f1(move(a)); // rvalue: 20
    d1.f2(a); // lvalue: 20
    d1.f2(move(a)); // rvalue: 20
}