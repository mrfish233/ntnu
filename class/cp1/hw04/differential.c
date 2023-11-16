#include "differential.h"

int64_t initDegree(char *str) {
	int64_t degree = -1;

	printf("Please enter %s degree: ", str);

	if (scanf("%ld", &degree) != 1) {
		printf("Error: invalid degree\n");
		return -1;
	}

	if (degree < 0 || degree > UINT32_MAX) {
		printf("Error: degree is out of range\n");
		return -1;
	}

	return degree;
}

int64_t *initEquation(char *str, int64_t degree) {
	int64_t *equation = calloc(degree + 1, sizeof(int64_t));

	printf("Please enter %s coefficients: ", str);

	for (int64_t i = 0; i < degree + 1; i++) {
		int64_t num = 0;
		if (scanf("%ld", &num) != 1) {
			printf("Error: invalid coefficient\n");
			freeEquation(equation);
			return NULL;
		}

		if (num == 0 && i == 0) {
			printf("Error: first coefficient should not be zero\n");
			freeEquation(equation);
			return NULL;
		}

		if (num < INT32_MIN || num > INT32_MAX) {
			printf("Error: coefficient is out of range\n");
			freeEquation(equation);
			return NULL;
		}

		equation[i] = num;
	}

	return equation;
}

void printEquation(char *str, int64_t *equation, int64_t degree) {
	int32_t printOnce = 0;

	printf("%s: ", str);

	for (int64_t i = 0; i < degree + 1; i++) {
		int64_t num = equation[i];

		// Skip the degree
		if (num == 0) {
			continue;
		}

		if (printOnce) {
			printf(" + ");
		}

		// Skip the number if it is 1, except constant term
		if (num != 1 || i == degree) {
			printf("%ld", num);
		}

		if (i == degree - 1) {
			printf("x");
		} else if (i != degree) {
			printf("x^%ld", degree - i);
		}

		printOnce = 1;
	}
	printf("\n");
}

void freeEquation(int64_t *equation) {
	if (equation == NULL) {
		return;
	}

	free(equation);
}
