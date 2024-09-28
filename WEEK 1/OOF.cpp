#define glue(a,b) a##b
#define str(x) #x

#include <iostream>
using namespace std;

int main(){

    cout << str(test) << endl;

    glue(co,ut) << "test";

    return 0;
}