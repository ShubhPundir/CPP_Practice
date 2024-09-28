#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(){
    list<int> li = {1,2,3,4,5};
    vector<int> vi(li.size());
    list<int>::iterator it1 = li.begin();
    vector<int>::iterator it2 = vi.begin();

    for(int i=0; i<3; i++){ // LINE - 1
        it1++; it2++;
    }

    copy(it1, li.end(), it2);

    for(it2=vi.begin(); it2 != vi.end(); ++it2)
        cout << *it2;

    
    return 0;
}