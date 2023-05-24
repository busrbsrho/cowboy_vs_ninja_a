#include "Team.hpp"
using namespace ariel;


Team :: Team(Character *lead):leader(lead){
   add(leader);
};

Team::~Team(){
    for (size_t i = 0; i < fighters.size(); i++)
    {
        delete fighters.at(i);
    }
    

}


Character* Team::closest(Team *team,Character *leader){
    Character *minimal=nullptr;
    double minimal_distance=INT16_MAX;

    for(size_t i=0; i<team->fighters.size(); i++)
    {
        if(team->fighters.at(i)==leader || team->fighters.at(i)->isAlive()==false)
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
 if (this->stillAlive() == 0 || enemyleader -> stillAlive() == 0) {
    throw runtime_error("both team must be alive for an attack to happen");
    }


if (!leader->isAlive())
{
    leader=closest(this,leader);
}

Character *victim=nullptr;
Cowboy *cow_boy=nullptr;
victim=closest(enemyleader,leader);

for (size_t i = 0; i < fighters.size()&&victim->isAlive(); i++)
{
    if(dynamic_cast<Cowboy *>(fighters.at(i))!=nullptr)
    {
        cow_boy=dynamic_cast<Cowboy *>(fighters.at(i));
     if (cow_boy->isAlive())
     {  
        if (cow_boy->hasboolets())
        {
            cow_boy->shoot(victim);
        }
        else{
            cow_boy->reload();
        }
        
    }
    }
    if(!victim->isAlive()&& enemyleader->stillAlive()>0){
        victim=closest(enemyleader,leader);
    }
    if (enemyleader->stillAlive()==0)
    {
        /* code */
        return;
    }
    
    cow_boy=nullptr;
}






Ninja *nin=nullptr;

for (size_t i = 0; i < fighters.size()&&victim->isAlive(); i++)
{
    if (dynamic_cast<Ninja*>(fighters.at(i))!=nullptr && fighters.at(i)->isAlive())
    {
        nin=dynamic_cast<Ninja*>(fighters.at(i));
    
    if (nin->getLocation().distance(victim->getLocation())<=1)
    {
        nin->slash(victim);
    }
    else
    {
        nin->move(victim);
    }
    }
     if(!victim->isAlive() && enemyleader->stillAlive()>0){
        victim=closest(enemyleader,leader);
    }


    nin=nullptr;
    
    
}








    





}

void Team ::add (Character *fighter)
{
    if(fighter==nullptr)
    {
        __throw_invalid_argument("null pointer invalid fighter");
    }
    if(fighters.size()==10)
    {
        __throw_runtime_error("The team is alreadhy full");
    }
    if (fighter->getIsInTeam())
    {
        __throw_runtime_error("is already in a team");
    }
    
    
    fighters.push_back(fighter);
    fighter->setInTeam(true);

}



int Team::stillAlive(){

    int count=0;
    for (size_t i = 0; i < fighters.size(); i++)
    {
        if(fighters.at(i)->isAlive()==true){
            count++;
        }
    }
    return count;

}


void Team:: print() const{
    Cowboy *cow_boy=nullptr;
    Ninja *nin=nullptr;
for (size_t i = 0; i < fighters.size(); i++)
    {
    if(dynamic_cast<Cowboy *>(fighters.at(i))!=nullptr)
    {
        cow_boy=dynamic_cast<Cowboy *>(fighters.at(i));
        cout<<cow_boy->print()<<endl;
            
    }
    cow_boy=nullptr;

}
for (size_t i = 0; i < fighters.size(); i++)
{
    if (dynamic_cast<Ninja*>(fighters.at(i))!=nullptr && fighters.at(i)->isAlive())
    {
        nin=dynamic_cast<Ninja*>(fighters.at(i));
        cout<<nin->print()<<endl;
    }
    nin=nullptr;



}
}


vector<Character*> Team::getFighters() const{
    return fighters;
}









