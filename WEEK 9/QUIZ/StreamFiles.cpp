#include <iostream>
#include <fstream>

int main(){
    std::ifstream inf("in.txt");
    std::string line;

    if(!inf.is_open()){
       std::cout << "file is not opened"; 
    }
    else{
        while(getline(inf, line))
            std::cout << line << std::endl;
        inf.close();
    }
    return 0;
}