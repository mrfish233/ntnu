#include "binaryForm.h"

void BinaryForm(uint32_t val, int32_t pos) {
	if (pos == 1) {
		printf("%u", val % 2);
		return;
	}

	BinaryForm(val / 2, pos - 1);
	printf("%u", val % 2);

	if (pos % 8 == 0) {
		printf(" ");
	}
}
