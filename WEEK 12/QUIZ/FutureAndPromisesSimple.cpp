#include <iostream>
#include <thread>
#include <future>
#include <vector>
using namespace std;

void change(std::promise<std::vector<int>>&& pr, std::future<std::vector<int>>& fu) {
    // Wait for the vector to be available and retrieve it
    std::vector<int> v = fu.get(); 
    std::vector<int> res;

    for (auto i : v) // Square each element
        res.push_back(i * i); // Store the squared values

    pr.set_value(res); // Set the squared result in the promise
}

int main() {
    std::promise<std::vector<int>> p; // Create a promise
    std::future<std::vector<int>> f = p.get_future(); // Get future associated with promise

    std::vector<int> v {10, 20, 30, 40}; // Vector with initial values

    std::thread th{change, std::move(p), std::ref(f)}; // Start a new thread

    p.set_value(v); // Set value of the promise with vector v

    // Wait for the thread to finish before getting the result
    th.join();

    auto rv = f.get(); // Get the squared values from future

    for (auto i : rv) // Output the results
        cout << i << " ";
    
    return 0;
}