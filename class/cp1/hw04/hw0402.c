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

	printEquation(F_FUNCTION, eqn1, deg1);
	printEquation(G_FUNCTION, eqn2, deg2);

	// Differentiated Equation

	int64_t *difEqn1 = differentiate(eqn1, deg1);
	int64_t *difEqn2 = differentiate(eqn2, deg2);
	int64_t  difDeg1 = newDegree(deg1 - 1);
	int64_t  difDeg2 = newDegree(deg2 - 1);

	// printf("\n");
	// printEquation("f'(x)", difEqn1, difDeg1);
	// printEquation("g'(x)", difEqn2, difDeg2);

	// Calculate (f(x)g(x))' = f(x)g'(x) + f'(x)g(x)

	int64_t *proEqn1 = productEquation(eqn1, deg1, difEqn2, difDeg2);
	int64_t *proEqn2 = productEquation(eqn2, deg2, difEqn1, difDeg1);
	int64_t  proDeg1 = newDegree(deg1 + difDeg2);
	int64_t  proDeg2 = newDegree(deg2 + difDeg1);

	// printf("\n");
	// printEquation("f(x)g'(x)", proEqn1, proDeg1);
	// printEquation("f'(x)g(x)", proEqn2, proDeg2);

	int64_t *sumEqn = sumEquation(proEqn1, proDeg1, proEqn2, proDeg2);
	int64_t  sumDeg = newDegree(proDeg1 > proDeg2 ? proDeg1 : proDeg2);

	printf("\n");
	printEquation("(f(x)g(x))'", sumEqn, sumDeg);

	// Calculate (f(x)/g(x))' = (f'(x)g(x) - f(x)g'(x)) / g^2(x)

	int64_t *subEqn = subtractEquation(proEqn2, proDeg2, proEqn1, proDeg1);
	int64_t  subDeg = newDegree(sumDeg);

	printf("\n");
	printEquation("f'(x)g(x)-f(x)g'(x)", subEqn, subDeg);

	int64_t *proEqn3 = productEquation(eqn2, deg2, eqn2, deg2);
	int64_t  proDeg3 = newDegree(deg2 + deg2);

	printEquation("g^2(x)", proEqn3, proDeg3);

	/**
	 * TODO: simplify the result of (f(x)/g(x))'
	*/

	clearEquation(eqn1);
	clearEquation(eqn2);
	clearEquation(difEqn1);
	clearEquation(difEqn2);
	clearEquation(proEqn1);
	clearEquation(proEqn2);
	clearEquation(sumEqn);
	clearEquation(subEqn);

	return 0;
}
