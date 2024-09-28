#include <iostream>
using namespace std;

void fun(int& b, int c)
{
    cout << "b: " << b << " " << "&b: " << &b << endl;
    cout << "c: " << c << " " << "&c: " << &c << endl;
}

int main()
{
    int a = 123;
    cout << "a: " << a << " " << "&a: " << &a << endl;
    fun(a,a);
    return 0;
}