#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
class Complex{
    private: T a, b;
    public:
        Complex(T a_, T b_) : a(a_), b(b_) {}
        T norm() { return sqrt(a*a + b*b);}
        void display() { cout << a << " + " << b << "_i" << endl; }
};

Complex<double> operator"" _i(long double d){
    return Complex<double> {0.0, static_cast<double>(d) };
}

int main(){
    Complex c{1.1,2.01};
    c.display();   

    auto z = 4.0_i;
    cout << z.norm();

}