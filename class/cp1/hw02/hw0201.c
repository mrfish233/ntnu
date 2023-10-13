#include <stdio.h>
#include <stdint.h>

int main() {
	int32_t count = 0;
	long double fraction = 0, result = 0, diff = 0;
	const long double squareRoot2 = 1.414213562373095L; // Constant

	printf("Please enter n (16-bits unsigned): ");
	scanf("%d", &count);

	// Error check
	if (count < 1 || count > UINT16_MAX) {
		printf("Error: input is out of range\n");
		return 1;
	}

	for (int32_t i = 1; i <= count; i++) {
		// Result and difference
		result = 1.0 + fraction;
		diff   = result - squareRoot2;

		// Continued fraction
		fraction = 1.0 / (fraction + 2.0);

		printf("n = %d: %.15Lf (%.15Lf)\n", i, result, diff);
	}

	return 0;
}

