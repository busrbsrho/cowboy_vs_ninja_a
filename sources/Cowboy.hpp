#pragma once
#include"Character.hpp"
#include "string"
using namespace std;
#define COWBOY_LIFE 110
namespace ariel{

class Cowboy : public Character{

int ammo;

public:

Cowboy(string name ,Point location);


void shoot (Character *enemy);

bool hasboolets() const{

    return ammo>0;
};

void reload();

string print() const override;
    
    


int getAmmo() const

{
    return ammo;
}









};

}