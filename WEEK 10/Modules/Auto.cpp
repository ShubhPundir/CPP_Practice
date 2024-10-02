#include <iostream>
using namespace std;

int main(){

    auto x1 = 10; // int x1 = 10;
    
    map<int,string> m;
    auto it = m.begin(); // map<int,string>::iterator it = m.begin();

    const auto *x2 = &x1; // const int *x2 = &x1;
    const auto& i2 = m; // const map<int,string>& i2 = m;

    

}