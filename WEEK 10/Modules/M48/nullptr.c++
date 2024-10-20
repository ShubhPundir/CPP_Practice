#include <iostream>
using namespace std;

void fun(int a){
    cout << "f(int) called" << endl;
}

void fun(int* a){
    cout << "f(int*) called" << endl;
}
int main(){

    int* q = nullptr;
    char* p = nullptr;
    char* p1 = 0;
    char* p2 = NULL;
    
    if(p)
        cout << "char*p=nullptr is a true" << endl;
    if(p==p1)
        cout << "char*p=nullptr == char* p1 = 0 is a true" << endl;
    if(p==p2)
        cout << "char*p=nullptr == char* p2 = NULL is a true" << endl;

    fun(0);
    fun(nullptr);
    // fun(NULL); // NULL is ambiguous

}
