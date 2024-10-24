#include <iostream>
using namespace std;
class Complex {
    double re, im; public:
    explicit Complex(double r = 0, double i = 0) : re(r), im(i) { } // No implicit conversion is allowed
    void display() { cout << re << " +j " << im << endl; }
    friend Complex operator+(const Complex &a, const Complex &b) { // Overload 1
        return Complex(a.re + b.re, a.im + b.im);
    }
    friend Complex operator+(const Complex &a, double d) { // Overload 2
        Complex b(d); // Create temporary object
        return a + b; // Use Overload 1
    }
    friend Complex operator+(double d, const Complex &b) { // Overload 3
        Complex a(d); // Create temporary object
        return a + b; // Use Overload 1
    }
    friend ostream& operator<<(ostream&, const Complex&);
};

ostream& operator<<(ostream& os, const Complex& a){
    os << a.re << " +j" << a.im << endl;
    return os;
}

int main() {
    Complex d1(2.5, 3.2), d2(1.6, 3.3), d3;
    
    // no need of d3.display() anymore
    // lesgo
    d3 = d1 + d2; cout << d3; // d3 = 4.1 +j 6.5. Overload 1
    d3 = d1 + 6.2; cout << d3; // d3 = 8.7 +j 3.2. Overload 2
    d3 = 4.2 + d2; cout << d3; // d3 = 5.8 +j 3.3. Overload 3
}