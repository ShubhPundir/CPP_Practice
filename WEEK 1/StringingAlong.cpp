#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Programming";
    str.erase(3,5); // refers to erasing from [3] to [3 + 5]
        // Proing
    str.insert(3,"AB"); // inserts "AB" in [3] 
        // ProABing
    str.insert(5,"XYZ");

    cout << str;
    return 0;
}
