#include <math.h>
#include <iostream>
using namespace std;

class Point{

double x;
double y;

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

Point MoveTowardsTo(Point origin , Point dest , double distance){
    return Point() ;
}










};