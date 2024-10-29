#include <iostream>
using namespace std;

template <typename ...Types>
struct Count; // declaration only

template<> struct Count<>{
    const static int value = 0;
};

template<typename T, typename... Rest>
struct Count<T, Rest...>{
    const static int value = 1 + Count<Rest...>::value;
};

int main(){
    auto count1 = Count<int, double, char, float>::value;
    auto count2 = Count<int>::value;
    auto count3 = Count<>::value;

    cout << count1 << endl;
    cout << count2 << endl;
    cout << count3 << endl;
}