#include <iostream>
using namespace std;
// This is from a course assignment LMAO


void update(const int &x)
{
    x = 10; // LINE 1
}
int main()
{
    const int a = 5;
    int b = 15;
    const int *p = &a;
    *p = b; // LINE 2
    p = &b; // LINE 3

    update(a); // LINE 4
    update(b); // LINE 5

    return 0;
}