#include <iostream>
using namespace std;

class classA{
    public:
        classA(const int& n) { cout << "base-lvalue: "<< n << endl;}
        classA(int&& n) { cout << "base-rvalue: "<< n << endl;}
};

class classB{
    classA a1, a2;
    public:
        template<typename T, typename U>
        classB(T&& n1, U&&n2) : a1(std::forward<U>(n1)), a2(std::forward<U>(n2)) {}
};

int main(){
    int i = 1;
    classB b1(i,2);
}