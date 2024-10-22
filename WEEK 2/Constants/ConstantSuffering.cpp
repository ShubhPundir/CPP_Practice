#include <iostream>
using namespace std;
int main()
{
    const int n = 2;
    cout << n << "\n";
    // n = 4; // is an error
    // int *p = &n; // FUCK also an error

    cout << n;
    return 0;
}
