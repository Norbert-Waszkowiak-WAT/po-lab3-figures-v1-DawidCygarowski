#ifndef POINT_CPP
#define POINT_CPP

#include <cmath>
#include <sstream>
#include <string>

struct Point {
    double x;
    double y;

    Point() : x(0.0), y(0.0) {}
    Point(double x_, double y_) : x(x_), y(y_) {}

    bool equals(const Point &other, double eps = 1e-9) const {
        return std::fabs(x - other.x) <= eps && std::fabs(y - other.y) <= eps;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

#endif