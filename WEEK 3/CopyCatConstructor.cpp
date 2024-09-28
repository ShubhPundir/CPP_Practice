#include <iostream>
using namespace std;

class Complex{
    public:
    double re_,im_;
    Complex(double re, double im): re_(re), im_(im)
    {
        cout << "Ctor"  << endl;
        print();
    }
    // Complex(const Complex& c) : re_(c.re_), im_(c.im_)
    // {
    //     cout << "C-Ctor"  << endl;
    //     print();
    // }
    ~Complex()
    {
        cout << "Dtor" << endl;
        print();
    }
    void print(){
        cout << "|" << re_ << "+j" << im_ << "|" <<endl;
    }
};


int main()
{
    Complex c1(4,5);
    // const char * c = c1; 
    cout << "C1 created now"  << endl;
    
    Complex c2(c1);
    cout << "C2 created now" <<endl;
    
    c2.im_ = 90;
    Complex c3 = c2;
    cout << "C3 created now" <<endl;
    return 0;
}