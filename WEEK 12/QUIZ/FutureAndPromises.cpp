#include <iostream>
#include <thread>
#include <future>
#include <vector>
using namespace std;

void change(std::promise<std::vector<int>>& pr, std::future<std::vector<int>>& fu){
    std::vector<int> v = fu.get();
    std::vector<int> res;
    long sum = 0;

    for(auto i: v)
        res.push_back(i*i);
    pr.set_value(res);
}
int main(){
    std::promise<std::vector<int>> p1;
    std::future<std::vector<int>> f1 = p1.get_future();

    std::promise<std::vector<int>> p2;
    std::future<std::vector<int>> f2 = p2.get_future();

    std::thread th{change, std::ref(p2), std::ref(f1)};

    std::vector<int> v {10, 20, 30, 40};

    p1.set_value(v); // LINE-1
    auto rv = f2.get(); // LINE-2

    for(auto i: rv)
        cout << i << " ";
    th.join();

}