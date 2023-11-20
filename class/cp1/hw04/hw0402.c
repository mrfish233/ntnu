#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "derivative.h"

#define F_FUNCTION "f(x)"
#define G_FUNCTION "g(x)"

int main() {
	int64_t deg1 = 0, *eqn1 = NULL;
	int64_t deg2 = 0, *eqn2 = NULL;

	deg1 = initDegree(F_FUNCTION);
	if (deg1 == -1) {
		return 1;
	}

	eqn1 = initEquation(F_FUNCTION, deg1);
	if (eqn1 == NULL) {
		return 1;
	}

	deg2 = initDegree(G_FUNCTION);
	if (deg2 == -1) {
		return 1;
	}

	eqn2 = initEquation(G_FUNCTION, deg2);
	if (eqn2 == NULL) {
		return 1;
	}

	// Calculate f'(x) and g'(x)

	int64_t *difEqn1 = differentiate(eqn1, deg1);
	int64_t  difDeg1 = newDegree(deg1 - 1);

	int64_t *difEqn2 = differentiate(eqn2, deg2);
	int64_t  difDeg2 = newDegree(deg2 - 1);

	// printf("\n");
	// printf("f'(x): ");
	// printEquation(difEqn1, difDeg1);
	// printf("g'(x): ");
	// printEquation(difEqn2, difDeg2);

	// Calculate (f(x)g(x))' = f(x)g'(x) + f'(x)g(x)

	int64_t *proEqn1 = productEquation(eqn1, deg1, difEqn2, difDeg2);
	int64_t  proDeg1 = newDegree(deg1 + difDeg2);

	int64_t *proEqn2 = productEquation(eqn2, deg2, difEqn1, difDeg1);
	int64_t  proDeg2 = newDegree(deg2 + difDeg1);

	// printf("\n");
	// printf("f(x)g'(x): ");
	// printEquation(proEqn1, proDeg1);
	// printf("f'(x)g(x): ");
	// printEquation(proEqn2, proDeg2);

	int64_t *sumEqn = sumEquation(proEqn1, proDeg1, proEqn2, proDeg2);
	int64_t  sumDeg = newDegree(proDeg1 > proDeg2 ? proDeg1 : proDeg2);

	// Calculate (f(x)/g(x))' = (f'(x)g(x) - f(x)g'(x)) / g^2(x)

	int64_t *subEqn = subtractEquation(proEqn2, proDeg2, proEqn1, proDeg1);
	int64_t  subDeg = newDegree(sumDeg);

	int64_t *proEqn3 = productEquation(eqn2, deg2, eqn2, deg2);
	int64_t  proDeg3 = newDegree(deg2 + deg2);

	// Simplify (f(x)/g(x))'

	int64_t *simEqn1 = simplifyEquation(subEqn, subDeg, proEqn3, proDeg3);
	int64_t  simDeg1 = subDeg;

	int64_t *simEqn2 = simplifyEquation(proEqn3, proDeg3, subEqn, subDeg);
	int64_t  simDeg2 = proDeg3;

	while (subEqn[simDeg1] == 0 && proEqn3[simDeg2] == 0) {
		simDeg1--;
		simDeg2--;
	}

	int64_t len1 = lengthOfEquation(simEqn1, simDeg1);
	int64_t len2 = lengthOfEquation(simEqn2, simDeg2);
	int64_t barLength = len1 > len2 ? len1 : len2;

	// Print the result

	printf(F_FUNCTION ": ");
	printEquation(eqn1, deg1);

	printf(G_FUNCTION ": ");
	printEquation(eqn2, deg2);

	printf("(f(x)g(x))': ");
	printEquation(sumEqn, sumDeg);

	printf(" f(x)    ");
	printEquation(simEqn1, simDeg1);

	printf("(----)': ");
	for (int32_t i = 0; i < barLength; i++) {
		printf("-");
	}
	printf("\n");

	printf(" g(x)    ");
	printEquation(simEqn2, simDeg2);

	clearEquation(eqn1);
	clearEquation(eqn2);
	clearEquation(difEqn1);
	clearEquation(difEqn2);
	clearEquation(proEqn1);
	clearEquation(proEqn2);
	clearEquation(sumEqn);
	clearEquation(subEqn);
	clearEquation(proEqn3);
	clearEquation(simEqn1);
	clearEquation(simEqn2);

	return 0;
}
