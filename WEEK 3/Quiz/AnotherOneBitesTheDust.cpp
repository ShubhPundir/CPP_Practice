#include <iostream>
using namespace std;

int globalVar = 5;

class Example{
    // int memberVar;
    public: 
        Example() {globalVar = 5;}
        ~Example() {globalVar = 6;}
};

void someFunction(){
    Example ex;
}
int anotherFunction(){
    globalVar = 7;
    someFunction();
    return globalVar++;
}

int main()
{
    cout << anotherFunction() << " ";
    cout << globalVar << endl;

    return 0;
}