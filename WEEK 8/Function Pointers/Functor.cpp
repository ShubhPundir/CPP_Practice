#include <iostream>
using namespace std;

int AdderFunction(int a, int b){ // a function
    return a+b;
}

class AdderFunctor{

    public:
        AdderFunctor(int p, int q) { }
        int operator()(int a, int b){ // a functor
            return a+b;
        }
};

int main(){
    int x = 1, y = 12;
    int z = AdderFunction(x,y);

    AdderFunctor aF(x,y);
    int w = aF(x,y);

    cout << z << " " << w << endl;
}