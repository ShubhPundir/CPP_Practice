#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <future> // CHANGED
using namespace std;

int accum = 0;
void square(future<int>& fut) {
    int x = fut.get(); // CHANGED
    int p = x * x; // compute product
    int delay = (int)((double)std::rand() / (double)(RAND_MAX)* 100); // random number between 0 and 100
    std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // random delay: 0ms .. 100ms
    accum += p; // accumulate product
}

int main(){
    vector<promise<int>> vp; // CHANGED
    vector<future<int>> vf; // CHANGED
    vector<thread> vt; // CHANGED
    for(int i=0; i<=20; i++){
        vp.push_back(promise<int>()); // CHANGED
        vf.push_back(vp[i].get_future()); // CHANGED
        vt.push_back(thread(&square, std::ref(vf[i]))); // CHANGED
        vp[i].set_value(i+1); // CHANGED --> Fulfill promise
        cout << i << " ";
    }
    cout << endl;
    for(auto& th : vt){
        cout << th.get_id() << " ";
        th.join();
    }
    cout << endl;
    cout << "accum: " << accum;
}