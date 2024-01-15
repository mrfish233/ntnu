#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int randomAccess(int32_t *array, int32_t size) {
	// Seed random number generator by current time
	srand(time(NULL));

	// Take random index between [0,size)
	int randomIndex = rand() % size;
	// Take random num base on index
	int randomNum = array[randomIndex];

	return randomNum;
}

void insertNumber(int32_t *array, int32_t size, int32_t num, int32_t index) {
	int32_t i = 0;

	// Move numbers to next index, start from given index
	for (i = size - 1; i > index; i--) {
		array[i] = array[i - 1];
	}

	array[index] = num;
}

void removeNumber(int32_t *array, int32_t size, int32_t index) {
	int32_t i = 0;

	// Move numbers to last index, start from given index + 1
	for (i = index; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
}

int findNumber(int32_t *array, int32_t size, int32_t target) {
	int32_t i = 0;

	// Find the target number and return index
	for (i = 0; i < size; i++) {
		if (array[i] == target) {
			return i;
		}
	}

	// Return -1 if find nothing
	return -1;
}

void printArray(int32_t *array, int32_t size) {
	int32_t i = 0;

	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

int main() {
	int32_t array1[5] = {0}; // {0,0,0,0,0}
	int32_t array2[5] = {1,2,3,4,5};
	int32_t size = 5;
	int32_t result1 = 0, result2 = 0;

	// Random access
	result1 = randomAccess(array1, size);
	result2 = randomAccess(array2, size);

	printf("random: %d %d\n", result1, result2);

	// Insert number
	int32_t num = 9, index = 1;

	insertNumber(array1, size, num, index);
	insertNumber(array2, size, num, index);

	printArray(array1, size);
	printArray(array2, size);

	// Remove number
	removeNumber(array1, size, index);
	removeNumber(array2, size, index);

	printArray(array1, size);
	printArray(array2, size);

	// Find number
	result1 = findNumber(array1, size, 1);
	result2 = findNumber(array2, size, 3);

	printf("found index: %d %d\n", result1, result2);

	return 0;
}
