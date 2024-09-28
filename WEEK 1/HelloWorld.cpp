#include <iostream>
int main(){
    std::cout << "Hello World in CPP";
    std::cout << std::endl;

    int a,b;
    std::cout << "INPUT 2 numbers";
    std::cin >> a >> b;

    int sum = a + b;
    std::cout << "Sum of " << a << "and " << b << " is " << sum << std::endl; 


    return 0;
}