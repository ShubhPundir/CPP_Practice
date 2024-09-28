#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 40;
    const int *a = &x;
    int * const b = &x;
    int const *c = &x;
    int const * const d = &x;

    *a = 20;
    *b = 20;
    *c = 20;
    *d = 20;

    return 0;
}
