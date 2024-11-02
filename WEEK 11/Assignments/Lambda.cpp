#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main() {
    std::vector<int> vec1 {2, 4, 6};
    std::vector<long long> vec2;
    
    // for(int i = 0; i < 3; i++){
    //     int a;
    //     std::cin >> a;
    //     vec1.push_back(a);
    // }
    std::function<long long(int)> factorial =[&](int n) {    //LINE-1
        return n > 1 ? n * factorial(n - 1) : 1;
    };
    
    for(auto i : vec1)
        vec2.push_back(factorial(i));
        
    [&](const std::vector<long long>& x) {    //LINE-2 
        for (auto i : x){ std::cout << i << " "; } 
    }(vec2);
     
    return 0;
}