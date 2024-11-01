#include <iostream>
#include <functional>
using namespace  std;

int func(int x1, int x2, int x3, const int& x4){
    return x1 - (x2 + x3 + x4);
}

int main(){
    using namespace std::placeholders;
    int i = 5, j = 3;
    auto f = std::bind(func, _2, i, _1, std::cref(j));
    cout << f(1,2,3) << " ";
    i = j = -10;
    cout << f(1,2,3);

}