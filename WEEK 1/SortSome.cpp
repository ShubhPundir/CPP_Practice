#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int i, int j){
    return (i<j);
}
int main()
{
    // int arr[] = {9,4,2,8,6,3,1};
    int arr[] = {60, 25, 35, 15, 45};
    sort(&arr[1],&arr[4]);
    
    for(int i=0;i<5;i++)
        cout << arr[i] << " ";

    return 0;
}
