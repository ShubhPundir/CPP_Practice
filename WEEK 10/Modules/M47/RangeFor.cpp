#include <iostream>
#include <vector>
#include <map>
int main() {
// Driver
    std::vector<int> v = { 0, 1, 2, 3, 4, 5 }; // Iterating over whole array
    for (auto i : v)
        std::cout << i << ' '; std::cout << std::endl;
    
    // the initializer may be a braced-init-list
    for (int n : { 0, 1, 2, 3, 4, 5 })
        std::cout << n << ' '; std::cout << std::endl;
    
    int a[] = { 0, 1, 2, 3, 4, 5 }; // Iterating over array
    
    for (int n : a) 
        std::cout << n << ' '; std::cout << std::endl;
    
    // Just running a loop for every array element
    for (int n : a) 
        std::cout << "In loop" << ' '; std::cout << std::endl;
    
    std::string str = "PPD"; // Printing string characters
    for (char c : str) 
        std::cout << c << ' '; std::cout << std::endl;
    
    std::map <int, int> MAP({{1,1}, {2,4}, {3,9}}); // Printing keys and values of a map
    for (auto i : MAP) 
        std::cout << ' ' << i.first << ", " << i.second << std::endl;
}