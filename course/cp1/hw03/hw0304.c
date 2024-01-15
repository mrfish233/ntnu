#include <stdio.h>
#include <stdint.h>
#include "hw0304.h"

int main() {
	int32_t n = 0;

	const int32_t SOURCE = 1;
	const int32_t TARGET = 2;
	const int32_t SPARED = 3;

	// Read the number of disks
	printf("Please enter the disk number (2-20): ");
	scanf("%d", &n);

	// Check if the number is in the range of 2 to 20
	if (n < 2 || n > 20) {
		printf("Error: the number is out of range\n");
		return 1;
	}

	towerOfHanoi(n, SOURCE, TARGET, SPARED);

	return 0;
}
