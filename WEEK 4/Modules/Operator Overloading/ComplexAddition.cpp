#include <iostream>
using namespace std;

class Complex{
    double re, im;
    public:
        Complex(double a=0.0, double b=0.0) : re(a), im(b) { }
        ~Complex() { }
        void display();
        Complex operator+(const Complex& c){
            Complex r;
            r.re = re + c.re;
            r.im = im + c.im;
            return r;
        }
};

void Complex::display(){
    cout << re;
    cout << " +j" << im << endl;
}

int main(){
    Complex c1(1,2) , c2(1,2), c3;
    c3 = c1 + c2;
    cout << "Sum = ";
    c3.display();

}