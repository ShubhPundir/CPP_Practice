#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
using namespace std;

struct st_A{
    int A_count = 0;
};

struct st_B{
    int B_count = 0;
};

std::mutex A_mtx;
std::mutex B_mtx;

void request1(st_A& aObj, st_B& bObj, int an, int bn){
    std::unique_lock<std::mutex> lck1(A_mtx);
    std::unique_lock<std::mutex> lck2(B_mtx);

    aObj.A_count += an;
    bObj.B_count += bn;

    cout << "R1: " << aObj.A_count << " " << bObj.B_count << endl;
}

void request2(st_A& aObj, st_B& bObj, int an, int bn){
    std::unique_lock<std::mutex> lck2(B_mtx);
    std::unique_lock<std::mutex> lck1(A_mtx);

    aObj.A_count += an;
    bObj.B_count += bn;

    cout << "R2: " << aObj.A_count << " " << bObj.B_count << endl;
}

int main(){
    st_A rA;
    st_B rB;

    std::thread t1{std::bind(request1, std::ref(rA), std::ref(rB), 10, 10) };
    std::thread t2{std::bind(request2, std::ref(rA), std::ref(rB), 20, 20) };

    t1.join(); t2.join();

}