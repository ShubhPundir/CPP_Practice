#include <iostream>
#include <cstring>
using namespace std;

class MyResource {
    char *str = nullptr;

public:
    MyResource() : str(nullptr) { } // Default constructor

    MyResource(const char* s) : str(strcpy(new char[strlen(s) + 1], s)) { } // Parameterized constructor

    // Move constructor
    MyResource(MyResource&& rr) noexcept : str(rr.str) {
        rr.str = nullptr;
    }

    // Move assignment operator
    MyResource& operator=(MyResource&& rr) noexcept {
        if (this != &rr) {
            delete[] str; // Release the current value
            str = rr.str; // Take ownership of rr's resource
            rr.str = nullptr; // Leave rr in a valid state
        }
        return *this;
    }

    // Destructor to release allocated memory
    ~MyResource() {
        delete[] str;
    }

    friend ostream& operator<<(ostream& os, const MyResource& r) {
        os << (r.str ? r.str : "Empty"); // Output the string or "Empty" if null
        return os;
    }
};

class MyClass {
    MyResource mRrc;

public:
    // Parameterized constructor
    MyClass(const char* s) : mRrc(s) { }

    // Move constructor
    MyClass(MyClass&& c) noexcept : mRrc(std::move(c.mRrc)) { }

    // Move assignment operator
    MyClass& operator=(MyClass&& c) noexcept {
        if (this != &c) {
            mRrc = std::move(c.mRrc); // Move MyResource using move assignment
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const MyClass& mc) {
        os << mc.mRrc;
        return os;
    }
};

int main() {
    MyClass c1("Hello");
    MyClass c2("World");

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    // Move c2 into c1
    c1 = std::move(c2);

    cout << "After moving c2 to c1:" << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl; // c2 should be in a valid but empty state

    return 0;
}
