#include <iostream>
using namespace std;

void update(int &x){
    x += 5;
}

int main(){

    int a = 3;
    int b = 4;
    update(a);
    update(b);
    cout << a << " " << b;
    return 0;
}