#include "Character.hpp"
using namespace ariel;



Character::Character(Point &point ,int hitpoints,  string name):location(point),hit_points(hitpoints), name(name){};
    


void Character::hit(int damage){

    if(this->isAlive() == true)
        {
            if(this->hit_points>damage)
            {
                hit_points-=damage;
            }
            else
            {
                hit_points=0;
                
            }
        }

}


string Character::print() const 
{
    return "Missing an OverRide";
}

string Character::strGetLocation() const{

    return "("+to_string(this->getLocation().getX())+","+to_string(this->getLocation().getY())+")";

}

void Character :: setLocation(Point loc){
    location=loc;
}