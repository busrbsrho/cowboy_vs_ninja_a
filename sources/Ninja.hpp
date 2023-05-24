#pragma once
#include "Character.hpp"
#include "string"
using namespace std;

namespace ariel{

class Ninja : public Character
{
private:
    /* data */
    int speed;
 
public:
    Ninja(string name ,int hitPoints, Point &loc,int _speed);
    virtual void move(Character *enemy);
    virtual void slash(Character *enemy);
    string print() const override;
   

};
}


