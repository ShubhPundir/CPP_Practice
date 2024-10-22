#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int* const p = &n; // constant pointer
    int m = 10;
    // p = &m; // error as p is a constant pointer
    
    cout << *p << endl;

    *p = 218;
    cout << *p;
    return 0;
}
/*
Finally, to decide on const-ness, draw a mental line through *
    int n = 5;
    int * p = &n; // non-const-Pointer to non-const-Pointee
    const int * p = &n; // non-const-Pointer to const-Pointee
    int * const p = &n; // const-Pointer to non-const-Pointee
    const int * const p = &n; // const-Pointer to const-Pointee
*/