#include <iostream>
#include <functional>
using namespace std;

int main(){
    std::function<int(int,int)> pow;
    pow = [&pow](int base, int exp) {return exp==0 ? 1 : base*pow(base, exp-1);};

    cout << pow(2,10) << endl; // 2^10
    cout << pow(2.14,10) << endl; // deduced to 2^10
}