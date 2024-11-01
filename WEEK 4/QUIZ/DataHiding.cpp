#include <iostream>
using namespace std;

int num = 5;

namespace space{int num = 15;}

int main(){
    using namespace space;
    
    // int num = 10;
    cout << num;
    // cout << ::num << " " << space::num << " " << num; // global namespace local
}