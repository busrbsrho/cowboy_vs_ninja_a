#include "Character.hpp"
using namespace ariel;



Character::Character(Point &point ,int hitpoints,  string name):location(point),hit_points(hitpoints), name(name){};
    


void Character::hit(int damage){

    if(this->alive == true)
        {
            if(this->hit_points>damage)
            {
                hit_points-=damage;
            }
            else
            {
                hit_points=0;
                this->alive=false;
            }
        }

}


string Character::print() const 
{
    return "Missing an OverRide";
}
