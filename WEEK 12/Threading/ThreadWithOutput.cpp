#include <iostream>
#include <thread>
#include <vector>
#include <functional> // std::bind
using namespace std;

void f(vector<int>& v, int* res){
    cout << "In f() :";
    *res = 0;
    for(auto x: v){
        cout << " " << x;
        *res += x;
    }
    cout << endl << endl;
}

struct F{
    vector<int>& v; int *res;
    F(vector<int>& v, int *res) : v{v}, res{res}{
        *res = 0;
    }
    void operator()(){
        cout << "In F()(): ";
        for(auto x: v) {
            cout << " " << x;
            *res += x;
        }
        cout << endl;
    }
};

int main(){
    vector<int> myVec {2,3,5,7,11}; int res1, res2;
    std::thread t1{std::bind(f,myVec, &res1)};
    std::thread t2{F(myVec, &res2)};

    t1.join(); t2.join();
    cout << "HEHHE";
    cout << res1 << " " << res2;
}