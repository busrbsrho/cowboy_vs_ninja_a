#include"Character.hpp"
#include "string"
using namespace std;
namespace ariel{

class Cowboy : public Character{

int ammo;

public:

Cowboy(string name ,Point location) :Character(location,100,name),ammo(6){};
void shoot (Character *enemy){};

bool hasBullets(){
    return false;
};

void reload(){
    this->ammo=6;
};

string print() override{
    return " ";
}

int getAmmo()

{
    return ammo;
}







};

}