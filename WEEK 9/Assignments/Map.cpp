#include <iostream>
#include <map>
#include <list>

std::map<int, int> Frequency(std::list<int> li){
    std::map<int, int> fq; 
    for (std::list<int>::iterator it=li.begin(); it!=li.end(); it++)   //LINE-1
        fq[*it]++;
    return fq;
}

void print(std::map<int, int> fq){
    for (std::map<int,int>::iterator it=fq.begin(); it!=fq.end(); it++)    //LINE-2
        std::cout << it->first << " => " << it->second << ", ";
}
int main() { 
    std::list<int> li = {1,1,2,3,4,2,4,4,4};
    // int a;
    // for(int i = 0; i < 10; i++){
    //     std::cin >> a;
    //     li.push_back(a);
    // }
    std::map<int, int> fq = Frequency(li); 
    print(fq);	
    return 0;
}