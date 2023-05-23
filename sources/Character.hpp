#pragma once
#include "Point.hpp"
#include "math.h"
#include "iostream"
#include "string"
using namespace std;

namespace ariel
{
    class Character
    {

        Point &location;
        int hit_points;
        string name;
        bool alive;

    public:
        Character(Point &point, int hitpoints, string name);

        bool isAlive() const
        {
            return alive;
        }

        void setAlive(bool _alive)
        {
            alive = _alive;
        }

        virtual double distance(Character *other) const
        {
            return this->location.distance(other->location);
        }

        virtual void hit(int damage);

        virtual string getName() const
        {
            return this->name;
        }

        virtual Point getLocation() const
        {
            return this->location;
        };

        virtual string print() const=0;

        int getHitPoints() const
        {
            return hit_points;
        }

        string strGetLocation() const
        {
            return "x is : " + to_string(this->location.getX()) + " y is : " + to_string(this->location.getY());
        }

        void setLocation(Point loc)
        {
            this->location=loc;
        }
    };
} // namespace ariel
