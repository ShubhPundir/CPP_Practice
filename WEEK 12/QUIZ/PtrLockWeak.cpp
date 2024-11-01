#include <iostream>
#include <memory>
using namespace std;

void update_share_ptrs(std::shared_ptr<int> sp1, std::shared_ptr<int>& sp2){
    sp1.reset(new int(10));
    sp2.reset(new int(10));
}

void testAndPrint(const std::weak_ptr<int>& wp){
    if(auto p = wp.lock())
        cout << *p << " ";
    else
        cout << "expired ";
}

int main(){
    auto p1 = std::make_shared<int>(1);
    auto p2 = p1;
    std::weak_ptr<int> wp1 = p1;
    std::weak_ptr<int> wp2 = p2;
    
    update_share_ptrs(p1, p2);
    testAndPrint(wp1);
    testAndPrint(wp2);

    update_share_ptrs(p2, p1);
    testAndPrint(wp1);
    testAndPrint(wp2);
}