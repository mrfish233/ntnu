#include <stdio.h>
#include <stdint.h>
//#include <math.h>

int main() {
	uint16_t count = 0;
	long double fraction = 0, result = 0, diff = 0;
	long double squareRoot2 = 1.41421356237309504880; // Constant
	long double calibrate   = 0.00000000000000009667;

	long double t           = 0.00000000000000000001;
	printf("sq2=%.20Lf\n", squareRoot2 - calibrate + t * 4.0);

	printf("Please enter n (16-bits unsigned): ");
	scanf("%hu", &count);

	for (uint16_t i = 1; i <= count; i++) {
		// Result and difference
		result = 1.0 + fraction;
		diff   = result - squareRoot2 + calibrate;

		// Continued fraction
		fraction = 1.0 / (fraction + 2.0);
		
		printf("n = %hu: %.20Lf (%.20Lf)\n", i, result, diff);
	}

	//printf("%.20f\n", M_SQRT2);
	//printf("%.20f\n", sqrt(2));

	return 0;
}

