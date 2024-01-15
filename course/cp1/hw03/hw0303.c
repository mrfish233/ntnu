#include <stdio.h>
#include <stdint.h>
#include "binaryForm.h"

int main() {
	int64_t n = 0;
	const int32_t SIZE = 32;

	// Read the number
	printf("Please enter the number: ");
	scanf("%ld", &n);

	// Check if the number is in the range of 32-bit integer
	if (n < INT32_MIN || n > INT32_MAX) {
		printf("Error: the number is out of range\n");
		return 1;
	}

	// Print the binary form
	BinaryForm(n, SIZE);
	printf("\n");

	return 0;
}
