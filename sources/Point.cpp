#include "Point.hpp"
using namespace ariel;


















  Point Point :: moveTowards (Point source, Point dest, double dist) {
    if (dist < 0) {
        throw invalid_argument ("Distance can't be negative!");
    }
    // If "dest" is already at distance "dist" or less, return it.
    if (source.distance(dest) <= dist) {
        return dest;
    }
    // Else, the closest point is somewhere on the vector connecting source and dest.
    // Find the relative portion of dist from the whole vector.
    double portion = dist / source.distance(dest);
    // Return the point at the end of the portion (vector wise).
    // Source: https://math.stackexchange.com/questions/175896/finding-a-point-along-a-line-a-certain-distance-away-from-another-point
    return Point ((1 - portion) * source.getX() + portion * dest.getX(),
                  (1 - portion) * source.getY() + portion * dest.getY());
}






