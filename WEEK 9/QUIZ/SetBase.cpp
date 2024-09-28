#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i = 90;

    cout << setbase(8) << i << " ";
    cout << setbase(10) << i << " ";
    cout << setbase(16) << i << " ";
    cout << static_cast<char>(i) << endl;

    return 0;
}