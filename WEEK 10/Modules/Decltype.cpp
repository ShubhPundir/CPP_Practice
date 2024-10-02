#include <iostream>
#include <vector>
using namespace std;

template<class T, class U>
vector<decltype(T() * U())> multiply(const vector<T>& vt, const vector<U>& vu){

    typedef decltype(vt[0]*vu[0]) Tmp; // typedef double Tmp
    vector<Tmp> result;

    for(int i=0; i<vt.size(); i++){
        result.push_back(vt[i] * vu[i]);
        // cout <<  <<endl;
    }
    return result;
}


int main(){

    vector<int> vi = {1,2,3,4,5};
    vector<double> vd = {1.0, 2.2, 3.0, 4.0, 5.0};

    auto result = multiply(vi,vd);
    for(auto& r: result){
        if (r!=4.4)
            cout << r << endl;
        else
            cout << "Fukc" << endl; 
    }


}