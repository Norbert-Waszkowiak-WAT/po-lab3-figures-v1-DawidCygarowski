#include "point.h"
#include "triangle.h"
#include <cmath>
 
Triangle::Triangle(Point a, Point b, Point c): a(a), b(b), c(c) {}
Triangle::Triangle(const Triangle &other): a(other.a), b(other.b), c(other.c) {}
 
bool Triangle::equals(Triangle &other){
    return (a.equals(other.a) && b.equals(other.b)) && c.equals(other.c);
}
 
void Triangle::flip(){
    a.flip();
    b.flip();
    c.flip();
}
 
void Triangle::move(double x, double y){
    a.move(x, y);
    b.move(x, y);
    c.move(x, y);
}
 
std::string Triangle::toString(){
    return "Triangle(" + a.toString() + ", " + b.toString() + ", " + c.toString() + ")";
}
 
double Triangle::getSurface(){
    double side_ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
    double side_bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
    double side_ca = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2));
    double s = (side_ab + side_bc + side_ca) / 2;
    return sqrt(s * (s - side_ab) * (s - side_bc) * (s - side_ca));
}
