#include <iostream>
template <typename T>
class Test{
    public:
        Test() = delete;
        Test(T _i) :i(_i) {}
        Test(const Test&) = delete;
        Test(Test&&) = default;
    private:
        T i;
};

int main(){
    Test<int> d1; // LINE-1
    Test<int> d2(5); // LINE-2
    Test<int> d3 = d2; // LINE-3
    Test<int> d4 = std::move(d2); // LINE-4
}

// LINE-1 and LINE-3