#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> v {20,30,40,50,10};

    struct compare{
        bool operator()(int a, int b) {return a>b;}
    };
    sort(v.begin(); v.end(); compare);
    

}