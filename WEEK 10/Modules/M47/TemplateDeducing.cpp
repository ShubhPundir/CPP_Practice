#include <initializer_list>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void f(T param){
    cout << "YOOOHOO" <<endl;
}

int main(){
    auto i1 = 10;
    auto i2(20);
    auto i3{30};
    cout << i1 << " "<< i2 << " " << i3 << endl;

    // f(i2);
    // f({1,2,3}); //error
    // f{1,2,3}; //error
    auto i4 = {1,2,3,4};
    // f(i4); // okay

    // f<decltype(i4)>(i4); // okay

    // f<decltype(i4)>({1,2,3});// okay

    // f<decltype({1,2,3})>({1,2,3});// not okay

    f<initializer_list<int>>({1,2,3});// okay
}