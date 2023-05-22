#include "Cowboy.hpp"
#include <string>
#include "iostream"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name ,Point location):Character(location,100,name){
    this->ammo=6;
};


void Cowboy::shoot(Character *enemy){

    if(this->isAlive()==true && this->hasBullets()==true)
    {
        enemy->hit(10);
        this->ammo--;
    }
    if(this->hasBullets()==false)
    {
        cout<<"out of bullets"<<endl;
    }
    else{
        cout<<this->getName()<<"is Dead "<<endl;
    }
    

};

string Character::print() const  {
   
   string data;
   if(!isAlive())
   {
    
    data = "C character name ( " +getName()+") hitting points is : --  location is "+strGetLocation();


   }
   else{
     data = "C character name " +getName()+" hitting points is :"  + to_string(hit_points)+  "  location is "+strGetLocation();
   }

   return data;

};
