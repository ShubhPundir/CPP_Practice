#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int *const p = &n;
    int m = 10;
    p = &m;

    cout << *p;
    return 0;
}