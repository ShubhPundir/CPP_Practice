#include <iostream>
using namespace std;

void func(){
    try{
        throw 9.81;
    }
    catch(int &e){throw e;}
}

int main(){
    try{
        func();
    }
    catch(int &e){ cout << "int";}
    catch(double &e){ cout << "double";}
    catch(...){ cout << "all";}
}