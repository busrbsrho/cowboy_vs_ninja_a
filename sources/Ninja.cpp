#include "Ninja.hpp"
#include "stdexcept"
using namespace ariel;

 Ninja :: Ninja(string name ,int hitPoints, Point &p,int _speed):Character(p,hitPoints,name),speed(_speed){};

 void Ninja ::move(Character *enemy){
    if(enemy==nullptr || enemy->isAlive()==false)
    {
        __throw_invalid_argument("enemy not found or dead");
    }

   setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));

 }


 void Ninja::slash(Character *enemy)
 {
    if (enemy==nullptr)
    {
        __throw_invalid_argument("no enemy bad poinetr");
    }

   
   if(this->isAlive() && this->getLocation().distance(enemy->getLocation())<=1)
   { 
      enemy->hit(40);
   }



 }

string Ninja :: print() const{


     string data;
   if(!isAlive())
   {

    data = "N character name ( " +getName()+") hitting points is : --  location is "+strGetLocation();


   }
   else{
     data = "N character name " +getName()+" hitting points is :"  + to_string(getHitPoints())+  "  location is "+strGetLocation();
   }

   return data;

}

 

 
