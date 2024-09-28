#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    for(int i=0;i<1;i++){
        int j = arr[i];
        replace(arr, arr + 5, j, *(arr + 4 - i)); // replace(START,END, WHAT_2_REPLACE, REPLACED_ITEM)
    }
    // 50, 20, 30, 40, 50
    
    for(int i=0;i<5;i++)
        cout << arr[i] << " ";

    return 0;
}
