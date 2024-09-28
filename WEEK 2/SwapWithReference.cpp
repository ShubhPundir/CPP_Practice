#include <iostream>
using namespace std;

void swapNum(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
int main()
{
    int x = 10, y = 2;
    cout << "x=" << x << " y=" << y << endl;
    swapNum(x,y);
    cout << "x=" << x << " y=" << y << endl;
}