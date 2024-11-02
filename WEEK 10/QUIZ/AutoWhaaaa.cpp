#include <iostream>
#include <vector>
using namespace std;

void change(std::vector<int>& iv){
    auto j =2;
    // for(auto& i: iv) // lvalue auto
    // for(decltype((j)) i : iv) // lvalue
    for(decltype(iv[j]) i : iv) // reference of pointer to vector element
        i *= j;
    
}

int main(){
    std::vector<int> iVec {10,20,30,40};
    change(iVec);
    for(auto i: iVec)
        cout << i << " ";

}