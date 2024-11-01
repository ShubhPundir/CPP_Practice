#include <iostream>
using namespace std;

class computation{
    public:
        int addition(int a, int b){
            return a+b;
        }
        int subtraction(int a, int b){
            return a-b;
        }
};

// int caller(const int& x, const int& y, computation* obj, int(computation::*fp)(int, int)){ // will work
int caller(int x, int y, computation* obj, int(computation::*fp)(int, int)){
    return (obj->*fp)(x,y);
}

int main(){
    computation cm;
    cout << caller(10, 20, &cm, &computation::addition) << " ";
    cout << caller(10, 20, &cm, &computation::subtraction) << " ";
}