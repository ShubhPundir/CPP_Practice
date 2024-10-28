#include <iostream>
using namespace std;

/*
    CountOnes(n) = CountOnes((n-1)/2) + 1 , n > 0 and odd
                 = CountOnes(n/2)         , n > 0 and odd
                 = 0                      , n = 0
*/


int CountOnes(int n){
    return (0==n) ? 0 : CountOnes(n/2) + (n%2); // n%2 is an adder of number of ones
    // if n is even --> n%2 = 0
    // if n is odd  --> n%2 = 1
}
// CountOnes(5) = 2 as (5)d = (101)b
// CountOnes(2) = 1 as (2)d = (010)b

int main(){
    auto Print = [](int n) {cout << "#(" << n << ") = " << CountOnes(n) << endl; };

    Print(0); Print(1); Print(2); Print(3); Print(1729);
}