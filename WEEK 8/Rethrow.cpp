#include <iostream>
#include <stdexcept>

class CustomException : public std::runtime_error {
public:
    CustomException(const std::string &msg) : std::runtime_error(msg) {}
    const char* getType() const { return "CustomException"; }
};

void rethrowUsingThrowEx() {
    try {
        throw CustomException("Initial exception thrown.");
    } catch (const std::exception &ex) {
        std::cout << "Caught in rethrowUsingThrowEx: " << ex.what() << std::endl;
        throw ex;  // throws a new exception, potentially losing derived type information
    }
}

void rethrowUsingThrow() {
    try {
        throw CustomException("Initial exception thrown.");
    } catch (const std::exception &ex) {
        std::cout << "Caught in rethrowUsingThrow: " << ex.what() << std::endl;
        throw;  // rethrows the original exception with full context
    }
}

int main() {
    std::cout << "Demonstrating throw ex:\n";
    try {
        rethrowUsingThrowEx();
    } catch (const std::exception &ex) {
        std::cout << "Caught in main after throw ex: " << ex.what() << std::endl;

        // Attempt to access derived class method (may not work due to slicing)
        const CustomException *customEx = dynamic_cast<const CustomException*>(&ex);
        if (customEx) {
            std::cout << "Exception type: " << customEx->getType() << std::endl;
        } else {
            std::cout << "Exception type lost due to slicing.\n";
        }
    }

    std::cout << "\nDemonstrating throw:\n";
    try {
        rethrowUsingThrow();
    } catch (const std::exception &ex) {
        std::cout << "Caught in main after throw: " << ex.what() << std::endl;

        // Access derived class method (will work as type is preserved)
        const CustomException *customEx = dynamic_cast<const CustomException*>(&ex);
        if (customEx) {
            std::cout << "Exception type: " << customEx->getType() << std::endl;
        } else {
            std::cout << "Exception type lost due to slicing.\n";
        }
    }

    return 0;
}
