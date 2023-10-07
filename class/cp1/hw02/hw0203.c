#include <stdio.h>
#include <stdint.h>

int main() {
	// Inputs
	int32_t input = 0, isOddInput = 0;

	// States and next states
	int32_t state0 = 1, state1 = 0, state2 = 0, state3 = 0;
	int32_t state4 = 0, state5 = 0, state6 = 0;
	int32_t state0_next = 0, state1_next = 0, state2_next = 0, state3_next = 0;
	int32_t state4_next = 0, state5_next = 0, state6_next = 0;

	printf("Please enter an integer: ");
	scanf("%d", &input);
	while (input != 0) {
		
		isOddInput = (input % 2 == 1);

		/*
		 * Determine next state
		 */

		// State 0
		if (state0) {
			if (isOddInput) {
				state1_next = 1;
				state2_next = 1;
			} else {
				state3_next = 1;
			}
			
			// Reset state 0
			state0 = 0;
		}

		// State 1
		if (state1) {
			if (isOddInput) {
				state2_next = 1;
			} else {
				state4_next = 1;
			}

			// Reset state 1
			state1 = 0;
		}

		// State 2
		if (state2) {
			if (isOddInput) {
				state3_next = 1;
			} else {
				state5_next = 1;
			}

			// Reset state 2
			state2 = 0;
		}

		// State 3
		if (state3) {
			if (isOddInput) {
				state5_next = 1;
			} else {
				state0_next = 1;
			}

			// Reset state 3
			state3 = 0;
		}

		// State 4
		if (state4) {
			if (isOddInput) {
				state5_next = 1;
			} else {
				state2_next = 1;
				state6_next = 1;
			}

			// Reset state 4
			state4 = 0;
		}

		// State 5
		if (state5) {
			if (isOddInput) {
				state6_next = 1;
			} else {
				state0_next = 1;
			}

			// Reset state 5
			state5 = 0;
		}

		// State 6
		if (state6) {
			if (isOddInput) {
				state6_next = 1;
			} else {
				state1_next = 1;
			}

			// Reset state 6
			state6 = 0;
		}

		// Replace state to next state
		state0 = state0_next;
		state1 = state1_next;
		state2 = state2_next;
		state3 = state3_next;
		state4 = state4_next;
		state5 = state5_next;
		state6 = state6_next;

		// Reset next state
		state0_next = 0;
		state1_next = 0;
		state2_next = 0;
		state3_next = 0;
		state4_next = 0;
		state5_next = 0;
		state6_next = 0;

		//printf("Current: %d %d %d %d %d %d %d\n", 
		//		state0, state1, state2, state3, state4, state5, state6);

		printf("Please enter an integer: ");
		scanf("%d", &input);
	}

	/*
	 * Print the result
	 */

	// Check if ever print any states
	int32_t hasPrintOnce = 0;

	printf("Possible States: ");

	// State 0
	if (state0) {
		printf("S0");
		hasPrintOnce = 1;
	}

	// State 1
	if (state1) {
		if (hasPrintOnce) {
			printf(", ");
		}

		printf("S1");
		hasPrintOnce = 1;
	}

	// State 2
	if (state2) {
		if (hasPrintOnce) {
			printf(", ");
		}

		printf("S2");
		hasPrintOnce = 1;
	}

	// State 3
	if (state3) {
		if (hasPrintOnce) {
			printf(", ");
		}

		printf("S3");
		hasPrintOnce = 1;
	}

	// State 4
	if (state4) {
		if (hasPrintOnce) {
			printf(", ");
		}

		printf("S4");
		hasPrintOnce = 1;
	}

	// State 5
	if (state5) {
		if (hasPrintOnce) {
			printf(", ");
		}

		printf("S5");
		hasPrintOnce = 1;
	}

	// State 6
	if (state6) {
		if (hasPrintOnce) {
			printf(", ");
		}

		printf("S6");
		hasPrintOnce = 1;
	}

	printf("\n");

	return 0;
}

