#include <iostream>
using namespace std;

template<typename T>    //LINE-1

double findMin(T num){ return num; }    //LINE-2 
// Base Case

template<typename T, typename... Args>    //LINE-3
double findMin(T num, Args... nums){     //LINE-4
    cout << num << " ";
    return num <= findMin(nums...) ? num : findMin(nums...);   
}
/*
findMin(30, 20, 10)
    |
    -> findMin(20, 10)
        |
        -> findMin(10) -> returns 10
    <- returns 10
<- returns 10
*/
int main(){
    int a = 10, b = 20, c = 23;
    double d =120.2, e =2.1, f=-421.1;
    // std::cin >> a >> b >> c;
    // std::cin >> d >> e >> f;
    
    // std::cout << findMin(c,b,a) << "\n";

    std::cout << findMin(a, b, c) << "\n";
    std::cout << findMin(d, e, f) << "\n";
    std::cout << findMin(a, b, c, d, e, f);
    return 0;
}