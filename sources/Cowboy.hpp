#include"Character.hpp"
#include "string"
using namespace std;
namespace ariel{

class Cowboy : public Character{

int ammo;

public:

Cowboy(string name ,Point location);


void shoot (Character *enemy);

bool hasBullets(){
    return false;
};

void reload(){
    this->ammo=6;
};

string print() const override;
    


int getAmmo()

{
    return ammo;
}







};

}