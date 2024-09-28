#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int numbers[6];
    
    for(int i=0;i<6;i++)
        *(numbers + i) = (i + 1) * 10;

    rotate(numbers,numbers + 5, numbers + 6);
    rotate(numbers,numbers + 2, numbers + 5);

    for(int i=0;i<6;i++)
        cout << numbers[i] << " ";

    return 0;
}
