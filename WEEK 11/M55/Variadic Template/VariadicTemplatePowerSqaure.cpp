#include <iostream>
using namespace std;

template <typename T> T square(T t){ return t*t; }

template <typename T>
double power_sum(T t){
    cout << __PRETTY_FUNCTION__ << endl;
    return t;
} // BASE CASE

template <typename T, typename ...Rest>
double power_sum(T t, Rest ...rest){
    cout << __PRETTY_FUNCTION__ << endl;
    return t + power_sum(square(rest...));
}

int main(){
    int result = power_sum(2,4,6);
    // 2 + power_sum(square(rest)...);
    // 2 + power_sum(square(4), square(6));
    // 2 + (square(4) + power_sum(square(rest)...))
    // 2 + (square(4) + power_sum(square(square(6)));
    // 2 + (square(4) + (square(square(6))))
    cout << result;
}

// Expands to: 2 + power_sum(square(4), square(6))
// Which becomes: 2 + power_sum(16, 36)
// Expands further: 2 + (16 + power_sum(square(36)))
// Which becomes: 2 + (16 + power_sum(1296))
// This results in: 2 + 16 + 1296 = 1314