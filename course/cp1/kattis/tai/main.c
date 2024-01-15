#include <stdio.h>
#include <stdint.h>

int main() {
	int32_t n = 0;
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0, res = 0;

	if (scanf("%d", &n) == 0) return 1;
	if (scanf("%lf %lf", &x1, &y1) == 0) return 1;

	while (--n) {
		if (scanf("%lf %lf", &x2, &y2) == 0) return 1;

		res += 0.5 * (y1 + y2) * (x2 - x1) / 1000.0;

		x1 = x2;
		y1 = y2;
	}

	int32_t pre = 0;
	int32_t temp = (int32_t) res;

	while (temp > 0) {
		pre += 1;
		temp /= 10;
	}

	// printf("pre=%d\n", pre);

	printf("%.*lg\n", pre+5, res);

	return 0;
}
