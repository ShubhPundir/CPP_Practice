#include <iostream>
using namespace std;

class X{
    X& operator=(const X&) = delete; // disallow copying
    X(const X&) = delete; // disallow Copy Constructor
};

struct Z{
    Z(long long);
    Z(int) = delete; // cannot initialize int
};

// deleted functions are defined, but cannot be used
// Most common application: prevent object copying:
class Widget {
    Widget(const Widget&) = delete; // declare and
    Widget& operator=(const Widget&) = delete; // make uncallable
};
