#include <iostream>
#include <cmath>
#include "pyramid.h"
#include "point2d.h"
#include "point3d.h"

double det(Point3D A, Point3D B, Point3D C){
    return A.getX()*B.getY()*C.getZ()+
            B.getX()*C.getY()*A.getZ() +
            C.getX()*A.getY()*B.getZ() -
            C.getX()*B.getY()*A.getZ() -
            A.getX()*C.getY()*B.getZ() -
            B.getX()*A.getY()*C.getZ();
}

Pyramid::Pyramid(){}
Pyramid::Pyramid(Point3D A, Point3D B, Point3D C, Point3D D):A(0,0,0), B(0,0,0), C(0,0,0), D(0,0,0){
    if ((det(A, B, C) == 0) && (det(A, B, D)) != 0){
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

}

Point3D Pyramid::getA()const{
    return this->A;
}

Point3D Pyramid::getB()const{
    return this->B;
}

Point3D Pyramid::getC()const{
    return this->C;
}

Point3D Pyramid::getD()const{
    return this->D;
}

void Pyramid::print() const{
    std::cout<<'{';
    getA().print();
    std::cout<<',';
    getB().print();
    std::cout<<',';
    getC().print();
    std::cout<<',';
    getD().print();
    std::cout<<'}';
}

double Pyramid::baseCircumference()const{
    return B.distance(C)+A.distance(C)+ A.distance(B);
}

double Pyramid::baseSurface()const {
    double distAB, distAC, distBC;
    distAB = A.distance(B);
    distAC = A.distance(C);
    distBC = B.distance(C);
    double p = baseCircumference()/2;
    return sqrt(p*(p-distAB)*(p-distAC)*(p-distBC));
}

double Pyramid::volume()const{
    Point3D AC = C, AB = B, AD = D;
    AC.translate(-A);
    AB.translate(-A);
    AD.translate(-A);
    return det(AC, AB, AD)/6;

}

void Pyramid::setA(Point3D A){
    if ((det(A, B, C) == 0) && (det(A, B, D)) != 0)
        this->A = A;
}

void Pyramid::setB(Point3D B){
    if ((det(A, B, C) == 0) && (det(A, B, D)) != 0)
        this->B = B;
}

void Pyramid::setC(Point3D C){
    if ((det(A, B, C) == 0) && (det(A, B, D)) != 0)
        this->C = C;
}

void Pyramid::setD(Point3D D){
    if ((det(A, B, C) == 0) && (det(A, B, D)) != 0)
        this->D = D;
}

void Pyramid::read(){
    std::cout<<"Enter point A"<<std::endl;
    A.read();
    std::cout<<"Enter point B"<<std::endl;
    B.read();
    std::cout<<"Enter point C"<<std::endl;
    C.read();
    std::cout<<"Enter point D"<<std::endl;
    D.read();

}
