#include <iostream>

constexpr int f2(const int i){
    return i + 10;
}

void function(const int i){
    constexpr int n = 20;
    constexpr int c1 = n + 30;
    constexpr int c2 = n + c1;
    constexpr int c3 = n + i; // errpr
    constexpr int c4 = n + f2(i); // error
    constexpr int c5 = n + f2(4); // not error
}

int main(){
    function(50);
    return 0;
}