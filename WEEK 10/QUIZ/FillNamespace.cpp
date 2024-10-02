#include <iostream>

namespace ns1{
    double dct = 0.05;
    double getVal(double pri){
        return pri*dct;
    }
}

inline namespace ns2{
    double dct = 0.07;
    template<typename T>
    T getVal(T pri){
        return pri*dct;
    }
}
int main(){
    std::cout << ns1::getVal(105.0) << " ";
    std::cout << ns2::getVal(105) << " " << getVal(105.0);
}