#include <stdio.h>
#include <stdlib.h>

void print_ints(char* memory, int size) {
	for (int i = 0; i < size / sizeof(int); i++) {
		printf("%d,", *(((int*)memory) + i));
	}
	printf("\n--------------------\n");

}
char* init(int size) {
	return (char*)malloc(size);
}

void swap(char* memory, int size) {
	int* int_memory_head = (int *)memory;
	int* int_memory_tail = (int *)(memory + size - sizeof(int));

	int temp = *int_memory_head;
	*int_memory_head = *int_memory_tail;
	*int_memory_tail = temp;
	return;
}

void swap_bytes(char* memory, int size) {
	char* head = memory;
	char* tail = (memory + size - sizeof(char));
	char tmp;
	while (head < tail) {
		tmp = *head;
		*head = *tail;
		*tail = tmp;
		++head;
		--tail;
	}
}

int test_swap(char* memory, int size) {
	//set
	int return_code = 0;
	int* temp = (int * )memory;
	int head_value = INT_MAX;
	*temp = head_value;
	*(temp + 1) = head_value;
	*(temp + 2) = head_value;
	*(temp + 3) = head_value;
	int tail_value = 0;
	
	*(temp + size /sizeof(int) - 1) = tail_value;
	*(temp + size / sizeof(int) - 2) = tail_value;
	*(temp + size / sizeof(int) - 3) = tail_value;
	*(temp + size / sizeof(int) - 4) = tail_value;
	
	//act
	print_ints(memory, size);
	swap(memory, size);

	//validate
	if (*temp != tail_value) {
		printf("Error after swapping values, expected %d, but got %d \n", tail_value, *memory);
		return_code = 10;
	}
	else {
		printf("Head test passed.\n");
	}
	if (*(temp + size / sizeof(int) - 1) != head_value) {
		printf("Error after swapping values, expected %d, but got %d \n", head_value, *(temp + size - 1));
		return_code = 20;
	}
	else {
		printf("Tail test passed.\n");
	}
	
	return return_code;
}




int main() {
	int size = 32;
	char* memory = init(size);
	if (size == NULL) return 10;
	
	test_swap(memory, size);

	//swap(memory, size);
	//swap_bytes(memory, size);


	free((void*)memory);
	return 0;
}
