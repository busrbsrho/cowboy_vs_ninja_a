#pragma once
#include "Character.hpp"
#include "string"
using namespace std;

namespace ariel{

class Ninja : public Character
{
private:
    /* data */
    int speed;

public:
    Ninja(string name ,int hitPoints, Point &p):Character(p,hitPoints,name){};
    virtual void move(Character *enemy){};
    virtual void slash(Character *enemy){};
    string print() override{
        return "";
    };


};
}


