#include <iostream>
#include <cmath>
using namespace std;
class Complex {
    double re_, im_;
    public:
    // Constructor
    Complex(double re, double im): re_(re), im_(im) { cout << "Complex ctor: "; print(); }
    // Copy Constructor
    explicit Complex(const Complex& c): re_(c.re_), im_(c.im_) { cout << "Complex copy ctor: "; print(); }
    // Copy assignment Constructor
    Complex& operator=(Complex& r) {
        re_ = r.re_;
        im_ = r.im_;
        cout << "c-assign ";
        return *this;
    }
    // Destructor
    ~Complex() { cout << "Complex dtor: "; print(); }
    double norm() { return sqrt(re_*re_ + im_*im_); }
    void print() { cout << "|" << re_ << "+j" << im_ << "| = " << norm() << endl; }
};
int main(){
    Complex c1(4.2, 5.3); // Constructor - Complex(double, double)
    Complex c2(c1); // Copy Constructor - Complex(const Complex&)
    Complex c3(0, 0);
    c3 = c1; // Copy assignment - Complex(const Complex&)
    c1.print();
    c2.print();
    // c3.print();
}
