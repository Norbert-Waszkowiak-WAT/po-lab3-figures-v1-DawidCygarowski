#include "quadrilateral.h"
#include <sstream>
#include <iomanip>
#include <cmath>
 
Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d): a(a), b(b), c(c), d(d) {}
 
Quadrilateral::Quadrilateral(const Quadrilateral &other): a(other.a), b(other.b), c(other.c), d(other.d) {}
 
bool Quadrilateral::equals(Quadrilateral &other){
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c) && d.equals(other.d);
}
 
void Quadrilateral::flip(){
    a.flip();
    b.flip();
    c.flip();
    d.flip();
}
 
void Quadrilateral::move(double x, double y){
    a.move(x,y);
    b.move(x,y);
    c.move(x,y);
    d.move(x,y);
}
 
static double triangleArea(Point &p1, Point &p2, Point &p3){
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    double x3 = p3.getX();
    double y3 = p3.getY();
    double area = 0.5 * std::fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    return area;
}
 
double Quadrilateral::getSurface(){
    return triangleArea(a,b,c) + triangleArea(a,c,d);
}
 
std::string Quadrilateral::toString(){
    std::ostringstream oss;
    oss << "Quadrilateral(" << a.toString() << ", " << b.toString() << ", " << c.toString() << ", " << d.toString() << ")";
    return oss.str();
}