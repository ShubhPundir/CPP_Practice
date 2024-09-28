#include <iostream>
using namespace std;

// DEEP copy or it's variants known as Lazy Copy or Copy-on-Write
// object is created by copying all data of all variables EXCEPT the ones on heap
// allocates similar memory resources with the same value to the object

// NEED TO EXPLICITY define the copy constructor and assign dynamic memory as required
// required to dynamically allocate memory to the variables in the other constructors


class A{
    int i_;
    int* p_;
    
        public: 
        A(int i, int j): i_(i), p_(new int(j)){}
        A(const A& a): i_(a.i_), p_(new int(*a.p_)){}
        ~A() {
            cout << "Dtor " << this << ": ";
            cout << "i_ = " << i_ << "p_ = " << p_ << " *p_ = " << *p_ << endl;
            delete p_;
            // cout << "PLEASE PLEASE PLEASE " << endl;
        }
};

int main(){
    int a = 5;
    int *point = &a;
    // cout << point << " " << &a <<endl;;
    A a1(2,3);
    A a2(a1);
    cout << "&a1 = " << &a1 << "\n&a2 = " << &a2 << endl;
    return 0;
}