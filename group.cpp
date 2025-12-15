#include "group.h"
#include "line.h"
#include "quadrilateral.h"
#include "triangle.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
Group::Group(){}
 
Group::Group(const Group &other): lines(other.lines), triangles(other.triangles), quadrilaterals(other.quadrilaterals) {}
 
bool Group::equals(Group &other){
    if (lines.size() != other.lines.size() ||
        triangles.size() != other.triangles.size() ||
        quadrilaterals.size() != other.quadrilaterals.size()) {
        return false;
    }
   
    for(vector<Line>::size_type i = 0; i < lines.size(); i++){
        if(!lines[i].equals(other.lines[i])){
            return false;
        }
    }
   
    for(vector<Triangle>::size_type i = 0; i < triangles.size(); i++){
        if(!triangles[i].equals(other.triangles[i])){
            return false;
        }
    }
   
    for(vector<Quadrilateral>::size_type i = 0; i < quadrilaterals.size(); i++){
        if(!quadrilaterals[i].equals(other.quadrilaterals[i])){
            return false;
        }
    }
   
    return true;
}
 
void Group::flip(){
    for(vector<Line>::size_type i = 0; i < lines.size(); i++){
        lines[i].flip();
    }
    for(vector<Triangle>::size_type i = 0; i < triangles.size(); i++){
        triangles[i].flip();
    }
    for(vector<Quadrilateral>::size_type i = 0; i < quadrilaterals.size(); i++){
        quadrilaterals[i].flip();
    }
}
 
void Group::move(double x, double y){
    for(vector<Line>::size_type i = 0; i < lines.size(); i++){
        lines[i].move(x, y);
    }
    for(vector<Triangle>::size_type i = 0; i < triangles.size(); i++){
        triangles[i].move(x, y);
    }
    for(vector<Quadrilateral>::size_type i = 0; i < quadrilaterals.size(); i++){
        quadrilaterals[i].move(x, y);
    }
}
 
double Group::getSurface(){
    double surface = 0;
    for(vector<Triangle>::size_type i = 0; i < triangles.size(); i++){
        surface += triangles[i].getSurface();
    }
    for(vector<Quadrilateral>::size_type i = 0; i < quadrilaterals.size(); i++){
        surface += quadrilaterals[i].getSurface();
    }
    return surface;
}
 
string Group::toString(){
    if (lines.empty() && triangles.empty() && quadrilaterals.empty()) {
        return "Group()";
    }
   
    string result = "Group(";
   
    for(vector<Line>::size_type i = 0; i < lines.size(); i++){
        result += lines[i].toString();
        result += ", ";
    }
   
    for(vector<Triangle>::size_type i = 0; i < triangles.size(); i++){
        result += triangles[i].toString();
        result += ", ";
    }
   
    for(vector<Quadrilateral>::size_type i = 0; i < quadrilaterals.size(); i++){
        result += quadrilaterals[i].toString();
        result += ", ";
    }
   
    result += ")";
   
    return result;
}
 
void Group::remove(Line t){
    for(vector<Line>::iterator it = lines.begin(); it != lines.end(); ++it){
        if(it->equals(t)){
            lines.erase(it);
            return;
        }
    }
}
 
void Group::remove(Triangle t){
    for(vector<Triangle>::iterator it = triangles.begin(); it != triangles.end(); ++it){
        if(it->equals(t)){
            triangles.erase(it);
            return;
        }
    }
}
 
void Group::remove(Quadrilateral t){
    for(vector<Quadrilateral>::iterator it = quadrilaterals.begin(); it != quadrilaterals.end(); ++it){
        if(it->equals(t)){
            quadrilaterals.erase(it);
            return;
        }
    }
}
 
void Group::add(Line t){
    lines.push_back(t);
}
 
void Group::add(Triangle t){
    triangles.push_back(t);
}
 
void Group::add(Quadrilateral t){
    quadrilaterals.push_back(t);
}