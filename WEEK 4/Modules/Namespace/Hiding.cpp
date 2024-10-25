#include <iostream>
#include <cstdlib>

namespace Test{
    int abs(int n){
        if(n>100) return n+1;
        return n;
    }
}
using namespace std;
// using namespace Test; // ambiguous call
int main(){
    cout << abs(200) << " " << Test::abs(200) << endl;
    cout << abs(20) << " " << Test::abs(20);
}