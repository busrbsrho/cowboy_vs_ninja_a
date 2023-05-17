#pragma once
#include "Point.hpp"
#include "math.h"
#include "iostream"
#include "string"
using namespace std;

namespace ariel
{
class Character{

    Point &location;
    int hit_points;
    string name;
    bool alive;

public:
    Character(Point &point ,int hitpoints,  string name):location(point),hit_points(hitpoints), name(name){};
    
bool isAlive() const
{
    return alive;
}

virtual double distance(Character *other) const
{
    return this->location.distance(other->location);
}

virtual void hit(int num) 
{

};

virtual string getName() const
{
    return this->name;
}

virtual Point getLocation() const 
{
    return this->location;
};

virtual string print(){
    return " ";
}

int getHitPoints(){
    return hit_points;
}













};
} // namespace ariel

