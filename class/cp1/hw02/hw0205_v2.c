#include <stdio.h>
#include <stdint.h>

/* 
 * Print the line in format "*---*" with different dash length
 */
void printLine(int32_t length);

/* 
 * Print spaces in given length
 */
void printSpace(int32_t length);

int main() {
	// Input variables
	int32_t layer = 0, length = 0;

	/* 
	 * Inputs
	 */

	printf("Please input the length: ");
	scanf("%d", &length);

	printf("Please input the number of layer: ");
	scanf("%d", &layer);

	// Check island width
	int32_t longestWidth = 0;
	// First and last '*'
	longestWidth += 2;
	// Empty spaces
	longestWidth += layer * (length + 2 * (length - 2));
	// Lines
	longestWidth += (layer - 1) * length;

	if (layer < 1) {
		printf("Error: number of layers is too small\n");
		return 1;
	}

	if (length < 3) {
		printf("Error: length of an island is too small\n");
		return 1;
	}

	if (longestWidth > 80) {
		printf("Error: the island is too big\n");
		return 1;
	}

	/*
	 * Print the island
	 */

	// Space length for leading spaces
	int32_t spaceLength = 0;

	// Group lines
	int32_t group = 0, groupLine = 0;

	// Longest leading spaces for top lines
	spaceLength = (length - 1) * (2 * layer - 1);

	// Top lines
	for (int32_t i = 0; i < (layer - 1) * (length - 1); i++) {
		group     = i / (length - 1);
		groupLine = i % (length - 1);

		// Print leading spaces
		printSpace(spaceLength);

		for (int32_t j = 0; j < group + 1; j++) {
			if (groupLine == 0) {
				// Print star lines
				printLine(length);
				printSpace((j != group) ? length + 2 * (length - 2) : 0);
			} else {
				// Print slash lines
				printf("/");
				printSpace(length + 2 * (groupLine - 1));
				printf("\\");
				printSpace((j != group) ? length + 2 * (length - groupLine - 2) : 0);
			}
		}

		// Print line break
		printf("\n");

		// Update space length for next line
		spaceLength -= ((i + 1) % (length - 1) == 0) ? length : 1;
	}

	// Middle leading spaces
	spaceLength = length - 1;
	
	// Flag for space length
	int32_t flag = 1;

	// Middle lines
	for (int32_t i = 0; i < 2 * layer * (length - 1) + 1; i++) {
		groupLine = i % (length - 1);

		// Print leading spaces
		printSpace(spaceLength);

		for (int32_t j = 0; j < layer; j++) {
			// Check is last layer
			int32_t isLastLayer = (j == layer - 1);

			// Space length
			int32_t starSpaceLength   = length + 2 * (length - 2);
			int32_t fSlashSpaceLength = length + 2 * (groupLine - 1);
			int32_t bSlashSpaceLength = length + 2 * (length - groupLine - 2);

			if (groupLine == 0 && spaceLength == 0) {
				// Print star lines without leading spaces
				printf((j == 0) ? "*" : "");
				printSpace(starSpaceLength);
				printLine(!isLastLayer ? length : 0);
				printf(isLastLayer ? "*" : "");
			} else if (groupLine == 0) {
				// Print star lines with leading spaces
				printLine(length);
				printSpace(!isLastLayer ? starSpaceLength : 0);
			} else if (flag == 1) {
				// Print slash lines starting with slash
				printf("/");
				printSpace(fSlashSpaceLength);
				printf("\\");
				printSpace(!isLastLayer ? bSlashSpaceLength : 0);
			} else {
				// Print slash lines starting with backslash
				printf("\\");
				printSpace(bSlashSpaceLength);
				printf("/");
				printSpace(!isLastLayer ? fSlashSpaceLength : 0);
			}
		}

		// Print line break
		printf("\n");

		// Update space length for next line
		spaceLength -= flag;
		if (spaceLength == 0 || spaceLength == length - 1) {
			flag = -flag;
		}
	}

	// Shortest leading spaces for bottom lines
	spaceLength = 2 * (length - 1) + 1;

	// Bottom lines
	for (int32_t i = (layer - 1) * (length - 1) - 1; i >= 0; i--) {
		group     = i / (length - 1);
		groupLine = i % (length - 1);

		// Print leading spaces
		printSpace(spaceLength);

		for (int32_t j = 0; j < group + 1; j++) {
			if (groupLine == 0) {
				// Print star lines
				printLine(length);
				printSpace((j != group) ? length + 2 * (length - 2) : 0);
			} else {
				// Print slash lines
				printf("\\");
				printSpace(length + 2 * (groupLine - 1));
				printf("/");
				printSpace((j != group) ? length + 2 * (length - groupLine - 2) : 0);
			}
		}

		// Print line break
		printf("\n");

		// Update space length for next line
		spaceLength += (groupLine == 0) ? length : 1;
	}

	return 0;
}

void printLine(int32_t length) {
	for (int32_t i = 0; i < length; i++) {
		printf((i == 0 || i == length - 1) ? "*" : "-");
	}
}

void printSpace(int32_t length) {
	for (int32_t i = 0; i < length; i++) {
		printf(" ");
	}
}
