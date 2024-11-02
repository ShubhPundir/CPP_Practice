#include<iostream>
class testArray{
    public:
        virtual void what(){ std::cout << "index out of array"; }
};
class InvalidElement{
    public:
        virtual void what(){ std::cout << "invalid"; }
};
template <typename T, int N> //LINE-1
class plist{
    T arr_[N];
    public:
        plist(){
            for(int i = 0; i < N; i++)
                arr_[i] = -1;
        }
        //LINE-2: impelement insert() function
        void insert(int i , T val){
            if(i < N)
                arr_[i] = val;  
            else	
                throw testArray();
        }
        
        //LINE-3: impelement peek() function
        T peek(int i){
            if(arr_[i] < 0)
                throw InvalidElement();
            else
                return arr_[i];
        }
};
int main(){
    int n;
    char c;
    plist<char, 4> li;
    try{
        for(int i = 0; i < 4; i++){
            std::cin >> n;
            std::cin >> c;
            li.insert(n, c);
        }
    }catch(testArray& e){
        e.what();
        std::cout << std::endl;
    }
    for(int i = 0; i < 4; i++){
        try{
            std::cout << li.peek(i) << ", ";
        }catch(InvalidElement& e){
            e.what();
            std::cout << ", ";
        }
    }
    return 0;
}