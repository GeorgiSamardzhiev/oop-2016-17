#ifndef PYRAMID_H
#define PYRAMID_H

#include "point2d.h"
#include "point3d.h"

const int MAX = 1000;

class Pyramid{
private:
    Point3D A,B,C,D;
public:
    Pyramid();
    Pyramid(Point3D A, Point3D B, Point3D C, Point3D D); // more like Tetrahedron

    Point3D getA()const;
    Point3D getB()const;
    Point3D getC()const;
    Point3D getD()const;
    void print() const;

    double baseCircumference()const;
    double baseSurface()const;
    double volume()const;

    void setA(Point3D A);
    void setB(Point3D B);
    void setC(Point3D C);
    void setD(Point3D D);

    void read();


};
#endif // PYRAMID_H
