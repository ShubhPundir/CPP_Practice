#include <iostream>
#include <cstring>
using namespace std;

template<class T>
T Max(T x, T y){
    return x > y ? x : y;
}

template<>
char *Max<char *>(char* x, char* y) {
    return strcmp(x,y) > 0 ? x : y;
}

template <class T, int size>
T Max(T x[]){

    int maximum = x[0];
    for(int i=1; i<size; i++){
        if(maximum < x[i])
            maximum = x[i];
    }
    return maximum;
}

int main(){
    int a = 3, b = 5, iMax;
    double c = 2.1, d = 3.4, dMax;
    char *s1 = new char[6], *s2 = new char[6];
    strcpy(s1, "black"); strcpy(s2, "white");

    iMax = Max<int>(a,b);
    cout << "Max of " << a << " and " << b << " is " << iMax << endl;

    dMax = Max<double>(c,d);
    cout << "Max of " << c << " and " << d << " is " << dMax << endl;

    cout << "Max of " << s1 << " and " << s2 << " is " << Max<char*>(s1,s2) << endl;

    int arr[8] = {1,2,34,5,-2, 333, 0, -4213};
    cout << "Max of array is " << Max<int,8>(arr) << endl;

}