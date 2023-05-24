#include"Character.hpp"
#include "string"
using namespace std;
#define COWBOY_LIFE 100
namespace ariel{

class Cowboy : public Character{

int ammo;

public:

Cowboy(string name ,Point location);


void shoot (Character *enemy);

bool hasBullets() const{
    return ammo>0;
};

void reload(){
    this->ammo=6;
};

string print() const override;
    
    


int getAmmo() const

{
    return ammo;
}









};

}