#pragma once
#include "Team.hpp"
#include "Character.hpp"
namespace ariel
{
    class Team2:public Team
{
private:
    /* data */

public:
    Team2(Character *leader);
    void print() const override;
    void attack (Team *enemyLeader) override;
    ~Team2()=default;
};


} // namespace ariel


