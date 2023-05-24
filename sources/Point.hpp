#pragma once
#include <math.h>
#include <iostream>
using namespace std;
namespace ariel{

class Point{

double x;
double y;


public:

Point(double xPoint, double yPoint):x(xPoint),y(yPoint){}
Point():x(0.0),y(0.0){}

double distance(const Point &other) const
{
    double dis=0;
    double ysub= this->y-other.y;
    double xsub= this->x -other.x;
    dis= pow(xsub,2)+pow(ysub,2);
    dis=sqrt(dis);
    return dis;
}

void print() const{
cout<<"x : "<<this->x<<" y: "<<this->y<<endl;
}

static Point moveTowards (Point source, Point destanation, double distance);

double getX() const{
    return this->x;
}

double getY() const
{
    return this->y;
}

void setX(double xpo)
{
    x=xpo;
}

void setY(double ypo)
{
    y=ypo;
}









};
}