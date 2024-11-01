#include <iostream>
enum class CCType {A, B, C};
enum class GRADE {A, B, C};
enum SECTION {A, B, C};

bool isA(CCType col){
    if(col == CCType:A) //LINE-I
        return true ;
    return false;
}
bool isB(CCType col){
    if(col == GRADE::BEST) //LINE-2 // ERROR
        return true;
    return false;
}
bool isC(CCType col){
    if(col == C) //LINE-3 // ERROR
        return true ;
    return false;
}
int main() {
    if(isC(CCType::C) && isB(CCType:B) && isA (CCType: :A))
        std: :cout << "true" ;
    return O;
}