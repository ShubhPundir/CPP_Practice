#include <iostream>
using namespace std;

int DoIt(int a, char b, char c){
    cout << "DoIt\n";
    return a + b + c;
}

int main(){
    int (*ptFunc) (int,char,char);
    
    // ptFunc = &DoIt; // OR
    ptFunc = DoIt;

    if(ptFunc == &DoIt){
        int res = ptFunc(1,'A',' '); // 1 + 65 + 32 = 98
        cout << "pointer points to DoIt : "<< res << endl;
    } 
}