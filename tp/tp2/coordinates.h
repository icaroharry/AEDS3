#include <stdlib.h>
#include <math.h>
/**
 * Coordinate strucute
 */
typedef struct coordinate_struct {
    unsigned int x;
    unsigned int y;
    unsigned int tanks;
} coordinate;

unsigned int base_x;
unsigned int base_y;

int compare(const void * a, const void * b);

void flush_coordinates(coordinate *attacks, size_t mem_slots);