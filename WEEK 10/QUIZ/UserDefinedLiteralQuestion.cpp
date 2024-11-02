#include <iostream>
#include <iomanip>

long double operator "" _M(long double x){
    return x*100;
}

long double operator "" _CM(long double x){
    return x;
}

unsigned long long operator "" _M(unsigned long long x){
    return x*100;
}

unsigned long long operator "" _CM(unsigned long long x){
    return x;
}

class Distance{
    public:
        Distance(int d1, int d2) : d1_(d1), d2_(d2) {}
        int getDistance() {return d1_ + d2_;}
    private:
        int d1_, d2_;
};

int main(){
    // Distance d(10.0_M, 19.0_CM);
    Distance d(10_M, 19_CM);
    std::cout << d.getDistance() << "CM";
}
