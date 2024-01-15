#include "hw0304.h"

void towerOfHanoi(int32_t n, int32_t source, int32_t target, int32_t spared) {
	// Calculate the loop count
	uint64_t loopCount = (1 << n) - 1;

	// Print the steps
	int32_t targetRod = 0;

	// Swap the target and spared rod if the number of disks is even
	if (n % 2 == 0) {
		int32_t temp = target;
		target = spared;
		spared = temp;
	}

	for (uint64_t i = 1; i <= loopCount; i++) {
		int32_t disk = 0, isOddDisk = 0;

		// Find the disk number
		for (int32_t j = 0; j < n; j++) {
			if (i & (1 << j)) {
				disk = j + 1;
				break;
			}
		}

		// Find if the disk number is odd
		isOddDisk = disk % 2;

		// Set the target rod according to step number and disk number
		if (i % 3 == 1) {
			targetRod = (isOddDisk) ? target : source;
		} else if (i % 3 == 0) {
			targetRod = (isOddDisk) ? spared : target;
		} else { // i % 3 == 2
			targetRod = (isOddDisk) ? source : spared;
		}

		// Print the step
		printf("move disk %d to rod %d\n", disk, targetRod);
	}
}

