#include "point.h"
#include <sstream>
#include <iostream>
#include <iomanip>
 
Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(const Point &other) : x(other.x), y(other.y) {}
bool Point::equals(Point &other){
    return (x == other.x && y == other.y);
}
double Point::getX(){
    return x;
}
double Point::getY(){
    return y;
}
void Point::flip(){
    x = -x;
    y = -y;
}
void Point::move(double x, double y){
    this ->x += x;
    this ->y += y;
}
std::string Point::toString(){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Point(" << x << ", " << y << ")";
    return oss.str();
}