#include "Team.hpp"
using namespace ariel;


Team :: Team(Character *lead):leader(lead){};



Character* Team::closest(Team *team,Character *leader){
    Character *minimal=nullptr;
    double minimal_distance=INT16_MAX;

    for(int i=0; i<team->getAmount(); i++)
    {
        if(team->fighters.at(i)==leader)
        {
            continue;
        }
        double temp_distance=leader->getLocation().distance(team->fighters.at(i)->getLocation());
        if(temp_distance<minimal_distance)
        {
            minimal=team->fighters.at(i);
            minimal_distance=temp_distance;
        }
    }

    return minimal;





}

void Team::attack(Team *enemyleader){

if (enemyleader==nullptr)
{
    __throw_invalid_argument("null pointer to enemy team");
}
    

if (!leader->isAlive())
{
    leader=closest(this,leader);
}

Character *victim=nullptr;



    





}

int Team:: getAmount()
{
    int count=0; 
    for(int i=0; i<10; i++ )
    {
        if (fighters.at(i)!=nullptr)
        {
            count++;
        }
        
    }

    return count;
}

void Team ::add (Character *fighter)
{
    if(fighter==nullptr)
    {
        __throw_invalid_argument("null pointer invalid fighter");
    }
    if(getAmount()==10)
    {
        __throw_invalid_argument("THe team is alreadhy full");
    }
    
    fighters.push_back(fighter);
    

}