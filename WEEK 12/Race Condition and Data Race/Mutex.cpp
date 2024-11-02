#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib> // rand()
#include <mutex>
using namespace std;

int accum = 0;
mutex accum_mutex; // mutex variable

void square(int x) { 
    int p = x * x; // compute product
    int delay = (int)((double)std::rand() / (double)(RAND_MAX)* 100); // random number between 0 and 100
    std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // random delay: 0ms .. 100ms
    
    accum_mutex.lock();
    accum += p; // accumulate product
    accum_mutex.unlock();
}

int main(){
    vector<thread> ths;
    for(int i=0; i<=20; i++){
        ths.push_back(thread(&square,i));
        cout << i << " ";
    }
    cout << endl;
    for(auto& th : ths){
        cout << th.get_id() << " ";
        th.join();
    }
    cout << endl;
    cout << "accum: " << accum;
}