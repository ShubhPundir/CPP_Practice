#include <iostream>

template<typename S>
int compare(S n1, S n2){
    return n1*n2;
}

int main(){
    // std::cout << compare(31.46, 34); // error
    // std::cout << compare(31.45, 34.0); // pass 
    // std::cout << compare('A', 34); // error
    std::cout << compare('i', 'k'); // how the fuck, pass

    return 0;
}