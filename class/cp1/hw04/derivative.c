#include "derivative.h"

int64_t newDegree(int64_t degree) {
	return degree < 0 ? 0 : degree;
}

int64_t *newEquation(int64_t degree) {
	if (degree < 0) {
		return NULL;
	}

	int64_t *newEquation = calloc(degree + 1, sizeof(int64_t));
	return newEquation;
}

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
	int64_t *equation = newEquation(degree);

	printf("Please enter %s coefficients: ", str);

	for (int64_t i = 0; i < degree + 1; i++) {
		int64_t num = 0;
		if (scanf("%ld", &num) != 1) {
			printf("Error: invalid coefficient\n");
			clearEquation(equation);
			return NULL;
		}

		if (num == 0 && i == 0) {
			printf("Error: first coefficient should not be zero\n");
			clearEquation(equation);
			return NULL;
		}

		if (num < INT32_MIN || num > INT32_MAX) {
			printf("Error: coefficient is out of range\n");
			clearEquation(equation);
			return NULL;
		}

		equation[i] = num;
	}

	return equation;
}

int64_t *differentiate(int64_t *equation, int64_t degree) {
	if (equation == NULL) {
		return NULL;
	}

	int64_t diffedDegree = newDegree(degree - 1);
	int64_t *diffedEquation = newEquation(diffedDegree);

	for (int64_t i = 0; i < diffedDegree + 1; i++) {
		diffedEquation[i] = equation[i] * (degree - i);
	}

	return diffedEquation;
}

int64_t *sumEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2) {
	if (eqn1 == NULL || eqn2 == NULL || deg1 < 0 || deg2 < 0) {
		return NULL;
	}

	int64_t sumDegree = newDegree(deg1 > deg2 ? deg1 : deg2);
	int64_t *sumEquation = newEquation(sumDegree);

	for (int64_t i = sumDegree; i >= 0; i--) {
		if (deg1 >= 0) {
			sumEquation[i] += eqn1[deg1--];
		}

		if (deg2 >= 0) {
			sumEquation[i] += eqn2[deg2--];
		}
	}

	return sumEquation;
}

int64_t *subtractEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2) {
	if (eqn1 == NULL || eqn2 == NULL || deg1 < 0 || deg2 < 0) {
		return NULL;
	}

	int64_t subtractDegree = newDegree(deg1 > deg2 ? deg1 : deg2);
	int64_t *subtractEquation = newEquation(subtractDegree);

	for (int64_t i = subtractDegree; i >= 0; i--) {
		if (deg1 >= 0) {
			subtractEquation[i] += eqn1[deg1--];
		}

		if (deg2 >= 0) {
			subtractEquation[i] -= eqn2[deg2--];
		}
	}

	return subtractEquation;
}

int64_t *productEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2) {
	if (eqn1 == NULL || eqn2 == NULL || deg1 < 0 || deg2 < 0) {
		return NULL;
	}

	int64_t productDegree = newDegree(deg1 + deg2);
	int64_t *productEquation = newEquation(productDegree);

	for (int64_t i = 0; i < deg1 + 1; i++) {
		if (eqn1[i] == 0) {
			continue;
		}

		for (int64_t j = 0; j < deg2 + 1; j++) {
			if (eqn2[j] == 0) {
				continue;
			}

			int64_t tempCoeff  = eqn1[i] * eqn2[j];
			int64_t tempDegree = productDegree - ((deg1 - i) + (deg2 - j));

			productEquation[tempDegree] += tempCoeff;
		}
	}
	
	return productEquation;
}

void printEquation(char *str, int64_t *equation, int64_t degree) {
	int32_t printOnce = 0;

	printf("%s: ", str);

	if (degree == 0) {
		printf("%ld\n", equation[0]);
		return;
	}

	for (int64_t i = 0; i < degree + 1; i++) {
		int64_t num = equation[i];

		// Skip the degree
		if (num == 0) {
			continue;
		}

		// if (printOnce) {
		// 	printf(" %c ", num < 0 ? '-' : '+');
		// }

		if (printOnce && num >= 0) {
			printf("+");
		}

		// Skip the number if it is 1 or -1, except constant term
		if ((num != 1 && num != -1) || i == degree) {
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

void clearEquation(int64_t *equation) {
	if (equation == NULL) {
		return;
	}

	free(equation);
}
