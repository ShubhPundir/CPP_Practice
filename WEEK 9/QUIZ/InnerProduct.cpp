#include <iostream>
#include <list>
#include <vector>
#include <numeric>
using namespace std;

int operation1(int i, int j) { return i+j;}
int operation2(int i, int j) { return i*j;}

int main(){
    vector<int> vi {1,2,3};
    list<int> li {10,20,30};

    // 10 + 40 + 90 = 140
    // int n = inner_product(vi.begin(), vi.end(), li.begin(), 0, operation1, operation2);
    int n = inner_product(li.begin(), li.end(), vi.begin(), 0, operation1, operation2);
    cout << n;
    return 0;
}
