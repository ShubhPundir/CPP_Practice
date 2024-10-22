#include <iostream>
using namespace std;


int& modify(int &a)
{
    return a = a * 2;
}
int main()
{
    int p = 3, q =4;
    int& r = modify(p);

    cout << p << " " << r << " ";
    
    modify(p) = q;

    cout << p << " " << r << " ";
    return 0;
}