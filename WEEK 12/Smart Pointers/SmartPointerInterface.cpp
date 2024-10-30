#include <iostream>
using namespace std;

template<class T>
class SmartPtr {
    T* pointee;

public:
    // Explicit constructor from a raw pointer to a smart pointer
    explicit SmartPtr(T* pointee_) : pointee(pointee_) {}

    // Copy constructor
    SmartPtr(const SmartPtr& other) : pointee(new T(*other.pointee)) {}

    // Copy assignment operator
    SmartPtr& operator=(const SmartPtr& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        delete pointee; // Clean up existing resource
        pointee = new T(*other.pointee); // Deep copy of other.pointee
        return *this;
    }

    // Destructor
    ~SmartPtr() { delete pointee; }

    // Dereference operator
    T& operator*() const { return *pointee; }

    // Arrow operator
    T* operator->() const { return pointee; }
};

int main() {
    int n = 20, m = 35;
    int* p = &n;
    SmartPtr<int> ptr0(p);
    SmartPtr<int> ptr1(new int(10));
    SmartPtr<int> ptr2(ptr1); // Copy constructor
    SmartPtr<int> ptr3 = ptr1; // Copy assignment
    SmartPtr<int> ptr4(&m);

    cout << *ptr0 << " "<< *ptr1 << " " << *ptr2 << " " << *ptr3 << endl; // Output should be 10 10 10
    cout << *ptr4;
    cout << "helo";
    return 0;
}
/*
    The issue with ptr0 and ptr4 is that they are constructed with
    pointers to stack-allocated variables (p and &m), 
    which are not dynamically allocated (i.e., not created using new). 
    
    SmartPtr is designed to manage dynamic memory, 
    meaning it expects a pointer to memory allocated with new, 
    and it will attempt to delete this memory when the SmartPtr object is destroyed.
*/