#include <iostream>
using namespace std;

class B{};
class A {
    public:
    A(int i = 0) {cout << "A::A(int)" <<endl;}
    A(const B&) {cout << "A::A(B&)"<<endl;}
};

int main(){
    A a;
    B b;
    int i = 5;

    cout <<"START SEEING FROM HERE TT" <<endl;

    // B==>A
    /* Here A, the final destination the variables b and i turn to, go through a constructor
    and get initialized according to the definition created by the user, this would not
    have been possible otherwise had the programmer not mention these*/
    a = b; 
    a = static_cast<A>(b);
    a = (A)b;

    // int==>A
    a = i;
    a = static_cast<A>(i);
    a = (A)i;   
    
    return 0;
}