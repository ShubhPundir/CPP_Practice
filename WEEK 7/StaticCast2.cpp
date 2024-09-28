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
    a = b;
    a = static_cast<A>(b);
    a = (A)b;

    // int==>A
    a = i;
    a = static_cast<A>(i);
    a = (A)i;   
    
    return 0;
}