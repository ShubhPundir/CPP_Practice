#include <iostream>
#include <functional>
using namespace  std;

int func(int x1, int x2, int x3, const int& x4){
    return x1 - (x2 + x3 + x4);
}

int main(){
    using namespace std::placeholders;
    int i = 5, j = 3;
    auto f = std::bind(func, _2, i, _1, std::cref(j)); // func(_2, 5, _1, 3)
    
    cout << f(1,2) << endl; // 1 --> _1, 2-->_2
    // func(2,5,1,3) is called --> returns -7
    
    
    i = j = -10;
    cout << i << endl;
    cout << j << endl;
    cout << f(1,2); // 1 --> _1, 2 --> _2
    // func(2, 5, 1, -10) --> returns 6
    // 2 - (5+1-10)
    // = 2 - (-4)
    // 6

    // i does not get updated because it is not mentioned by cref like j
}
/*
Reference Type:
    std::ref(T& t): This creates a std::reference_wrapper<T> that 
                    allows a mutable reference to the object. 
                    It can be used to modify the object it refers to.
    std::cref(const T& t): This creates a std::reference_wrapper<const T>
                           which makes the reference read-only. 
                           It is used when you want to ensure that 
                           the object cannot be modified.

Use Case:
    Use std::ref() when you want to pass an object to a function that will modify it.
    Use std::cref() when you want to pass an object to a function but ensure that the function does not modify the object.
*/