#include "doctest.h"
#include "sources/Team.hpp"
#include <vector>
#include <math.h>
#include <sstream>
using namespace ariel;
using namespace std;


TEST_SUITE("Point class")
{
    Point p1(0, 5) ,p2(0,10);
    TEST_CASE("gets")
    {
        CHECK(p1.getX() == 0);
	    CHECK(p1.getY() == 10);
    }
    TEST_CASE("Distance")
    {
        CHECK(p1.distance(p2) == (double)(5));
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
    }

    TEST_CASE("Move towards a point")
    {
        
        Point p3 = Point::moveTowards(p1, p2, 0.5);
        CHECK(p3.distance(p2) <= 0.5);
    }

}

TEST_SUITE("Character class")
{
     
    Point p1(0,0),p2(0,10);
    Cowboy *c2 = new Cowboy("Peer", p2);
    Cowboy *c1 = new Cowboy("Omer", p1);

 
   TEST_CASE("constructor checking ")
   { 
       CHECK_NOTHROW(Cowboy c("benaya", p1));

       CHECK_EQ(c1->getHitPoints(), 100);
   }
   

    

    TEST_CASE("Distance")
    {
        CHECK(c1->distance(c2) == 10.0);
    }

    TEST_CASE("Get name")
    {
        CHECK(c1->getName() == "Omer");
        CHECK(c2->getName() == "Peer");
    }
   

    TEST_CASE("isAlive")
    {
        CHECK(c1->isAlive() == true);
        CHECK(c2->isAlive() == true);
        
    }
     TEST_CASE("Get location")
    {
        CHECK(c1->getLocation().getX()==p1.getX());
        CHECK(c1->getLocation().getY()== p1.getY());
    }

      TEST_CASE("Reload bullets")
    {  for (int i = 0; i < 6; i++)
    {
        c1->shoot(c2);
        CHECK_EQ(c1->getAmmo(),6-i+1);
    }
        CHECK(c1->hasBullets() == false);
        
        c1->reload();
        CHECK(c1->hasBullets() == true);
        CHECK_EQ(c1->getAmmo(),6);
    }
}


