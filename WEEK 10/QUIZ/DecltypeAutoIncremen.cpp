int main(){
    int n = 10;
    int& a= n;
    const int& b = 10;

    auto x1 = a;
    auto x2 = b;
    decltype(a) x3 = a;
    decltype(b) x4 = a;

    ++x1;
    ++x2;
    ++x3;
    // ++x4;

}