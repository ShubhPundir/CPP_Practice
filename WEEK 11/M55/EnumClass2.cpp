#include <iostream>
using namespace std;

enum class Color : unsigned int { Bronze, Silver, Gold};
enum class Bullion : std::uint8_t { Silver, Gold};
enum class Metal : char { Silver, Gold, Platinum};
enum class CreditCard { Silver, Gold, Platinum}; // underlying type = int

