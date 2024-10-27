#include <iostream>
using namespace std;

int main(){
    int val = 0;
    int ref;

    auto check = [val, &ref](int param){
        cout << "val: " << val << ", ref: " << ref << ", param: " << param << endl;
    };

    ref = 2;
    check(4);
    val = 3;
    check(4);
    ref = 5;
    check(4);
}