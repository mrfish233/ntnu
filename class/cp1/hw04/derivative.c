#include "derivative.h"

int32_t gcd(int32_t a, int32_t b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
 
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

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

	int64_t  sumDeg = newDegree(deg1 > deg2 ? deg1 : deg2);
	int64_t *sumEqn = newEquation(sumDeg);

	for (int64_t i = sumDeg; i >= 0; i--) {
		if (deg1 >= 0) {
			sumEqn[i] += eqn1[deg1--];
		}

		if (deg2 >= 0) {
			sumEqn[i] += eqn2[deg2--];
		}
	}

	return sumEqn;
}

int64_t *subtractEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2) {
	if (eqn1 == NULL || eqn2 == NULL || deg1 < 0 || deg2 < 0) {
		return NULL;
	}

	int64_t  subDeg = newDegree(deg1 > deg2 ? deg1 : deg2);
	int64_t *subEqn = newEquation(subDeg);

	for (int64_t i = subDeg; i >= 0; i--) {
		if (deg1 >= 0) {
			subEqn[i] += eqn1[deg1--];
		}

		if (deg2 >= 0) {
			subEqn[i] -= eqn2[deg2--];
		}
	}

	return subEqn;
}

int64_t *productEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2) {
	if (eqn1 == NULL || eqn2 == NULL || deg1 < 0 || deg2 < 0) {
		return NULL;
	}

	int64_t  proDeg = newDegree(deg1 + deg2);
	int64_t *proEqn = newEquation(proDeg);

	for (int64_t i = 0; i < deg1 + 1; i++) {
		if (eqn1[i] == 0) {
			continue;
		}

		for (int64_t j = 0; j < deg2 + 1; j++) {
			if (eqn2[j] == 0) {
				continue;
			}

			int64_t tempCoeff  = eqn1[i] * eqn2[j];
			int64_t tempDegree = proDeg - ((deg1 - i) + (deg2 - j));

			proEqn[tempDegree] += tempCoeff;
		}
	}
	
	return proEqn;
}

int64_t *simplifyEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2) {
	if (eqn1 == NULL || eqn2 == NULL || deg1 < 0 || deg2 < 0) {
		return NULL;
	}

	int64_t simDeg = newDegree(deg1);
	int64_t tmpDeg2 = deg2;

	while (eqn1[simDeg] == 0 && eqn2[tmpDeg2] == 0) {
		simDeg--;
		tmpDeg2--;
	}

	int64_t *simEqn = newEquation(simDeg);

	for (int64_t i = 0; i < simDeg + 1; i++) {
		simEqn[i] = eqn1[i];
	}

	int64_t divisor = eqn1[0];

	for (int64_t i = 1; i < deg1 + 1; i++) {
		if (eqn1[i] == 0) {
			continue;
		}
		
		divisor = gcd(divisor, eqn1[i]);

		if (divisor == 1) {
			break;
		}
	}

	for (int64_t i = 0; i < deg2 + 1; i++) {
		if (eqn2[i] == 0) {
			continue;
		}

		divisor = gcd(divisor, eqn2[i]);

		if (divisor == 1) {
			break;
		}
	}

	for (int64_t i = 0; i < simDeg + 1; i++) {
		simEqn[i] /= divisor;
	}

	return simEqn;
}

void printEquation(int64_t *equation, int64_t degree) {
	int32_t printOnce = 0;

	// printf("degree=%ld\n", degree);

	if (degree == 0) {
		printf("%ld\n", equation[0]);
		return;
	}

	int64_t check = 0;
	for (int64_t i = 0; i < degree + 1; i++) {
		if (equation[i] == 0) {
			check++;
		}
	}

	if (check == degree + 1) {
		printf("0\n");
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

		if (num == -1 && i != degree) {
			printf("-");
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

int64_t lengthOfEquation(int64_t *equation, int64_t degree) {
	if (equation == NULL) {
		return 0;
	}

	if (degree == 0 && equation[0] == 0) {
		return 1;
	}

	int64_t totalLength = 0;
	
	for (int64_t i = 0; i < degree + 1; i++) {
		int64_t num = equation[i];

		// Skip the degree
		if (num == 0) {
			continue;
		}

		// Sign length
		totalLength += 1;

		// Coefficient length
		totalLength += (int64_t) log10(labs(num));
		if ((num != 1 && num != -1) || i == degree) {
			totalLength += 1;
		}

		// "x"
		if (i != degree) {
			totalLength += 1;

			// "^n"
			if (i != degree - 1) {
				totalLength += (int64_t) log10(degree - i) + 2;
			}
		}

		// First positive coefficient has no sign
		if (i == 0 && num > 0) {
			totalLength -= 1;
		}
	}

	return totalLength;
}

void clearEquation(int64_t *equation) {
	if (equation == NULL) {
		return;
	}

	free(equation);
}
