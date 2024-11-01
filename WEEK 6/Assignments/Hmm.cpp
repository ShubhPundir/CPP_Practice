#include <iostream>
using namespace std;

class Base{
    int d;
    public:
        Base(int _d);
        virtual ~Base();        //LINE-1
        int get() { return d; }
};

class Derived : public Base{
    public:
        Derived(int _d);
        ~Derived();              //LINE-2
};
Base::Base(int _d) : d(_d) { cout << d << " "; }
Base::~Base(){ cout << 2*d << " "; }
Derived::Derived(int _d) : Base(_d) { cout << 3*_d << " "; }
Derived::~Derived() { cout << Base::get() << " "; }

int main(){
    int m = 10;
    // cin >> m;//
    Derived *t = new Derived(m);
    cout << endl;
    Base *t1 = t;
    cout << endl;
    delete t1;
    return 0;
}