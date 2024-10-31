#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int numbers[6];
    
    for(int i=0;i<6;i++)
        *(numbers + i) = (i + 1) * 10;
    // 10 20 30 40 50 60
    rotate(numbers, numbers + 5, numbers + 6); // rotate(begin, middle, end)
    // 10 20 30 40 50 {60}
    // 60 10 20 30 40 50
    
    rotate(numbers,numbers + 2, numbers + 5);
    // {60 10} {20 30 40} 50
    // 60 10 30 40 50 20 

    for(int i=0;i<6;i++)
        cout << numbers[i] << " ";
    // 20 30 40 60 10 50
    return 0;
}
