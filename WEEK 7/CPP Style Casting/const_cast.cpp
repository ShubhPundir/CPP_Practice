#include <iostream>
using namespace std;

class A{
    int i;
    public:
        A(int i_) : i(i_) { }
        int get() const{ return i;}
        void set(int i_) {i = i_;}
};
void print(char *str) { cout << str;}

int main(){
    const char *c = "sample text";
    // print(c); // ERROR --> Cannot convert argument from 'const char*' to 'char*'
    print(const_cast<char*>(c)); // OKAY
    print((char*)(c)); // C-STYLE okay

    const A a(1);
    a.get();
    // a.set(4);
    const_cast<A&>(a).set(5); // OKAY
    ((A&)a).set(5); // C-STYLE okay

    // const_cast<A>(a).set(5); // ERROR --> cannot convert 'const A' to 'A'
    ((A)a).set(5); // C-STYLE okay


    void (type::*mfp)(int) = &type::m1; // pointer to a member function
    // <return type> <struct/class::name of function pointer> <parameter> const 
    
}