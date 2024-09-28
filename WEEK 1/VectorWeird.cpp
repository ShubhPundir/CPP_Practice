#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int size = 4, c = 100;
    vector<int> vi(size,5);
    // creates a vector of size=4 in which, all are initialzed default as 5
    // 5,5,5,5

    for(int i=1; i<=3; i++)
        vi.push_back(c+i); // starts out as 100 + 1, 100 + 2, 100 + 3
    
    // 5,5,5,5,101,102,103 
    vi.resize(12,99);
    // extra values are filled wuth the number 99
    // 5,5,5,5,101,102,103,99,99,99,99,99
    // vi.size() = 12

    vi.resize(10); // the size of vi is restricted to 10 now

    cout << vi.size() << " ";
    cout << "\n";
    for(int i=0; vi.size(); i++) // vi.size() is 10 
        cout << vi[i] << " ";

    // final vector: 5,5,5,5,101,102,103,99,99 
    return 0;
}
