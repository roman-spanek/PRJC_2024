#pragma once
#include <stdio.h>
#include <stdlib.h>

long* init(int size);
void fill(long* array, int size);
long** init_pointers(int size);
long** shuffle(long* array, int size);
void verify(long* array);

void print_pointers_array(long** array, int size);
void print_array(long* array, int size);
