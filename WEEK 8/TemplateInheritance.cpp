#include <vector>
#include <iostream>
using namespace std;

template <class T>
class List{
    public:
        void put(const T& val) { items.push_back(val);}
        int length() {return items.size();}
        bool find(const T& val){
            for(unsigned int i = 0; i < items.size(); i++){
                if (items[i] == val)
                    return true;
            }
            return false;
        }
    private:
        vector<T> items;
};

template<class T>
class Set{
    public:
        Set() { }
        virtual ~Set() { }
        virtual void add(const T& val);
        int length();
        bool find(const T& val);
    private:
        List<T> items;
};

template<class T>
void Set<T>::add(const T& val){
    if(items.find(val)) return;
    items.put(val);
}

template<class T> int Set<T>::length() {return items.length();}
template<class T> bool Set<T>::find(const T& val) {return items.find(val);}

template<class T>
class BoundSet : public Set<T>{
    public:
        BoundSet(const T& lower, const T& upper);
        void add(const T& val);
    private:
        T min; T max;
};

template <class T> BoundSet<T>::BoundSet(const T& lower, const T& upper) : min(lower), max(upper) { }
template <class T> void BoundSet<T>::add(const T& val) {
    if (this->find(val)) return; // Set<T>::find()
    if ((val <= max) && (val>=min))
        Set<T>::add(val);
}

int main(){
    BoundSet<int> bsi(3,21);
    Set<int> *setptr = &bsi;

    for(int i=0; i < 25; i++)
        setptr->add(i);
    
    if(bsi.find(4))
        cout << "FUCK YEA\n";
    
    if(!bsi.find(414))
        cout << "FUCK NO\n";
        
}