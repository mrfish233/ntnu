#include "mysort.h"

/**
 * Swap 2 values in an array.
 * @param array The given array
 * @param a The first index to be swapped
 * @param b The second index to be swapped
*/
static void swap(int32_t array[], int32_t a, int32_t b) {
	int32_t temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void mysort(int32_t array[], int32_t size) {
	int32_t tail = size - 1;
	int32_t head = 0;

	// 1st policy: even numbers before odd numbers
	while (head < tail) {
		if (array[head] % 2 == 1) {
			swap(array, head, tail);
			tail--;
		}

		if (array[head] % 2 == 0) {
			head++;
		}
	}

	int32_t split = (array[head] % 2 == 1) ? head : head + 1;
	// printf("split=%d\n", split);

	// 2nd policy: Ascending odd numbers
	for (int32_t i = split; i < size - 1; i++) {
		for (int32_t j = i + 1; j < size; j++) {
			if (array[i] > array[j]) {
				swap(array, i, j);
			}
		}
	}

	// 3rd policy: Descending even numbers
	for (int32_t i = 0; i < split - 1; i++) {
		for (int32_t j = i + 1; j < split; j++) {
			if (array[i] < array[j]) {
				swap(array, i, j);
			}
		}
	}
}

void myprint(int32_t array[], int32_t size) {
	for (int32_t i = 0; i < size; i++) {
		if (i != 0) printf(" ");
		printf("%d", array[i]);
	}
	printf("\n");
}
