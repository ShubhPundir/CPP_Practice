#include <iostream>
using namespace std;

int main(){
    auto power = [](auto self, auto base, int exp) -> decltype(base) {
        return exp==0 ? 1 : base * self(self,base,exp-1);
    };

    auto pow = [power] ( auto base, int exp) -> decltype(base) {
        return power(power, base, exp);
    };
    cout <<"TEST" << endl;

    cout << power(power,2,10) << endl;

    cout << pow(2,10) << endl;

    cout << "YO";
}