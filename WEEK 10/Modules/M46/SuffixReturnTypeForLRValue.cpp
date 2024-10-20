#include <iostream>

// returns prvalue --> pure Rvalue
// plain auto never deduces to a reference
template<typename T> auto foo(T& t) {return t.value();}

// returns lvalue
// auto& alawys deduces to a reference
template<typename T> auto& bar(T& t) {return t.value();}

template<typename T>
decltype(auto) foobar(T& t){
    // return prvalue if t.value() is an rvalue
    // return lvalue if t.value() is an lvalue
    return t.value();
}

int main(){
    struct A {
        int i=10;
        int& value() {return i;}
    } a;

    struct B {
        int i=20;
        int value() {return i;}
    } b;

    // foo(a) = 15; // not okay as a.value() return an int& (lvalue) while foo returns an rvalue reference
    // foo(b); // OKAY

    bar(a) = 15; // OKAY
    // bar(b); // not okay as b.value() returns an int (rvalue) and bar returns a lvalue reference 


    foobar(a) = 15;
    foobar(b);

}
