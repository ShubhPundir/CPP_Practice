#include <iostream>
using namespace std;

enum Days  {Sunday, 
            Monday = 10,
            Tuesday,
            Wednesday, 
            Thursday,
            Friday,
            Saturday};

Days operator+(const Days &a, const Days &b){
    unsigned int ea = a, eb = b;
    unsigned int c = (ea + eb)%7;
    return Days(c);
}

int main()
{
    Days x = Tuesday, y = Sunday;
    Days z = Wednesday;
    Days result = x + y;

    cout << result << endl << endl;
    cout << x << " " << y << " " << z;
    return 0;

}