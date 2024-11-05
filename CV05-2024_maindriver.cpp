#include "modules.h"

int assert_equals(long *original, long ** expected, int size) {
	int i;
	int j = size - 1;
	for (i = 0; i < size; i++) {
		if (**(expected + j) != *(original + i)) return 0;
		j--;
	}
	return 1;
}

int test() {
	int size = 10;
	long* array = init(size);
	fill(array, size);
	long** shuffled_array = shuffle(array, size);
	print_pointers_array(shuffled_array, size);
	print_array(array, size);
	int return_code = assert_equals(array, shuffled_array, size);
	free((void*)array);
	free((void**)shuffled_array);
	return return_code;
}

int main() {
	if (test() == 1) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}