#include <iostream>
#include <vector>
using namespace std;

void change(vector<int>& iv){
    auto j = 2;
    for(decltype((j)) i: iv) // auto& i // auto i // decltype(iv[j])
    {
        i*=j;
    }
}

int main(){
    vector<int> iVec {10,20,30,40};
    change(iVec);

    for(auto i : iVec){
        cout << i << ", ";
    }
    return 0;
}