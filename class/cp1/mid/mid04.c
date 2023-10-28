#include <stdio.h>
#include <stdint.h>
#include "parity.h"

int main() {
	// int32_t num1 = 2147483647;
	// int32_t num1 = 2;

	// uint64_t parity1 = oddParity(num1);

	// printf("Parity of %d is %lu\n", num1, parity1);
	// printf("test: %d\n", 1 << 1);

	printf("%ld\n", parity_2d(1,1,1,1,1));

	return 0;
}
