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
    double dis;
    double ysub= this->y-other.y;
    double xsub= this->x -other.x;
    dis= pow(xsub,2)+pow(ysub,2);
    dis=sqrt(dis);
    return dis;
}

void print(){
cout<<"x : "<<this->x<<" y: "<<this->y<<endl;
}

static const Point moveTowards(Point &origin , Point &dest , double distance){
    return Point(0,0);
}

double getX(){
    return x;
}

double getY()
{
    return y;
}









};
}