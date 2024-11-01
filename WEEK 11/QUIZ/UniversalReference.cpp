template<typename T>
class Test{
    public:
        void f1(T&& n) {} // LINE-1

        template<typename U>
        void f2(U&& n) {} // LINE-2

        void f3(Test&& n) {} // LINE-3

        template<typename V>
        void f4(std::vector<V>&& n) {} // LINE-4 
};

// only LINE-2 is a universal reference

/*
    LINE-1: void f1(T&& n) {}
        This function uses an rvalue reference of type T. The T&& syntax here is not universal reference, but rather a true rvalue reference.
        This function only accepts arguments of type T that are rvalues, meaning it will fail to compile if you try to pass an lvalue of type T.
    LINE-2: template<typename U> void f2(U&& n) {}
        This is a universal reference. The U&& deduces to U& if n is an lvalue and to U&& if n is an rvalue.
        This function can accept arguments of any type (lvalues or rvalues of any type), thanks to type deduction and reference collapsing.
    LINE-3: void f3(Test&& n) {}
        This function takes an rvalue reference to an object of type Test.
        It will only accept an rvalue of type Test. This is a true rvalue reference, not a universal reference, as it doesn't involve template deduction.
    LINE-4: template<typename V> void f4(std::vector<V>&& n) {}
        This is a template function that accepts an rvalue reference to a std::vector<V> where V can be any type.
        This function will only accept rvalues of type std::vector<V> for any V. It will not accept lvalues of std::vector<V> or any other type.
*/