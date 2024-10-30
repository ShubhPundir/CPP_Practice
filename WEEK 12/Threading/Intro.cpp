#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void f() {cout << "In f()\n";}
struct F{void operator()(){cout << "In F()()\n";}};

void fun(){
    
    std::thread t1{f};
    std::thread t2{F()};

    t1.join();
    t2.join();
}

int main(){
    int iterations = 20;

    std::vector<std::thread> threads; // Vector to store threads

    // Loop to create and start threads
    for (int i = 0; i < iterations; ++i) {
        threads.emplace_back(fun); // Create a thread for fun()
        // emplace_back used when we need to add new objects directly into the container
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }
}