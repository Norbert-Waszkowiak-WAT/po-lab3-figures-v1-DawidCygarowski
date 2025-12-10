#ifndef QUADRILATERAL.CPP
#define QUADRILATERAL.CPP

#include "point.cpp"
#include <string>

class Quadrilateral {
public:
    Point a;
    Point b;
    Point c;
    Point d;

    Quadrilateral();
    Quadrilateral(const Point &a_, const Point &b_, const Point &c_, const Point &d_);
    Quadrilateral(const Quadrilateral &other);

    bool equals(const Quadrilateral &other, double eps = 1e-9) const;
    void flip(); // odwraca kolejność wierzchołków (zmienia orientację)
    void move(double dx, double dy);
    double getSurface() const; // pole powierzchni (shoelace)
    std::string toString() const;
};

#endif