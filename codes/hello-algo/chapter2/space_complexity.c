#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Linear
 * Space complexity: O(n)
 */
void linear(int n) {
	// nums array with length of n
	int32_t *nums = malloc(sizeof(int32_t) * n);
	free(nums);
}

void linearRecursive(int32_t n) {
	printf("rec %d", n);
	if (n != 1) {
		printf(", ");
	}
	else {
		printf("\n");
		return;
	}

	linearRecursive(n - 1);
}

/**
 * Quadratic
 * Space complexity: O(n^2)
 */
void quadratic(int32_t n) {
	int32_t**numMatrix = malloc(sizeof(int32_t *) * n);
	int32_t i = 0, j = 0;

	// Square matrix
	for (i = 0; i < n; i++) {
		int32_t *tmp = malloc(sizeof(int32_t) * n);
		for (j = 0; j < n; j++) {
			tmp[j] = j;
		}
		numMatrix[i] = tmp;
	}

	// Free matrix
	for (i = 0; i < n; i++) {
		free(numMatrix[i]);
	}
	free(numMatrix);
}

int main() {
	int32_t n = 5;

	linearRecursive(n);

	return 0;
}
