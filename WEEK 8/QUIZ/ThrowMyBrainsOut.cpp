#include <iostream>
using namespace std;

void validate(int i){
    try{
        if(i<0)
            throw "negative";
        else if(i>0)
            throw i * 1.00;
        else
            throw 0;
    }
    catch(float){ cout <<"float ";}
    catch(int){ cout <<"int ";}
    catch(const char*){ cout <<"char * ";}
}
int main(){
    try{
        validate(0);
        validate(5);
        validate(-5);
    }
    catch(...){ cout << "ALL";}
}