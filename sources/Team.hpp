
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>

namespace ariel
{
    class Team
    {
    private:
        Character* leader;
        vector<Character*> fighters;
        int count_of_fighters;
    public:
        Team(Character *lead);
        ~Team();
      
        virtual void attack(Team* enemyleader);
        void add(Character* fighter);
        int stillAlive();
        virtual void print() const;
        Character *closest(Team *team,Character *leader);
        void closestchecker();
        vector<Character *> getFighters() const;
        Character* getLeader(){
            return leader;
        }
        void setLeader(Character* newleader)
        {
            leader=newleader;
        }

        
        

       
    };
    
    
    
    
} // namespace ariel
