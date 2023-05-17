
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
        

       
    };
    
    
    
    
} // namespace ariel
