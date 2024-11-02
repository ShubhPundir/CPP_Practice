#include <iostream>
#include <list>
using namespace std;

struct divide{
    int d_;
    divide(int d=1) : d_(d) { }
    bool operator()(int i) {return (i%d_ == 0);}
};

template<class T, class P>
T find_if(T first, T last, P pred) {
    while(first!=last && !pred(*first)) ++first;
        return first;
}

void show(list<int> li, int d){
    divide divi(d);
    list<int>::iterator it = find_if(li.begin(), li.end(), divi);
    // cout << *it << " ";  
    // list<int>::iterator it = li.begin();
    cout << "GladWeCouldGetThatOuttaOurWay ";
    while(it!=li.end()){
        cout << *it << " ";
        it = find_if(++it, li.end(), divi);
    }
}

int main(){
    list<int> li {7, 8, 1, 4, 2, 5, 16, 3};
    int d;
    show(li, 4);
    return 0;
}