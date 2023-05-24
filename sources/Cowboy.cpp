#include "Cowboy.hpp"
#include <string>
#include "iostream"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name ,Point location):Character(location,COWBOY_LIFE,name){
    this->ammo=6;
};


void Cowboy::shoot(Character *enemy){

    if (!enemy->isAlive())
   {
    __throw_runtime_error("cant kill dead enemy");
   }
   if(!this->isAlive() )
   {
    __throw_runtime_error("cant kill while dead ");
   }
   if (this==enemy)
   {
    /* code */
    __throw_runtime_error("no self harm");
   }
   

    if(this->isAlive()==true && this->hasboolets()==true && enemy->isAlive())
    {
        enemy->hit(10);
        this->ammo--;
    }
    

   
    

};

string Cowboy::print() const  {
   
   string data;
   if(!isAlive())
   {
    
    data = "C character name ( " +getName()+") hitting points is : --  location is "+strGetLocation();


   }
   else{
     data = "C character name " +getName()+" hitting points is :"  + to_string(getHitPoints())+  "  location is "+ strGetLocation();
   }

   return data;

};


void Cowboy :: reload(){
    if(isAlive())
    {
    this->ammo=6;
    }
    else
    __throw_runtime_error("dead bodey cant reload");
};


