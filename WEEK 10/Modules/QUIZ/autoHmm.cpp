#include <iostream>
using namespace std;

int main(){
    int a = 1;
    const int b = 1;
    int& i1 = a;
    const int& i2 = b;

    auto x1 = i1;
    auto x2 = i2; // LINE-1

    cout << ++x1 << " " << ++x2 << " ";
    cout << i1 << " " << i2;
    return 0;

}