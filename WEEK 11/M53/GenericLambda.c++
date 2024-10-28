#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printElements(auto C){
    for(auto e:C)
        cout << e << " ";
    cout << endl;
}

int main(){
    auto greater = [](auto a, auto b) -> bool {return a>b;};

    vector<int> vi = {1, 4, 2, 1, 6, 62, 636};
    vector<double> vd = {4.62, 161.3, 62.26, 13.4, 235.5};
    vector<string> vs = {"Tom", "Harry", "Ram", "Shyam"};

    sort(vi.begin(), vi.end(), greater);
    sort(vd.begin(), vd.end(), greater);
    sort(vs.begin(), vs.end(), greater);

    printElements(vi);
    printElements(vd);
    printElements(vs);
}