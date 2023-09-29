#include <stdio.h>
#include <stdint.h>

/*
 * bubble sort
 * Time complexity: O(n^2)
 */
int32_t bubbleSort(int32_t *a, int32_t n) {
	int32_t count = 0;
	int32_t i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				// Swap 2 numbers
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

				count += 3;
			}
		}
	}

	return count;
}

/*
 * Exponential
 * Time complexity: O(2^n)
 */
int32_t exponential(int32_t num) {
	int32_t count = 0;
	int32_t loop  = 1, i, j;

	// Loop num times
	for (i = 0; i < num; i++) {
		// Loop 2^loop - 1 times
		for (j = 1; j <= loop; j++) count++;

		loop *= 2;
	}

	// Add 1 more to count
	count += 1;

	return count;
}

int32_t exponentialRecursive(int32_t num) {
	if (num == 0) return 1;

	return exponentialRecursive(num - 1) + exponentialRecursive(num - 1);
}

/*
 * Logarithmic
 * time complexity: O(log n)
 */
int32_t logarithmic(float num) {
	int count = 0;

	while (num > 1) {
		// Half the number
		num /= 2;

		count++;
	}

	return count;
}

int32_t logarithmicRecursive(float num) {
	if (num <= 1) return 0;

	return logarithmicRecursive(num / 2) + 1;
}

/*
 * Linear logarithmic
 * Time complexity: O(n log n)
 */
int32_t linearLogarithmicRecursive(float num) {
	if (num <= 1) return 1;

	int32_t count = linearLogarithmicRecursive(num / 2) * 2;
	int32_t i = 0;

	for (i = 0; i < num; i++) count++;
	// printf("count=%d\n", count);

	return count;
}

/*
 * Factorial
 * Time complexity: O(n!)
 */
int32_t factorial(int32_t num) {
	int32_t count = 1, loop = 1;
	int32_t i = 0, j = 0;

	for (i = 1; i <= num; i++) {
		for (j = 1; j < i; j++) count += loop;

		loop = count;
	}

	return count;
}

int32_t factorialRecursive(int32_t num) {
	if (num == 0) return 1;

	int32_t count = 0;
	int32_t i = 0;

	for (i = 0; i < num; i++) {
		count += factorialRecursive(num - 1);
	}

	return count;
}

int main() {
	int32_t result1 = 0, result2 = 0;
	int32_t i = 0, n = 10;
	float f = 8.0;

	/*
	 * Bubble Sort
	 */
	int32_t array[10] = {10, 3, 6, 4, 2, 5, 9, 7, 8, 1};

	// Before sort
	printf("Before sort: ");
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	// Sort
	bubbleSort(array, n);

	// After sort
	printf("After sort: ");
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	/*
	 * Exponential
	 */
	result1 = exponential(n);
	result2 = exponentialRecursive(n);

	printf("2^%d = %d / %d\n", n, result1, result2);

	/*
	 * Logarithmic
	 */
	result1 = logarithmic(f);
	result2 = logarithmicRecursive(f);

	printf("log_2(%.2f) = %d / %d\n", f, result1, result2);

	// Linear logarithmic
	result1 = linearLogarithmicRecursive(f);
	printf("%.2f log_2(%.2f) = %d\n", f, f, result1);

	/*
	 * Factorial
	 */
	result1 = factorial(n);
	result2 = factorialRecursive(n);

	printf("%d! = %d / %d\n", n, result1, result2);

	return 0;
}
