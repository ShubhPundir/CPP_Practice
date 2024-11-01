#include <iostream>
using namespace std;

template <typename T, int N> // LINE-1
class NPrint{
    T _v;
    public:
        NPrint(T v) : _v(v) {};
        void print(){
            for(int i=0; i<N; i++){
                cout << _v;
            }
        }
};
int main(){
    int n = 3;
    NPrint<char, n> np('C'); //LINE-2
    // A non constant expression cannot be passed as a template parameter as they
    // are calculated at compile time
    np.print();
    return 0;
}