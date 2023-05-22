#include "Point.hpp"
using namespace ariel;


















  Point Point::moveTowards(Point origin , Point dest , double distance){

     if (distance < 0)
    {
        throw std::invalid_argument("Distance can't be less than 0");
    }

    // Calculate the distance between the source and destination points
    double distance = origin.distance(dest);

    // If the distance is less than or equal to the given distance, return the destination point
    if (distance <= distance)
    {
        return dest;
    }

    // Calculate the ratio between the given distance and the distance between the source and destination points
    double ratio = distance / distance;

    // Calculate the new x and y coordinates based on the ratio
    double new_x = origin.getX() + (ratio * (dest.getX() - origin.getX()));
    double new_y = origin.getY() + (ratio * (dest.getY() - origin.getY()));

    // Return a new point with the new x and y coordinates
    return Point(new_x, new_y);
}





