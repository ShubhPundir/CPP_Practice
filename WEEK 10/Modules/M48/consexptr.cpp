#include <iostream>
using namespace std;

enum Flags{
    good = 0, fail =1 , bad =2, eof= 4
};

constexpr int operator | (Flags f1, Flags f2){
    return Flags(int(f1) | int(f2));
}

// void f(Flags x){
//     switch(x){
//         case bad : cout << "Bad" << endl; break;
//         case eof : cout << "Eof" << endl; break;
//         case bad|eof : cout << "Bad|Eof" << endl; break;
//         case bad : cout << "Bad" << endl; break;
//     }
// }

// void yo(Flags f3){
//     constexpr int x2 = bad|f3;
//     cout << x2 << endl; // error as f3 is a variable
// }
int main(){
    constexpr int x1 = bad|eof;
    // 
    cout << x1;    
}