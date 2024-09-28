#include <iostream>
using namespace std;

int fun(int a)
{
    return a;
}
int fun(int a, int b=2)
{
    return a+2.0;
}
int main()
{
    int x = 5;

    cout << fun(x); // ambiguous 

    return 0;
}