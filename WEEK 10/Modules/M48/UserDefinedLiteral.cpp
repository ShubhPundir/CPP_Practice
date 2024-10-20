#include <iostream>
#include <string>
using namespace std;

string operator"" _s(const char *p, size_t n){
    cout << "Hell yea this is a string --> " << *p;
    return string(p,n);
}


template<class T>
void f(const T& a){
    cout << a << endl;
}

int main(){
    f("Hello");
    f("Hola"_s);
}