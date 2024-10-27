#include <iostream>
using namespace std;

int main(){
    if([](int a, int b) {return a*2 == b;} (12,24))
        cout << "YOOOOOO\n";
    else
        cout << "NIGHTMARE NIGHTMARE NIGHTMARE RAAHAHHAHAHHA\n";

    cout << "This lambda returns " << [](int x, int y) -> double {
        if(x>5) return x+y;
        else if (y<2) return x-y;
        else return x*y;
    }(3.14, 2.7) << " HEHEHE" << endl;
}