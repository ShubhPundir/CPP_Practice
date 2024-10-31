#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string message = "Good Morning World";
    message.resize(12);
    // char* m;
    // strcpy(m,"Good Morning");

    cout << message;
    return 0;
}
