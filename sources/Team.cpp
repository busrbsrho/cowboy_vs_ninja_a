#include "Team.hpp"
using namespace ariel;


Team :: Team(Character *lead):leader(lead){
   add(leader);
};



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

if (enemyleader->stillAlive()==0)
{
    cout<<"all enemys are dead";
    return;
}

if (!leader->isAlive())
{
    leader=closest(this,leader);
}

Character *victim=nullptr;
Cowboy *cow_boy=nullptr;
victim=closest(enemyleader,leader);

for (size_t i = 0; i < fighters.size(); i++)
{
    if(dynamic_cast<Cowboy *>(fighters.at(i))!=nullptr)
    {
        cow_boy=dynamic_cast<Cowboy *>(fighters.at(i));
     if (cow_boy->isAlive())
     {  
        if (cow_boy->hasBullets())
        {
            cow_boy->shoot(victim);
        }
        else{
            cow_boy->reload();
        }
        
    }
    }
    cow_boy=nullptr;
}






Ninja *nin=nullptr;

for (size_t i = 0; i < fighters.size(); i++)
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
        __throw_invalid_argument("The team is alreadhy full");
    }
    
    fighters.push_back(fighter);
    

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


void Team::closestchecker(){
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));
    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12,81)));
    Character *victim=closest(&team_B,tom);
    cout<<victim->print()<<endl;
    
}









