#include <iostream>
using namespace std;

class Widget{
    public:
        Widget() {cout << "Default Ctor" <<endl;}
        Widget(const Widget&) {cout << "Copy Ctor" << endl;}
        Widget(Widget&&) noexcept {cout << "Move Ctor" << endl;}
        Widget& operator=(const Widget&) {cout << "Copy Assignment operator" << endl; return *this;}
        Widget& operator=(Widget&&) noexcept {cout << "Move Assignment operator" << endl; return *this;};
        ~Widget() {cout << "Dtor" << endl;}
};

int main() {
    // Creating a widget object using the default constructor
    Widget w1;

    // Copy constructor
    Widget w2 = w1;  // Copying w1 into w2

    // Move constructor
    Widget w3 = std::move(w1);  // Moving w1 into w3

    // Copy assignment operator
    Widget w4;
    w4 = w2;  // Copy assigning w2 into w4

    // Move assignment operator
    Widget w5;
    w5 = std::move(w3);  // Move assigning w3 into w5

    return 0;
}
