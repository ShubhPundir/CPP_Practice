#include <iostream>
#include <future>
#include <vector>
using namespace std;

struct Calc_sum{
    std::vector<double> dv;
    Calc_sum(const std::vector<double> dv_) : dv(dv_) {}
    double operator()(){
        double sum = 0.0;
        for(double i: dv)
            sum += i;
        return sum;
    }
};

double makeThreadedCall(const std::vector<double> dv){
    auto as = std::async(Calc_sum) // LINE-1
    return as.get();
}

int main(){
    std::vector<double> arr {2.3, 4.5, 6.3, 2.3, 5.6, 3.5};
    cout << makeThreadedCall(arr)
}