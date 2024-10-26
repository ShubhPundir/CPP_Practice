#include <algorithm>
#include <iostream>
using namespace std;

template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn){
    while(first!=last){
        fn(*first);
        ++first;
    }
    return fn;
}

struct adder : public unary_function<double, void> {
    adder() : sum(0) {}
    double sum;
    void operator()(double x) { sum += x;}
};

int main(){
    
}