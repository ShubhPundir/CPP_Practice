#include <iostream>

template<typename T>
void swapByCopy(T& a, T& b){
    T tmp(a);
    a = b;
    b = tmp;
}

template<typename T>
void swapByMove(T& a, T& b){
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}


int main(){

    int a = 1, b = 2;
    int* pA = &a;
    int *pB = &b;

    std::cout << a << " " << b << std::endl; // 1 2
    std::cout << pA << " " << pB << std::endl; // pA pB
    
    b=std::move(a);
    
    std::cout << a << " " << b << std::endl; // 1 1
    std::cout << pA << " " << pB << std::endl; // pA pB

    // only safe to move rvalues
    // it is preferred not to move lvalues

    // Rvalue --> T&&
    // Lvalue --> T&
}