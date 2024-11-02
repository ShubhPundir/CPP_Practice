#include <iostream>
using namespace std;

class B {
    protected:
        B() { cout << "B "; }
        ~B() { cout << "~B "; }
};
class C : public B {
    public: // now this can be called as a data member
    // fuck all (ERROR) would have happened had this been declared as protected
        C() { cout << "C "; }
        ~C() { cout << "~C "; }
};
class D : private C {
    C data_;
    public:
        D() { cout << "D " << endl; }
        ~D() { cout << "~D "; }
};
int main() {
    D d;
}