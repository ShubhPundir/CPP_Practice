#include <iostream>

template<class Itr, class T>
int findMax(Itr first, Itr last, T& mval){
    int maxPos = 0, i = 0;
    mval = *first++;

    while(first!=last){
        if(*first > mval){
            mval = *first;
            maxPos = i + 1;
        }
        ++first;
        ++i;
    }
    return maxPos;
}

int main(){
    int iArr[] = {1, 4, 8, 1, 3, 8, 7};
    double mVal = 0.0;

    // int pos = findMax(iArr, iArr + sizeof(iArr)/sizeof(*iArr), mVal );

    int pos = findMax(iArr, &iArr[sizeof(iArr)/sizeof(*iArr)], mVal );


    std::cout << pos << ", " << mVal;
    return 0;
}