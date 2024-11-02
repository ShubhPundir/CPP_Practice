#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created.\n"; }
    ~MyClass() { std::cout << "MyClass destroyed.\n"; }
};

int main() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(); // MyClass created
    std::weak_ptr<MyClass> weakPtr = sharedPtr; // Create a weak pointer from shared pointer

    if (auto lockedPtr = weakPtr.lock()) { // Attempt to lock the weak pointer
        std::cout << "Object is still alive.\n"; // THIS RUNS
    } else {
        std::cout << "Object has been destroyed.\n";
    }

    sharedPtr.reset(); // Reset shared pointer, destroying the MyClass object
    // MyClass destroyed

    if (auto lockedPtr = weakPtr.lock()) { // Attempt to lock again
        std::cout << "Object is still alive.\n";
    } else {
        std::cout << "Object has been destroyed.\n"; // THIS RUNS
    }

    return 0;
}
