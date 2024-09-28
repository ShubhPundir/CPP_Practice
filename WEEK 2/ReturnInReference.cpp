#include <iostream>
using namespace std;

int returnByVal(int &x)
{
    cout << "x: " << x << " and &x: " << &x << endl;
    return x;
}
int& returnByRef(int &x)
{
    cout << "x: " << x << " and &x: " << &x << endl;
    return x;
}
int main()
{
    int a = 10;
    cout << "a: " << a << " and &a: " << &a << endl;
    
    const int& val = returnByVal(a); // const needed
    cout << "val: " << val << " and &val: " << &val << endl;
    
    const int& ref = returnByRef(a); // const optional 
    cout << "ref: " << ref << " and &ref: " << &ref << endl;
    

}