#include <iostream>
#include <string>
using namespace std;

int main()
{
    string message = "Good Morning World";
    // message.resize(12);
    char* m;
    strcpy(m,"Good Morning");

    cout << m;
    return 0;
}
