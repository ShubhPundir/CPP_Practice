#include<iostream>
#include<algorithm>
#include<vector>
struct average {
    int cnt_; //count of element
    int ss_; //sum of square of elements

    average(int cnt=0, int ss=0) : cnt_(cnt), ss_(ss) {} //LINE-1

  void operator() (int x) {ss_ += x*x; ++cnt_;} //LINE-2
};
int main(){
    std::vector<int> v {1,2,3};
    // int n = 3;
    // std::cin >> n;
    // for(int i = 0; i < n; i++){
    //     // std::cin >> a;
    //     v.push_back(a);
    // }
    average mi = for_each(v.begin(), v.end(), average());
    
    std::cout << "mean = " << (double)mi.ss_/mi.cnt_;
    return 0;
} // 1 + 4 + 9 = 14/3 = 4.667