#include <iostream>
#include <cstring>
using namespace std;

void defaultBehaviour(){
    char * str = strdup("IIT, Kharagpur");
    str[0] = 'N'; // Edit the name
    cout << str << endl;
    str = strdup("JIT, Kharagpur"); // Change the name
    cout << str << endl;
}

void fun1(){
    // pointer to a constant data
    const char * str = strdup("IIT Kharagpur");
    // str[0] = 'T'; // not allowed
    str = strdup("TIT Kharagpur");
    cout << str;
}
void fun2(){
    // constant pointer
    char * const str = strdup("IIT Kharagpur");
    str[0] = 'T';
    // str = strdup("TIT Kharagpur"); // not allowed
    cout << str;
}
void fun3(){
    //constant pointer to a constant data
    const char * const str = strdup("IIT Kharagpur");
    // str[0] = 'T'; // not allowed
    // str = strdup("TIT Kharagpur"); // not allowed
    cout << str;
}

int main(){

    fun3();

}