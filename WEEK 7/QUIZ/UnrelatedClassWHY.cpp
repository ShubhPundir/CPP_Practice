#include <iostream>
using namespace std;

class A{
    string a = "C++";
};
class B{
    public: string b = "Java";
};

int main(){
    A u;
    // B *v = reinterpret_cast<B*>(&u);
    B *v = (B*)(&u);
    cout << v->b; 
    return 0;

}