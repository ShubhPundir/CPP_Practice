#include <iostream>
using namespace std;

int n = 7;
int rem(int m) {return m%n;}

struct remainder{
    int mod;
    remainder(int n) : mod(n){}
    int operator()(int m){
        return m%n;
    }
};

int main(){
    int result = rem(23);
    cout << result << " ";

    remainder remain(n);
    int res = remain(23);
    cout << res << " ";

    auto lambda = [n](int m) -> int {return m%n;};
    int lam_res = lambda(23);
    cout << lam_res;
}