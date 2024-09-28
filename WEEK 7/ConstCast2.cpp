#include <iostream>
using namespace std;

struct type{
    type(): i(3){}
    void m1(int v) const {
        // this->i = v;
        const_cast<type*>(this)->i = v;
    }
    int i;
};

int main(){
    int i = 3;
    const int& cref_i = i;
    const_cast<int&>(cref_i) = 4;
    cout << "i: " << i << endl;

    type t;
    t.m1(4);
    cout << "type::i = " << t.i << endl;

    const int j = 3;
    int *pj = const_cast<int*>(&j); // creates a copy from &j and stores that 
    //                                  copy address in a int* that gets
    //                                  stored in *pj
    //                                  but changes done to either of the pointers --> &j and *pj
    //                                  offer different outputs
    //                                  THIS ONLY PROVIDES A NON-CONST VIEW OF THE OBJECT
    *pj = 4;
    cout << "pj =  " << pj << " , &j = " << &j <<endl;
    cout << "*pj = " << *pj << " , j = " << j <<endl; 

    void (type::*mfp)(int) const = &type::m1; // pointer to a member function
    const_cast<void(type::*)(int)>(mfp); // cannot convert a constant member function to a non-constant member function
    return 0;
}