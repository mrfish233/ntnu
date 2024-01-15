#include <stdio.h>
#include <stdint.h>
#include "weight.h"

int main() {
	setup_boy_weight(70);
	setup_girl_weight(60);

	printf("%ld\n", afford_weight(0, 1));
	printf("%ld\n", afford_weight(0, -1));
	printf("%ld\n", afford_weight(-1, 0));

	for (int32_t i = 0; i < 5; i++) {
		for (int32_t j = 0; j <= i; j++) {
			printf("(%d,%d)=%ld\n", i, j, afford_weight(i, j));
		}
	}

	return 0;
}
