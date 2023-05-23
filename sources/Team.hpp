
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
        vector<Character*> fighters{10};
        int count_of_fighters;
    public:
        Team(Character *lead):leader(lead){};
        ~Team(){

        };
      
        virtual void attack(Team* enemyleader){};
        void add(Character* fighter){};
        int stillAlive(){
            return 0;
        };
        virtual void print() const {};
        int getAmount();
        Character *closest(Team *team,Character *leader);
        
        

       
    };
    
    
    
    
} // namespace ariel
