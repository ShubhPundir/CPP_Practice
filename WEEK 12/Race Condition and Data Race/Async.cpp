#include <iostream>
#include <vector>
#include <thread> // thread, this_thread::sleep_for
#include <future> // future
#include <chrono> // chrono::milliseconds
#include <cstdlib> // rand()
using namespace std;

int square(int x) { 
    // called in different threads - one each for 1 .. 20
    int p = x * x; // compute product
    int delay = (int)((double)std::rand() / (double)(RAND_MAX)* 100); // random number between 0 and 100
    std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // random delay: 0ms .. 100ms
    return p;
}
int main() {
    int accum = 0; // define accumulator
    vector<future<int>> fts; // vector of future objects
    
    for (int i = 1; i <= 20; i++) { 
        fts.push_back(async(&square, i)); 
    } // 20 future objects
    
    for (auto& ft : fts) { 
        accum += ft.get();
    } // wait to get value from future and accumulate
    cout << " accum = " << accum << endl; // print final value
}