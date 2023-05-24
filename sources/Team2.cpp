#include "Team2.hpp"
using namespace ariel;



Team2 :: Team2(Character *leader):Team(leader){};

void Team2::print() const{

    for (size_t i = 0; i < getFighters().size(); i++)
    {
        cout<<getFighters().at(i)->print()<<endl;
    }
    

}

void Team2::attack(Team *enemyleader)
{
if (enemyleader==nullptr)
{
    __throw_invalid_argument("null pointer to enemy team");
}

if (enemyleader->stillAlive()==0)
{
    cout<<"all enemys are dead";
    return;
}
if (this->stillAlive() == 0)
{
    throw std::invalid_argument("Team can't attack with no warriors");
}
if (!(this->getLeader()->isAlive()))
{
        this->setLeader(closest(this, this->getLeader()));
}


Character *victim=nullptr;
Cowboy *cow_boy=nullptr;
victim=closest(enemyleader,getLeader());
Ninja *nin=nullptr;

for (size_t i = 0; i < getFighters().size()&&victim->isAlive(); i++)
{
    if(dynamic_cast<Cowboy *>(getFighters().at(i))!=nullptr)
    {
        cow_boy=dynamic_cast<Cowboy *>(getFighters().at(i));
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
   
    }else  if (dynamic_cast<Ninja*>(getFighters().at(i))!=nullptr && getFighters().at(i)->isAlive())
    {
        nin=dynamic_cast<Ninja*>(getFighters().at(i));
    
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
    cow_boy=nullptr;
    
    
    
}





}