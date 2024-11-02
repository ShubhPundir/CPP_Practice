#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int compute(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a long computation
    return x * x;
}

int main() {
    std::cout << "Starting computation..." << std::endl;

    // Start the computation asynchronously
    std::future<int> result = std::async(std::launch::async, compute, 5);

    // Main thread can do other work here
    std::cout << "Doing other work in main thread..." << std::endl;

    // Wait for the result
    int value = result.get(); // Blocks until the computation is complete
    std::cout << "Computation result: " << value << std::endl;

    return 0;
}
