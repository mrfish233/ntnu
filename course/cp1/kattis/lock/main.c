#include <stdio.h>
#include <stdint.h>

int32_t turnDegree(int32_t from, int32_t to) {
	return 9 * ((to > from) ? (40 + from - to) : (from - to));
}

int main() {
	int32_t a=-1, b=-1, c=-1, d=-1;

	while (1) {
		int32_t total = 0;

		// Scan number
		if (scanf("%d %d %d %d", &a, &b, &c, &d) == 0) return 1;

		if (a == 0 && b == 0 && c == 0 && d == 0) break;

		// Calculate
		total += 1080;
		total += turnDegree(a,b);
		total += turnDegree(c,b);
		total += turnDegree(c,d);

		printf("%d\n", total);
	}

	return 0;
}
