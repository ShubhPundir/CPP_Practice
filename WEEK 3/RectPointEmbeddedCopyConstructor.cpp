#include <iostream>
using namespace std;
class Point { int x_; int y_; public:
Point(int x, int y): x_(x), y_(y) { cout << "Point ctor: "; print(); cout << endl; } // Ctor
Point(): x_(0), y_(0) { cout << "Point ctor: "; print(); cout << endl; } // DCtor
Point(const Point& p): x_(p.x_), y_(p.y_) { cout << "Point cctor: "; print(); cout << endl; } // CCtor
~Point() { cout << "Point dtor: "; print(); cout << endl; } // Dtor
void print() { cout << "(" << x_ << ", " << y_ << ")"; } }; // Class Point

class Rect {
Point TL_; Point BR_;
public:
Rect(int tlx, int tly, int brx, int bry): TL_(tlx, tly), BR_(brx, bry) // Ctor o{ Rect: 4 coords
{ cout << "Rect ctor --> 4 coords: "; print(); cout << endl; } // Uses Ctor {or Point
Rect(const Point& p_tl, const Point& p_br): TL_(p_tl), BR_(p_br) // Ctor o{ Rect: 2 Points
{ cout << "Rect ctor --> 2 Points: "; print(); cout << endl; } // Uses CCtor {or Point
Rect(const Point& p_tl, int brx, int bry): TL_(p_tl), BR_(brx, bry) // Ctor o{ Rect: Point + 2 coords
{ cout << "Rect ctor: "; print(); cout << endl; } // Uses CCtor {or Point
Rect() { cout << "Rect ctor: "; print(); cout << endl; } // DCtor o{ Rect: // DCtor Point
Rect(const Rect& r): TL_(r.TL_), BR_(r.BR_) // CCtor o{ Rect
{ cout << "Rect cctor: "; print(); cout << endl; } // Uses CCtor {or Point
~Rect() { cout << endl<< "Rect dtor: "; print(); cout << endl; } // Dtor
void print() { cout << "["; TL_.print(); cout << " "; BR_.print(); cout << "]"; } }; // Class Rect


int main(){
    Rect r1(0,2,5,7);
    cout << endl;

    Rect r2(Point(1,4), Point(14,15));
    cout << endl;
}