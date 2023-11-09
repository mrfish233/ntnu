#include <stdio.h>
#include <stdint.h>

void digitCount(int32_t digit[], int32_t num) {
	while (num > 0) {
		int32_t temp = num % 10;
		num /= 10;

		digit[temp]++;
	}
}

int32_t hasSameDigit(int32_t a[], int32_t b[]) {
	for (int32_t i = 0; i < 10; i++) {
		if (a[i] != b[i]) return 0;
	}

	return 1;
}

int main() {
	int32_t a = 0, b = 0;
	int32_t res[500][3] = {0};
	int32_t count = 0;

	// Check valid input
	if (scanf("%d %d", &a, &b) == 0) return 1;

	// Loop from a to b
	for (int32_t i = a; i <= b; i++) {
		// Loop from i to b
		for (int32_t j = i; j <= b; j++) {
			int32_t ttl = i * j;
			int32_t numDigit[10] = {0}, 
					ttlDigit[10] = {0};

			digitCount(numDigit, i);
			digitCount(numDigit, j);
			digitCount(ttlDigit, ttl);

			if (hasSameDigit(numDigit, ttlDigit)) {
				// printf("x = %d, y = %d, xy = %d\n", i, j, ttl);
				res[count][0] = i;
				res[count][1] = j;
				res[count][2] = ttl;
				count++;
			}
		}
	}

	// Print all result
	printf("%d digit-preserving pair(s)\n", count);
	for (int32_t i = 0; i < count; i++) {
		printf("x = %d, y = %d, xy = %d\n", res[i][0], res[i][1], res[i][2]);
	}

	return 0;
}
