#include <iostream>
using namespace std;

template<typename T>
T test = T(2.541);

int main(){
    test<int> = 100;
    auto cm_2_m = [](auto(cm)){return cm * test<decltype(cm)>;}(100); // 100 * 100
    auto cm_2_in = [](auto(cm)){return cm * test<decltype(cm)>;}(100.0); // 100 * 2.541

    cout << cm_2_m << " " << cm_2_in;
} // 1000 254.1