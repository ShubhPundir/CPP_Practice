#include <iostream>
#include <string>
using namespace std;

union U{
    int m1;
    float m3;
};

int main(){
    U u;
    u.m1 = 1;
    float f = u.m3;
}