#include "parity.h"

uint64_t oddParity(int32_t num) {
	uint64_t parityBit = 1;
	uint64_t result = (uint64_t) num;

	// printf("Result: %lu, num=%d\n", result, num);

	// Loop until num is 0
	while (num != 0) {
		// If the last bit is 1, flip the parity bit
		if (num & 1) {
			parityBit = !parityBit;
		}
		num = num >> 1;
	}

	// printf("Parity bit: %lu\n", parityBit);

	// Add the parity bit to the result
	result = result << 1;
	result = result + parityBit;

	// printf("Result: %lu\n", result);

	return result;
}

uint64_t parity_2d(int32_t num1, int32_t num2, int32_t num3, int32_t num4, int32_t num5) {
	// Find the parity of each number
	uint64_t parity1 = oddParity(num1);
	uint64_t parity2 = oddParity(num2);
	uint64_t parity3 = oddParity(num3);
	uint64_t parity4 = oddParity(num4);
	uint64_t parity5 = oddParity(num5);

	uint64_t msb = 1UL << 32;
	uint64_t result = 0;
	uint64_t tempBit = 1;

	while (msb != 0) {
		// If the parity bit is 1, flip the result bit
		if (parity1 & msb) {
			tempBit = !tempBit;
		}
		if (parity2 & msb) {
			tempBit = !tempBit;
		}
		if (parity3 & msb) {
			tempBit = !tempBit;
		}
		if (parity4 & msb) {
			tempBit = !tempBit;
		}
		if (parity5 & msb) {
			tempBit = !tempBit;
		}
		msb = msb >> 1;

		// Add the temp bit to the result
		result = result << 1;
		result = result + tempBit;
	}

	return result;
}
