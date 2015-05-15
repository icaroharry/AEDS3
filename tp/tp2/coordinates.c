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

void close_files(FILE **f) {
    int i;
    for(i = 0; i < number_of_files; i++) {
        if(f[i] != NULL)
            fclose(f[i]);
    }
    free(*f);
}

void flush_elements(const void *array, size_t element_size, size_t array_size) {
    char str[10];
    snprintf(str, 10, "%d", number_of_files);
    
    FILE *fp = fopen(str, "a+");
    fwrite((array), element_size, array_size, fp);
    fclose(fp);
    number_of_files++;
}

void flush_coordinates(coordinate *attacks, size_t mem_slots) {
    if(mem_slots > 0) {    
        qsort(attacks, mem_slots, sizeof(coordinate), compare);
        flush_elements(attacks, sizeof(coordinate), mem_slots);
    }
}

void external_sort(size_t mem_size) {
    int i;
    char str[10];
    coordinate buffer, biggest;
    
    FILE **f = (FILE **)malloc((number_of_files) * sizeof(FILE *));
    FILE *out = fopen("out", "w");
    
    int end_of_block = 0;
    int biggest_index;

    for(i = 0; i < number_of_files; i++) {
        snprintf(str, 10, "%d", i);
        f[i] = fopen(str, "a+");
        rewind(f[i]);
    }
    size_t test = 0;
    while(end_of_block < number_of_files) {
        printf("%d\n", number_of_files);
        biggest.tanks = 0;
        for(i = 0; i < number_of_files; i++) {
            if(f[i] != NULL) {
                fseek(f[i], 0, SEEK_CUR);
                if(fread(&buffer, sizeof(coordinate), 1, f[i]) == 0) {
                    printf("buffer: %u;(%u,%u)\n", buffer.tanks, buffer.x, buffer.y);
                    test++;
                    printf("pr%d\n", i);
                    end_of_block++;
                    fclose(f[i]);
                    f[i] = NULL;
                } else {
                    test++;
                    printf("r%d\n", i);
                    printf("buffer_else: %u;(%u,%u)\n", buffer.tanks, buffer.x, buffer.y);
                    printf("biggest: %u;(%u,%u)\n", biggest.tanks, biggest.x, biggest.y);
                    //printf("%lu\n", test);
                    if(compare(&buffer, &biggest) < 0) {
                        biggest = buffer;
                        biggest_index = i;
                    }
                }
            }
        }
        if(f[biggest_index] != NULL && biggest.tanks > 0) {
            fseek(f[biggest_index], sizeof(coordinate), SEEK_CUR);
            fseek(out, 0, SEEK_END);
            fwrite(&biggest, sizeof(coordinate), 1, out);
        }
    }
    fclose(out);
    out = fopen("out", "r");
    size_t offset = 0;
    while(!feof(out)) {
        fseek(out, offset, SEEK_SET);
        fread(&buffer, sizeof(coordinate), 1, out);
        printf("%u;(%u,%u)\n", buffer.tanks, buffer.x, buffer.y);
        offset += sizeof(coordinate);
    }
}