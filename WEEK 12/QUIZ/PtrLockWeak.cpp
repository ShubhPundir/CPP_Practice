#include <iostream>
#include <memory>
using namespace std;

void update_share_ptrs(std::shared_ptr<int> sp1, std::shared_ptr<int>& sp2){
    sp1.reset(new int(0));
    sp2.reset(new int(0));
}
/*
    The lock() method of std::weak_ptr attempts to create a std::shared_ptr 
    that shares ownership of the object. If the object still exists 
    (i.e., there are one or more std::shared_ptrs managing it), 
    lock() returns a std::shared_ptr pointing to the object. 
    
    If the object has already been destroyed 
    (i.e., the last std::shared_ptr managing it has been destroyed), 
    lock() returns a null std::shared_ptr.
*/
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
    // cout << *p1 << " " << *p2 << endl;
    testAndPrint(wp1);
    testAndPrint(wp2);

    cout << endl;

    update_share_ptrs(p2, p1);
    testAndPrint(wp1);
    testAndPrint(wp2);
}