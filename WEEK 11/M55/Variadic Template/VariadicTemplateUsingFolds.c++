#include <iostream>

template <typename... Args>
void printAll(Args... args) {
    // Base case: Just expand the arguments
    (std::cout << ... << args) << '\n';  // Fold expression (C++17)
}

int main() {
    printAll(1, 2.5, "hello", 'A');
    return 0;
}
