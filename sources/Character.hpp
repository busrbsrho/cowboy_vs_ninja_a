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

        Point location;
        int hit_points;
        string name;
        bool isInTeam=false;
       

    public:
        Character(Point &point, int hitpoints, string name);
        virtual ~Character()=default;

        bool isAlive() const
        {
            return hit_points>0;
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
            return location;
        };

        virtual string print() const=0;

        int getHitPoints() const
        {
            return hit_points;
        }

        string strGetLocation() const;
        

       void setLocation (Point loc) ;

      
       void setInTeam(bool flag)
       {
        isInTeam=flag;
       } 


       bool getIsInTeam(){
        return isInTeam;
       }


    };
} // namespace ariel
