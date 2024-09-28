#include <iostream>
using namespace std;


template<typename T1=char, typename T2=int> // LINE-1
class TempTest{
    T1 a_;
    T2 b_;

    public:
        TempTest(T1 a, T2 b){
            a_ = a;
            b_ = b;
        }
        void test(){
            cout << "a = "<< a_ << " b = " << b_ << endl;
        }

};

int main(){
    TempTest<int> t1(97,65);
    TempTest<> t2(97, 65);
    t1.test();
    t2.test();
    return 0;
}