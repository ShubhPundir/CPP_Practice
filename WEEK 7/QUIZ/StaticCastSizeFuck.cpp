#include <iostream>
using namespace std;

int main(){
    char ch = 'C';
    double db = 3.14;
    char *cp = &ch;
    double *pd;

    ch = static_cast<char>(db);
    db = static_cast<double>(ch);
    pd = static_cast<double*>(cp);
    ch = static_cast<char>(&ch);
    // cout << static_cast<double>(ch);
    // cout << ch;
    // cout << sizeof(char) << " " <<sizeof(double);
}