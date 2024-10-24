#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double re, im;
public:
    // Constructor
    Complex(double re_, double im_) : re(re_), im(im_) {
        cout << "Ctor(" << this->re << "," << this->im << ")" << endl;
    }
    
    // Default constructor (needed for the array)
    Complex() : re(0), im(0) {
        cout << "Default Ctor(" << this->re << "," << this->im << ")" << endl;
    }
    
    // Destructor
    ~Complex() {
        cout << "Dtor(" << this->re << "," << this->im << ")" << endl;
    }

    // Method to calculate norm
    double norm() {
        return sqrt(re * re + im * im);
    }

    // Method to print the complex number and its norm
    void print() {
        cout << "|" << re << " + " << im << "i| = " << this->norm() << endl;
    }
};

int main() {
    unsigned char buf[100];  // Pre-allocated buffer for placement new

    // Dynamically allocating a single Complex object
    Complex* pc = new Complex(4.2, 5.3);

    // Dynamically allocating an array of Complex objects
    Complex* pd = new Complex[2];  // Calls the default constructor

    // Using placement new to create a Complex object in the buffer
    Complex* pe = new (buf) Complex(2.6, 3.9);
    // creates object in a specific pre-allocated memory location (buf in this case).

    // Calling the print function
    pc->print();
    pd[0].print();  // These will print the default values (0, 0)
    pd[1].print();  // Same here (0, 0)
    pe->print();

    // Freeing dynamically allocated memory
    delete pc;  // Deallocate single object
    delete[] pd;  // Deallocate array of objects

    // Manually calling destructor for object created with placement new
    pe->~Complex();

    return 0;
}
