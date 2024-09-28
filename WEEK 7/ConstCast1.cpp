#include <iostream>
using namespace std;

// ONLY WAY TO get rid of constness and volatility
// Usually does not perform computation or change value

class A{
    int i_;
    public: A(int i): i_(i) {}
    int get() const {return i_;}
    void set(int j) {i_ = j;}
};

void print(char* str) {cout << str << endl;}

int main(){
    const char * c = "Sample Text";
    // print(c);  // ERROR
    // print(const_cast<char*>(c)); // OKAY
    // print((char*)(c)) // C-Style --> OKAY


    const A a(1);
    a.get();

    // a.set(112); // ERROR
    const_cast<A&>(a).set(112); // OKAY 
    // allows us to a create a non constant reference
    ((A&)a).set(112); // C-Style Cast --> OKAY

    // const_cast<A>(a).set(112); // NOT OKAY as cannot convert from 'const A' to A 
    ((A)a).set(112); // C-Style Cast --> OKAY

    return 0;    
}