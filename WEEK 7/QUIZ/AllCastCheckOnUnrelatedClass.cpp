#include <iostream>
using namespace std;

class Test1 {};
class Test2 {};

int main(){
    Test1* tst1 = new Test1;
    Test2* tst2 = new Test2;

    tst2 = reinterpret_cast<Test2*>(tst1);
    return 0;
}
