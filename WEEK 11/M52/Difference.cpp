#include <iostream>
using namespace std;

int function(int a) { return a + 3;}
class Functor{
    public:
        int operator()(int a) { return a + 3;}
};
auto lambda = [](int a){return a + 3;};
// [capture list] (parameter list) -> return-type {function body}

int main(){
    Functor fun;
    cout << function(5) << fun(5) << lambda(5);
}