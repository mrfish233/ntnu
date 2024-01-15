#include <stdio.h>
#include <stdint.h>

int main() {
	// Inputs
	int32_t input = 0, isOddInput = 0;

	// State and next state (using bit 0-6, start from LSB)
	int8_t state     = 0b00000001;
	int8_t stateNext = 0b00000000;

	printf("Please enter an integer: ");
	scanf("%d", &input);
	while (input != 0) {
		
		// Odd input
		isOddInput = !(input % 2 == 0);

		/*
		 * Determine next state
		 */

		// 0 -> odd: 1,2; even: 3
		if (state & 0b00000001) {
			stateNext |= (isOddInput) ? 0b00000110 : 0b00001000;
		}

		// 1 -> odd: 2; even: 4
		if (state & 0b00000010) {
			stateNext |= (isOddInput) ? 0b00000100 : 0b00010000;
		}

		// 2 -> odd: 3; even: 5
		if (state & 0b00000100) {
			stateNext |= (isOddInput) ? 0b00001000 : 0b00100000;
		}

		// 3 -> odd: 3; even: 0
		if (state & 0b00001000) {
			stateNext |= (isOddInput) ? 0b00100000 : 0b00000001;
		}

		// 4 -> odd: 5; even: 2,6
		if (state & 0b00010000) {
			stateNext |= (isOddInput) ? 0b00100000 : 0b01000100;
		}

		// 5 -> odd: 6; even: 0
		if (state & 0b00100000) {
			stateNext |= (isOddInput) ? 0b01000000 : 0b00000001;
		}

		// 6 -> odd: 6; even: 1
		if (state & 0b01000000) {
			stateNext |= (isOddInput) ? 0b01000000 : 0b00000010;
		}

		// Set state and reset
		state     = stateNext;
		stateNext = 0b00000000;

		// Read input again
		printf("Please enter an integer: ");
		scanf("%d", &input);
	}

	/*
	 * Print the result
	 */

	// Check if ever print any states
	int32_t hasPrintOnce = 0;

	printf("Possible States: ");

	for (int32_t i = 0; i < 7; i++) {
		// Print if LSB is 1
		if (state & 1) {
			if (hasPrintOnce) {
				printf(", ");
			}

			printf("S%hd", i);
			hasPrintOnce = 1;
		}
		// Shift state
		state >>= 1;
	}
	printf("\n");

	return 0;
}

