#include "quadrilateral.cpp"
#include <cmath>
#include <sstream>

// Konstruktor domyślny (czworokąt zerowy)
Quadrilateral::Quadrilateral()
    : a(), b(), c(), d() { }

Quadrilateral::Quadrilateral(const Point &a_, const Point &b_, const Point &c_, const Point &d_)
    : a(a_), b(b_), c(c_), d(d_) { }

Quadrilateral::Quadrilateral(const Quadrilateral &other)
    : a(other.a), b(other.b), c(other.c), d(other.d) { }

bool Quadrilateral::equals(const Quadrilateral &other, double eps) const {
    return a.equals(other.a, eps)
        && b.equals(other.b, eps)
        && c.equals(other.c, eps)
        && d.equals(other.d, eps);
}

void Quadrilateral::flip() {
    // Odwracamy kolejność wierzchołków zachowując 'a' jako pierwszy:
    // a, b, c, d -> a, d, c, b
    Point oldB = b;
    Point oldD = d;
    b = oldD;
    d = oldB;
    // c pozostaje na swoim miejscu (środek pary)
}

// Przesunięcie o (dx, dy)
void Quadrilateral::move(double dx, double dy) {
    a.x += dx; a.y += dy;
    b.x += dx; b.y += dy;
    c.x += dx; c.y += dy;
    d.x += dx; d.y += dy;
}

// Pole czworokąta liczymy wzorem shoelace (gauss) dla czterech punktów
double Quadrilateral::getSurface() const {
    // Wzór: 0.5 * | sum_{i=0}^{n-1} x_i*y_{i+1} - x_{i+1}*y_i |
    // z indeksami cyklicznymi; n = 4
    double xs[4] = { a.x, b.x, c.x, d.x };
    double ys[4] = { a.y, b.y, c.y, d.y };
    double sum = 0.0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        sum += xs[i] * ys[j] - xs[j] * ys[i];
    }
    return std::fabs(sum) * 0.5;
}

std::string Quadrilateral::toString() const {
    std::ostringstream oss;
    oss << "Quadrilateral:\n"
        << "  a: " << a.toString() << "\n"
        << "  b: " << b.toString() << "\n"
        << "  c: " << c.toString() << "\n"
        << "  d: " << d.toString() << "\n"
        << "  surface: " << getSurface();
    return oss.str();
}