#include <iostream>
#include <thread>
#include <future>
using namespace std;

void compute(promise<int> &p) {
    // Simulate some computation
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_value(42); // Set the computed value in the promise
}

int main() {
    promise<int> p;               // Create a promise
    future<int> f = p.get_future(); // Get the associated future

    std::thread t(compute, std::ref(p)); // Start a thread to compute the value
    std::cout << "Waiting for the result..." << std::endl;

    int result = f.get(); // This will block until the value is available
    std::cout << "Result: " << result << std::endl;
    cout << "HEHEHHE";
    t.join(); // Wait for the thread to finish
    return 0;
}
