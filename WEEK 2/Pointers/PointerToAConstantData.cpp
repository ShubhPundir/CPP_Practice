#include <iostream>
using namespace std;

void fun2(){
    const int n2 = 10;
    int m = 20;
    // int * p2 = &n2;
    // invalid as n2 is a constant, it cannot convert from 'const int*' to 'int*'
    
    const int* p2 = &n2;
    // VALID as hell, YEAHAHHAHAHH
    // p2 is a pointer to a constant data now and now the conversion is okay
    cout << p2 << " " << *p2 << endl;

    p2 = &m; // but it can still change its value
    cout << p2 << " " << *p2 << endl;
    
    // *p2 = 90;
    // however cannot change the value of the variable it is pointing to

    // OUTPUT:
    // 0xce89fffbd4 10
    // 0xce89fffbd0 20
}

void fun1(){
    int n = 10, m = 20;
    const int* p = &n; // Pointer to a constant data 
    cout << p << " " << *p << endl;

    // *p = 90;
    // error as the value the p points to is a constant

    p = &m;
    cout << p << " " << *p << endl;
    
    // OUTPUT:
    // 0xb6937ffb94 10
    // 0xb6937ffb90 20    

}

int main(){

    fun2();
    
    // cout << p << " " << *p << endl;


}