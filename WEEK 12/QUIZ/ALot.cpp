#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

void addition(std::vector<int>& v){
    for(int i = 5; i < 9; i++)
        v.push_back(i);
}

int main(){
    vector<int> v;
    std::thread t1 {&addition, std::ref(v)};

    for(int i=0; i<4; i++)
        v.push_back(i);

    t1.join();
    for(int i: v)
        cout << i << " ";
    return 0;
}