#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "differential.h"

#define F_FUNCTION "f(x)"
#define G_FUNCTION "g(x)"

int main() {
	int64_t degree1 = 0, *equation1 = NULL;
	int64_t degree2 = 0, *equation2 = NULL;

	degree1 = initDegree(F_FUNCTION);
	if (degree1 == -1) {
		return 1;
	}

	equation1 = initEquation(F_FUNCTION, degree1);
	if (equation1 == NULL) {
		return 1;
	}

	degree2 = initDegree(G_FUNCTION);
	if (degree2 == -1) {
		return 1;
	}

	equation2 = initEquation(G_FUNCTION, degree2);
	if (equation2 == NULL) {
		return 1;
	}

	printEquation(F_FUNCTION, equation1, degree1);
	printEquation(G_FUNCTION, equation2, degree2);

	free(equation1);
	free(equation2);

	return 0;
}
