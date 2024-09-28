#include <iostream>

class Base {
public:
    int x;
    virtual void display() { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
    int y;
    void display() override { std::cout << "Derived\n"; }
};

int main() {
    Derived d;
    d.x = 1;
    d.y = 2;

    // Base *pB = &d;
    // pB->display(); // Calls Derived's display

    Base &rb = d;
    rb.display(); // Calls Derived's display


    // Base b = d;  // Object slicing occurs here
    // b.display(); // Calls Base's display, not Derived's
}
