#include "hw0304.h"

void towerOfHanoi(int32_t n, int32_t source, int32_t target, int32_t spared) {
	// Move the last disk from source to target
	if (n == 1) {
		printf("move disk %d to rod %d\n", n, target);
		return;
	}

	// Move n - 1 disks from source to spared
	towerOfHanoi(n - 1, source, spared, target);

	// Move disk n from source to target
	printf("move disk %d to rod %d\n", n, target);

	// Move n - 1 disks from spared to target
	towerOfHanoi(n - 1, spared, target, source);
}
