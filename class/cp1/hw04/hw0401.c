#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "mysort.h"

int main() {
	srand(time(0));

	int32_t size   = (rand() % 30) + 11;
	int32_t *array = malloc(sizeof(int32_t) * size);

	// int32_t array[SIZE] = {0};

	for (int32_t i = 0; i < size; i++) {
		array[i] = rand() % 1000;
	}

	printf("Before sort: \n");
	myprint(array, size);

	mysort(array, size);

	printf("After sort: \n");
	myprint(array, size);

	free(array);

	return 0;
}
