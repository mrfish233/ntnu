#include <stdio.h>
#include <stdint.h>

/*
 * Print the binary form of the given 32-bit integer.
 * val: the given integer
 * pos: the position of the bit to be printed, MSB is 0, LSB is 31
 */
void BinaryForm(uint32_t val, int32_t pos);

int main() {
	int64_t n = 0;

	// Read the number
	printf("Please enter the number: ");
	scanf("%ld", &n);

	// Check if the number is in the range of 32-bit integer
	if (n < INT32_MIN || n > INT32_MAX) {
		printf("Error: the number is out of range\n");
		return 1;
	}

	// Print the binary form
	BinaryForm(n, 31);
	printf("\n");

	return 0;
}

void BinaryForm(uint32_t val, int32_t pos) {
	if (pos == 0) {
		printf("%u", val % 2);
		return;
	}

	BinaryForm(val / 2, pos - 1);
	printf("%u", val % 2);

	if ((pos + 1) % 8 == 0) {
		printf(" ");
	}
}
