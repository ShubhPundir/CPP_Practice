#include <iostream>

void printAll() {}  // Base case: Do nothing

template <typename T, typename... Args>
void printAll(T first, Args... rest) {
    std::cout << first << " ";
    printAll(rest...);  // Recursive call with the remaining arguments
}

int main() {
    printAll(1, 2.5, "hello", 'A');
    return 0;
}
