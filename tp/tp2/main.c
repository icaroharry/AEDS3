#include "automaton.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <stdint.h>

#define STATIC_MEM 10

void SetMemoryLimit(const int64_t limit_mb) {
    struct rlimit limits;
    limits.rlim_cur = limit_mb * 1024ull * 1024ull;
    limits.rlim_max = limit_mb * 1024ull * 1024ull;
    int error_code = setrlimit(RLIMIT_AS, &limits);
}

int main() {
    unsigned int mem_limit;
    coordinate *attacks;
    scanf("%u\n", &mem_limit);
    scanf("%u %u\n", &base_x, &base_y);

    SetMemoryLimit(mem_limit);

    size_t mem_available = (size_t)((mem_limit - STATIC_MEM) * pow(2, 20));
    size_t mem_slots = mem_available / sizeof(coordinate);
    attacks = (coordinate *)malloc(mem_available);
    
    size_t number_of_attacks = automaton(attacks, mem_slots);
    
    qsort(attacks, number_of_attacks, sizeof(coordinate), compare);

    size_t i;
    for(i = 0; i < number_of_attacks; i++) {
        printf("%u;(%u,%u)\n", attacks[i].tanks, attacks[i].x, attacks[i].y);
    }
    return 0;
}