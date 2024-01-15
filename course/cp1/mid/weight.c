#include "weight.h"

static uint32_t boyWeight = 0;
static uint32_t girlWeight = 0;

static uint32_t initBoyWeight = 0;
static uint32_t initGirlWeight = 0;

void setup_girl_weight(uint32_t weight) {
	girlWeight = weight;

	initGirlWeight = 1;
}

void setup_boy_weight(uint32_t weight) {
	boyWeight = weight;

	initBoyWeight = 1;
}

int64_t afford_weight(int32_t x, int32_t y) {
	if (initGirlWeight == 0 || initBoyWeight == 0) {
		return -1;
	}

	if (x < 0 || y < 0 || x < y) {
		return -1;
	}

	if (x == 0 && y == 0) {
		return 0;
	}

	double totalWeight = 0;
	double weightScale = 1;

	uint64_t totalWeightScale = 1 << x;

	for (int32_t i = 0; i < x; i++) {
		if (i % 2 == 0) {
			totalWeight += girlWeight * (i + 1);
		} else {
			totalWeight += boyWeight * (i + 1);
		}
	}

	// Calculate the value of x choose y using the binomial coefficient formula
	for (int32_t i = 1; i <= y; i++) {
		weightScale = weightScale * (double) (x - y + i) / i;
	}

	double result = totalWeight * weightScale / (double) totalWeightScale;

	return result;
}
