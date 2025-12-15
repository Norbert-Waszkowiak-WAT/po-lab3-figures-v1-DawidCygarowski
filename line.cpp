#include "point.h"
#include "line.h"
 
 
Line::Line(Point a, Point b): a(a), b(b) {}
Line::Line(const Line &other): a(other.a), b(other.b) {}
bool Line::equals(Line &other){
    return (a.equals(other.a) && b.equals(other.b));
}
void Line::flip(){
    a.flip();
    b.flip();
}
void Line::move(double x, double y){
    a.move(x, y);
    b.move(x, y);
}
std::string Line::toString(){
    return "Line(" + a.toString() + ", " + b.toString() + ")";
}