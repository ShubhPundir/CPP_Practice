#include <iostream>
#include <list>
using namespace std;

int main(){
    // auto test = [d, &sum](std::list<int> l){
    //     for(auto i: l)
    //         sum += i;
    //     return (double) sum / l.size();
    // };

    struct A{
        int d; int& sum;
        A(int d_, int& sum_) : d(d_) , sum(sum_) {}
        void operator()(std::list<int> l, double& avg) const{
            for(auto i: l)
                sum += i;
            
            avg = (double)sum/l.size();
        }       
    };

    struct B{
        int d; int& sum;
        B(int d_, int& sum) : d(d_), sum(sum_){}
        operator()(std::list<int> l){
            for(auto i: l)
                sum += i;
            return (double) sum / l.size();
        }
    };

    struct C{
        int d; int sum;
        C(int d_, int sum) : d(d_), sum(sum_){}
        double operator()(std::list<int> l) const{
            for(auto i: l)
                sum += i;
            return (double) sum / l.size();
        }
    };

    struct D{
        int d; int& sum;
        D(int d_, int& sum) : d(d_), sum(sum_){}
        double operator()(std::list<int> l) const{
            for(auto i: l)
                sum += i;
            return (double) sum / l.size();
        }
    };


    auto test = D(d,sum);

}