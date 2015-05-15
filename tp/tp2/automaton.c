#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "automaton.h"

unsigned long automaton(coordinate *attacks, size_t mem_slots) {
    char ch;
    char state = 0;
    unsigned long i = 0;
    unsigned int x = 0, y = 0, tanks = 0;
    while(!feof(stdin)) {       
        ch = getchar();
        switch(ch) {
            case 'p':
                if(state == 0) {
                    state = 1;
                }
                break;
            case 'o':
                if(state == 1 || state == 2) {
                    state = 2;
                    tanks++;
                }
                break;
            case 'i':
                if(state == 2) {
                    state = 3;
                }
                break;
            case 'n':
                if(state == 3) {
                    state = 4;
                }
                break;
            case 't':
                if(state == 4) {
                    state = 5;
                }
                break;
            case '(':
                if(state == 5) {
                    state = 6;
                } else if(state > 5) {
                    state = 0;
                    x = 0;
                    y = 0;
                    tanks = 0;
                }
                break;
            case ',':
                if(state == 7) {
                    state = 8;
                } else if(state == 6 || state > 7) {
                    state = 0;
                    x = 0;
                    y = 0;
                    tanks = 0;
                }
                break;
            case ')':
                if(state == 9) {
                    state = 0;
                    if(i < mem_slots) {      
                        attacks[i].x = x;
                        attacks[i].y = y;
                        attacks[i].tanks = tanks;
                        i++;
                    } else {
                        printf("i de batatatata%lu\n", i);
                        i = 0;
                        flush_coordinates(attacks, mem_slots);
                    }
                    x = 0;
                    y = 0;
                    tanks = 0;
                } else if(state == 8) {
                    state = 0;
                    x = 0;
                    y = 0;
                    tanks = 0;
                }
                break;
            default:
                if(isdigit((int)ch)) {
                    if(state == 6 || state == 7) {
                        x *= 10;
                        x += (ch - 48);
                        state = 7;
                        if(x >= 100000) {
                            state = 0;
                            x = 0;
                            y = 0;
                            tanks = 0;
                        }
                    } else if(state == 8 || state == 9) {
                        y *= 10;
                        y += (ch - 48);
                        state = 9;
                        if(y >= 100000) {
                            state = 0;
                            x = 0;
                            y = 0;
                            tanks = 0;
                        }
                    }
                }
                if(feof(stdin)) {
                    flush_coordinates(attacks, i);
                }
                break;
        }
    }
    return i;
}