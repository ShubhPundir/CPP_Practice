#include <iostream>
using namespace std;

int main(){
    int val = 0; int ref;

    struct check_f{
        int val_f;
        int& ref_f;
        check_f(int v, int& r): val_f(v), ref_f(r) { }
        void operator()(int param) const{
            cout << "val: " << val_f << ", ref: " << ref_f << ", param: " << param << endl;
        }
    };

    auto check = check_f(val, ref);

    
    ref = 2;
    check(4);
    val = 3;
    check(4);
    ref = 5;
    check(4);
}