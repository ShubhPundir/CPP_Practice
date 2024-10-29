#include <iostream>
using namespace std;

enum Alert { green, yellow, orange, red};
enum class Color { red, blue};
enum class TrafficLight { red, yellow, green};
/*
    enum class: This is a scoped enumeration, introduced in C++11,
    that does not IMPLICITLY convert to integers. 
    So Color c = 7; is not allowed, providing stronger type safety.
*/
int main(){
    // Alert a = 7; // Implicit conversion is not type safe, but allowed in classic enum
    // Color c = 7;

    int a2 = red;
    int a3 = Alert::red; // Valid as it is using enum from C++03
    // int a4 = blue; // error
    // int a5 = Color::blue; // no Color to int initialization
    
    Color a6 = Color::blue;
}