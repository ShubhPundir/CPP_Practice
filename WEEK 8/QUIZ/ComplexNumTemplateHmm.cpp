#include <iostream>
using namespace std;

class complex_num{
    int re_, im_;
    public:
        complex_num(int re=0, int im=0) : re_(re), im_(im) {}
        int getRe() {return re_;}
        int getIm() {return im_;}
        void setRe(int re) {re_=re;}
        void setIm(int im) {im_=im;}
        friend std::ostream& operator<<(std::ostream& os, const complex_num& c);
};

std::ostream& operator<<(std::ostream& os, const complex_num& c){
    os << c.re_ << " + i"<< c.im_ << std::endl;
    return os;    
}

template <class T>
T add(T x, T y){
    return x+y;
}

template <>
complex_num add(complex_num x, complex_num y){
    complex_num t;
    t.setRe(x.getRe() - y.getRe());
    t.setIm(x.getIm() + y.getIm());
    return t;
}

int main(){
    complex_num c1(10,10);
    complex_num c2(5,15);
    cout << add<double>(5.5,1.4) << ", ";
    cout << add<int>(5,4) << ", ";
    cout << add<complex_num>(c1,c2);
    return 0;
}