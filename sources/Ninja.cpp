#include "Ninja.hpp"
#include "stdexcept"
using namespace ariel;

 Ninja :: Ninja(string name ,int hitPoints, Point &p):Character(p,hitPoints,name){};

 void Ninja ::move(Character *enemy){
    if(enemy==nullptr)
    {
        __throw_invalid_argument("enemy not found or dead");
    }

    this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),speed));
    
 }

 
