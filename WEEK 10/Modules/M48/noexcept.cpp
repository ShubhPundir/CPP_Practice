#include <iostream>
#include <vector>
#include <math>
using namespace std;

// vector<double> my_computation(const vector<double>& v) noexcept{
//     vector<double> res(v.size()); // might throw
//     for(int i; i<v.size(); i++)
//         res[i] = sqrt(v[i]);
//     return res;
// }

template <class T>
void do_f(vector<T>& v ) noexcept (noexcept(f(v.at(0)))){
    // (noexcept(f(v.at(0)))) is true if f(v.at(0)) cannot throw 
    for(int i; i<v.size(); i++)
        v.at(i) = v.at(i) * 2;
}

int main(){
    
}