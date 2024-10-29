#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
    char c;
};

void Print(Data data){
    cout << "data.i = " << data.i << endl;
    cout << "data.f = " << data.f << endl;
    cout << "data.c = " << data.c << endl;
    cout << "-----------------------------------" << endl;
}

int main() {
    Data data;
    data.i = 10;
    Print(data);

    data.f = 3.14;
    Print(data);

    data.c = 'A';
    Print(data);

    // Note: data.i and data.f now hold unpredictable values
    return 0;
}

/*
    OUTPUT:
    
    data.i = 10
    data.f = 1.4013e-44
    data.c = 

    -----------------------------------
    data.i = 1078523331
    data.f = 3.14
    data.c = �
    -----------------------------------
    data.i = 1078523201
    data.f = 3.13997
    data.c = A
    -----------------------------------
*/