#include "coordinates.h"
#include <math.h>
#include <stdio.h>

int number_of_files = 0;

int compare(const void * a, const void * b) {
    coordinate *aux_a = (coordinate *)a;
    coordinate *aux_b = (coordinate *)b;

    if (aux_a->tanks <  aux_b->tanks) return 1;
    if (aux_a->tanks >  aux_b->tanks) return -1;
    if (aux_a->tanks == aux_b->tanks) {
        return (int)(sqrt(pow((double)aux_a->x - (double)base_x, 2) + pow((double)aux_a->y - (double)base_y, 2)) - sqrt(pow((double)aux_b->x - (double)base_x, 2) + pow((double)aux_b->y - (double)base_y, 2)));
    }
    return 0;
}

void flush_coordinates(coordinate *attacks, size_t mem_slots) {
    printf("teste\n");
    char str[10];
    snprintf(str, 10, "%d", number_of_files);
    number_of_files++;
    FILE *fp = fopen(str, "a+");
    fwrite(attacks, sizeof(coordinate), mem_slots, fp);
    fclose(fp);
}