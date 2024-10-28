#include <iostream>
#include <functional>
using namespace std;

int main(){
    // auto CountOnes = [](int n) { return (0==n)?0:CountOnes(n/2) + (n%2);};
    // ERROR --> use of 'CountOnes' befpre deduction of 'auto'

    std::function<int(int)> CountOnes;
    CountOnes = [&CountOnes] (int n) -> int { return (n==0) ? 0 : CountOnes(n/2) + (n%2);};

    auto Print = [CountOnes] (int n) {cout << "#(" << n << ") = " << CountOnes(n) << endl;};

    Print(0);
    Print(1);
    Print(2);
    Print(3);
    Print(1729);
}