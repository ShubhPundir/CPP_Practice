#include <iostream>
using namespace std;

// also called bit-wise copy, shallow copy, field-by-field copy, field-for-field copy or field copy 

// object created by simply copying the data of all variables of the original object
// works well if none of the variables are defined in heap/free store

// DOES NOT WORK WELL FOR POINTERS or other DYNAMICALLY created variables as the copied object refers to the same memory location

class A{
    int i_;
    int* p_;

        public: 
        A(int i, int* j): i_(i), p_(j){}
        ~A() {
            cout << "Dtor " << this << ": ";
            cout << "i_=" << i_ << " p_=" << p_ << " *p_=" << *p_ << endl;
            delete p_;
            cout << p_ <<endl;
            cout <<"THis is  visible"<<endl;
        }
};

int main(){
    int a = 5;
    int *point = &a;
    cout << point << " " << &a <<endl;;
    A a1(2,point);
    A a2(a1);
    cout << "&a1 = " << &a1 << "\n&a2 = " << &a2 << endl;
    return 0;
}