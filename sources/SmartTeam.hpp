#include "Team.hpp"
#include "Character.hpp"
namespace ariel
{
    class SmarTeam:public Team
{
private:
    /* data */
public:
    SmarTeam(Character *leader):Team(leader){};
    void print() const override{};
    void attack (Team *enemyLeader) override{};
    ~SmarTeam(){};
};


} // namespace ariel
