#include <iostream>
using namespace std;

template<typename T>
T n = T(65);

int main(){
    n<int> = 10;
    cout << n<int> << endl;

    cout << n<char> << endl;
}