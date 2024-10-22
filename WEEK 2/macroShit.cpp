    #include <iostream>
    // #define SQUARE (x) (x)*(x)

    using namespace std;
    int inline SQUARE(int x){
        return x*x;
    }
    int main()
    {
        int a=3,b;
        b = SQUARE(++a);
        cout << b;
        return 0;
    }