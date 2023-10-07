#include <stdio.h>
#include <stdint.h>
//#include <math.h>

int main() {
	uint16_t count = 0;
	double fraction = 0, result = 0, diff = 0;
	const double squareRoot2 = 1.41421356237309504880; // Constant

	printf("Please enter n (16-bits unsigned): ");
	scanf("%hu", &count);

	for (uint16_t i = 1; i <= count; i++) {
		// Result and difference
		result = 1.0 + fraction;
		diff   = result - squareRoot2;

		//printf("n = %hu: fraction= %.20f\n", i, fraction);

		// Continued fraction
		fraction = 1.0 / (fraction + 2.0);
		
		printf("n = %-5hu: %.20f (%.20f)\n", i, result, diff);
	}

	// printf("%hu\n", UINT16_MAX);


	//printf("%.20f\n", M_SQRT2);
	//printf("%.20f\n", sqrt(2));

	return 0;
}

