#include <iostream>
using namespace std;

class emp{
    private:
        int id_ {-1};
        double salary_ {0.0};
        static constexpr double dSalary = 5500.0;
    public: 
        explicit emp(): emp(0) {cout << "1" << endl;}  
        explicit emp(const int i): emp(i, dSalary) {cout << "2" << endl;}  
        explicit emp(const double s): emp(0, s) {cout << "3" << endl;}
        explicit emp(int i, double s): id_{i}, salary_{s} {cout << "4" << endl;}    
};

int main(){
    emp e1;
}
