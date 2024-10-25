#include <iostream>
using namespace std;

int data = 0;

namespace name1{
    int data = 1;
}

int main(){
    // using name1::data;
    int data = 2;

    cout << data << endl; // local data
    cout << name1::data << endl; // name1::data
    cout << ::data; // global data
}