// Initializer list must be homogeneous
#include <iostream>
#include <vector> 
using namespace std;

// template<class E>
// class vector{
//     public:
//         vector(std::initializer_list<E> s){
//             reserve(s.size());
//             uninitialized_copy(s.begin(), s.end(), elem);
//             sz = s.size();
//         }
// };

void f(initializer_list<int> args){
    for(auto p=args.begin(); p!=args.end(); ++p){
        cout << *p << " ";
    }
    cout << endl;
}

int main(){

    vector<double> v1(7); // v1 has 7 elements
    // cout << v1.size() << endl;
    v1 = {1, 2.21, 3.14, 5, 4.1, 7, 3.0, 8};
    // cout << v1.size() << endl;

    vector<double> v2{7}; // v2 has 1 element of value 7.0
    // cout <<v2.size();
     
    vector<int> wow = {
        vector<int>{1,2,3}
    }; // never do this again
    // is that you're trying to initialize a vector<int> with another vector<int>, but this is not allowed

    vector<vector<int>> wow2 = {
        vector<int>(10),  // vector of size 10 initialized to 0
        vector<int>{10},  // vector containing a single element 10
        vector<int>{10, 20, 30}  // another vector with 3 elements
    };

    // Nested loop to print the elements of wow
    for (const auto& inner_vec : wow2) {
        for (const auto& elem : inner_vec) {
            cout << elem << " ";
        }
        cout << endl;  // New line after each inner vector
    }

    f({1,2,3,4});
}