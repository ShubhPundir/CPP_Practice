#include <iostream>
using namespace std;

int main(){
    const double g = 9.81;
    const double *pg = &g;

    double *pt = const_cast<double*>(pg);
    *pt = 10;

    cout << *pt << " " << g;
    return 0;

}