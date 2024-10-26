#include <iostream>
using namespace std;

struct type{
    type():i(3) {}
    void m1(int v) const {
        // this->i = v;
        // already gives a compilation error as void m1() is declared const
        // hence assumes the this pointer will be invoked by a const struct type as well
        // although, both const and non const variables of type can invoke the method m1()
        const_cast<type*>(this)->i = v; 
    }
    int i;
};

int main(){
    int i = 3;
    const int &cref_i = i;
    const_cast<int&>(cref_i) = 4;

    cout << "i = " << i << endl;

    type t;
    t.m1(4);
    cout << "type::i = " << t.i << endl;

    int j = 3; // const int j = 3; will have different results as 3 4 in LINE - 31
    int *pj = const_cast<int*>(&j);
    *pj = 4;
    cout << &j << " " << pj << endl;
    cout << j << " "<< *pj << endl; // LINE - 31



    return 0;   
}