#include "modules.h"

void verify(long* array) {
	if (array == NULL) {
		exit(EXIT_FAILURE);
	}
}

void fill(long* array, int size) {
	verify(array);
	int i;
	for (i = 0; i < size; i++) {
		*(array + i) = (long)i;
	}
}

long* init(int size) {
	return (long*)malloc(sizeof(long) * size);
}

long** init_pointers(int size) {
	return (long**)malloc(sizeof(long*) * size);
}
long** shuffle(long* array, int size) {
	long** shufled = init_pointers(size);
	int i;
	int j = size - 1;
	for (i = 0; i < size; i++) {
		*(shufled + i) = (array + j);
		j--;
	}
	return shufled;
}
void print_pointers_array(long** array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("[%d] = %ld, ", i, *(array[i]));
	}
	printf("\n");
}
void print_array(long* array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("[%d] = %ld, ", i, array[i]);
	}
	printf("\n");
}