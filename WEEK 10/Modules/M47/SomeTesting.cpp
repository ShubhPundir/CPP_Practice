#include <iostream>
#include <initializer_list>
using namespace std;

int main(){
    initializer_list<int> i = {1,2,3,4};
    auto i_a = {1,4,9,16};

    // error
    // auto wow{1,2,3,4};

    for(auto it:i_a)
        cout << it << " ";
}