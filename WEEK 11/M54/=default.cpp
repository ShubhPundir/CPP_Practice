class Y{
    Y& operator=(const Y&) =default;
    Y(const Y&) = default;
};

// Or change normal accessibility, explicitness, virtualness:
class Widget {
    public:
        virtual ~Widget() = default; // declare as virtual
        explicit Widget(const Widget&) = default; // declare as explicit
        private:
            Widget& operator=(Widget&&) noexcept = default; // declare as private
};
