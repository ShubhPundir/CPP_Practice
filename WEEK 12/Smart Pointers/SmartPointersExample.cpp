#include <iostream>
#include <memory> // For smart pointers

class Demo {
public:
    Demo() { std::cout << "Demo constructor called!\n"; }
    ~Demo() { std::cout << "Demo destructor called!\n"; }
    void show() { std::cout << "Demo::show() called!\n"; }
};

void uniquePtrDemo() {
    std::cout << "=== unique_ptr Demo ===\n";
    std::unique_ptr<Demo> ptr1 = std::make_unique<Demo>();
    ptr1->show();

    // Transfer ownership to another unique_ptr
    std::unique_ptr<Demo> ptr2 = std::move(ptr1);
    if (!ptr1)
        std::cout << "ptr1 is now empty!\n";
    ptr2->show();
    // ptr2 is automatically destroyed here, calling the destructor of Demo
}

void sharedPtrDemo() {
    std::cout << "\n=== shared_ptr Demo ===\n";
    std::shared_ptr<Demo> ptr1 = std::make_shared<Demo>();
    std::cout << "Reference count: " << ptr1.use_count() << "\n";

    {
        std::shared_ptr<Demo> ptr2 = ptr1; // Shared ownership
        std::cout << "Reference count: " << ptr1.use_count() << "\n";
        ptr2->show();
    } // ptr2 goes out of scope but ptr1 still owns the object

    std::cout << "Reference count after ptr2 is out of scope: " << ptr1.use_count() << "\n";
    ptr1->show();
    // ptr1 is destroyed here, and the object is deleted as no one owns it anymore
}
void weakPtrDemo() {
    std::cout << "\n=== weak_ptr Demo ===\n";

    // Create a shared_ptr that manages a Demo object
    std::shared_ptr<Demo> sharedPtr = std::make_shared<Demo>();
    // Create a weak_ptr that observes the same Demo object
    std::weak_ptr<Demo> weakPtr = sharedPtr;

    // Display the reference count of the shared_ptr
    std::cout << "Reference count: " << sharedPtr.use_count() << "\n"; // 1

    // Attempt to lock the weak_ptr to access the Demo object
    /*
        The lock() method attempts to convert the weak_ptr into a shared_ptr.
        If the object is still alive (i.e., if there are active shared_ptr instances pointing to it), lock() returns a valid shared_ptr (lockedPtr).
        If the object has been destroyed (when all shared_ptr instances are out of scope or reset), lock() returns nullptr.
    */
    if (auto lockedPtr = weakPtr.lock()) { // Check if shared_ptr is still valid
        std::cout << "Accessing Demo object through weak_ptr\n";
        std::cout << "Reference count with lockedPtr: " << lockedPtr.use_count() << '\n'; // 2
        lockedPtr->show(); // Call the show method on the Demo object
    }

    // Manually release ownership of the Demo object by resetting the shared_ptr
    sharedPtr.reset(); // This decreases the reference count and may delete the object
    std::cout << "Reference count after sharedPtr.reset(): " << sharedPtr.use_count() << '\n'; // 0
    // Check if the weak_ptr has expired (i.e., the object it points to has been deleted)
    if (weakPtr.expired()) {
        std::cout << "The weak_ptr object is expired!\n"; // The object is no longer valid
    }
}


int main() {
    uniquePtrDemo();
    sharedPtrDemo();
    weakPtrDemo();
    return 0;
}
