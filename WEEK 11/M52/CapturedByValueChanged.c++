#include <iostream>
using namespace std;

// THIS CODE DOES NOT WORK

struct foo{
    foo() : i(0) {}
    void amazing() {
        lambda = [=]{i = 8;}();
        lambda();
    }
    int i;
};

foo f;
f.amazing();
cout << f.i;