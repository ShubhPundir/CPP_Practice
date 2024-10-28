#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

struct machine{
    vector<std::function<int(int)>> to_do;

    template<typename T>
    void add(T f){ to_do.push_back(f);}
    int run(int v){
        for_each(to_do.begin(), to_do.end(), [&v](std::function<int(int)> f){
            v = f(v);
        });
        return v;
    }
};

int foo(int i) { return i + 4;}

int main(){
    machine m;
    m.add([](int i){return i*3;});
    m.add(foo);
    m.add([](int i){return i/5;});
    cout << "run(7): " << m.run(7) << endl;
    // 7 * 3 = 21
    // 21 + 4 = 25
    // 25 / 5 = 5
    // 5 is the final answer
}