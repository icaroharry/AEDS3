#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_files 50

void open_files();

void close_files(FILE **f);

void flush_elements(const void *array, size_t element_size, size_t array_size);