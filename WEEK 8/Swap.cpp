#include <iostream>
#include <string>
using namespace std;

template<class T>
void Swap(T& one, T& other){
    T temp = one;
    one = other;
    other = temp;
}

int main(){
    int i = 10, j = 20;
    cout << "i = " << i << " j = " << j << endl;
    Swap(i,j);
    cout << "i = " << i << " j = " << j << endl;

    string a = "hheehhe", b = "yoyoyoo";
    cout << "a = " << a << " b = " << b << endl;
    Swap(a,b);
    cout << "a = " << a << " b = " << b << endl;

}