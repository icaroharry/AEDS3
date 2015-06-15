#include "util.h"

/**
 * Calculates the distance between 2 points
 * 
 * @param  x1 Coordinate X of point 1
 * @param  y1 Coordinate Y of point 1
 * @param  x2 Coordinate X of point 2
 * @param  y2 Coordinate Y of point 2
 * @return    double
 */
double distance(long int x1, long int y1, long int x2, long int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}