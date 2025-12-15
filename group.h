#ifndef GROUP
#define GROUP
#include "line.h"
#include "quadrilateral.h"
#include "triangle.h"
#include <string>
#include <vector>
 
using namespace std;
 
class Group{
    private:
        vector<Line> lines;
        vector<Triangle> triangles;
        vector<Quadrilateral> quadrilaterals;
    public:
        Group();
        Group(const Group &other);
        bool equals(Group &other);
        void flip();
        void move(double x, double y);
        double getSurface();
        string toString();
        void remove(Line t);
        void remove(Triangle t);
        void remove(Quadrilateral t);
        void add(Line t);
        void add(Triangle t);
        void add(Quadrilateral t);
 
 
 
 
};
#endif