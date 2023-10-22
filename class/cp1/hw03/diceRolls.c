#include "diceRolls.h"

// Dices array (max 10 dices) and the dice kept
static int32_t dices[15] = {0};
static int32_t diceKept[15] = {0};

// Dice count and dice kept count
static int32_t diceCount = 0;
static int32_t diceKeptCount = 0;

// Sum of dices and sum of kept dices
static int32_t sumDices = 0;
static int32_t sumKeptDices = 0;

// Shift of sum
static int32_t sumShift = 0;

void clearDices() {
	// Reset the sum of dices and the sum of kept dices
	sumDices  = 0;
	sumKeptDices = 0;

	// Reset the sum shift
	sumShift = 0;

	// Reset the dice count and the dice kept count
	diceCount = 0;
	diceKeptCount = 0;

	// Reset the dices array and the dice kept
	for (int32_t i = 0; i < 15; i++) {
		dices[i] = 0;
		diceKept[i] = 0;
	}
}

void printDice(int32_t index) {
	// Print the dice at the given index
	printf("[%d]\n", dices[index]);
}

void printDices() {
	// Print all dices
	for (int32_t i = 0; i < diceCount; i++) {
		printf("[%3d] ", dices[i]);

		if (i % 5 == 4 && i != diceCount - 1) {
			printf("\n");
		}
	}
	printf("\n");
}

void printDicesWithIndex() {
	// Print all dices
	for (int32_t i = 0; i < diceCount; i++) {
		// Print the kept dice with green color
		if (diceKept[i] == 1) {
			printf("\e[0;32m");
		}

		printf("%2d. [%3d] ", i + 1, dices[i]);

		// Reset the color
		printf("\e[0m");

		if (i % 5 == 4 && i != diceCount - 1) {
			printf("\n");
		}
	}
	printf("\n");
}

void printSum() {
	printf("Result: ");

	// Print all dices
	for (int32_t i = 0; i < diceCount; i++) {
		if (i != 0) {
			printf(" + ");
		}
		printf("%d", dices[i]);
	}

	// Print sum shift if it is not zero
	if (sumShift != 0) {
		printf(" + %d", sumShift);
	}

	// Print the sum
	if (diceCount > 1 || sumShift != 0) {
		printf(" = %d\n", sumDices + sumShift);
	} else {
		printf("\n");
	}
}

void printSumKept() {
	int32_t isPlusPrinted = 0;

	printf("Result: ");

	// Print all dices kept
	for (int32_t i = 0; i < diceCount; i++) {
		if (diceKept[i] == 1) {
			if (isPlusPrinted != 0) {
				printf(" + ");
			}
			printf("%d", dices[i]);

			isPlusPrinted = 1;
		}
	}

	// Print 0 if no dice is kept
	if (diceKeptCount == 0) {
		printf("0");
	}

	// Print sum shift if it is not zero
	if (sumShift < 0) {
		printf(" - %d", -sumShift);
	} else if (sumShift > 0) {
		printf(" + %d", sumShift);
	}

	// Print the sum
	if (diceKeptCount > 1 || sumShift != 0) {
		printf(" = %d\n", sumKeptDices + sumShift);
	} else {
		printf("\n");
	}
}

int32_t rollDices(int32_t numDices, int32_t sides) {
	// Seed the random number generator with the current time
	srand(time(0));

	// Check for invalid input
	if (numDices < 0 || numDices > 10 || sides < 2 || sides > 100) {
		return -1;
	}

	// Reset the dices array and the sum
	clearDices();

	// Set the dice count
	diceCount = numDices;

	// Add dices to the array and calculate the sum
	for (int32_t i = 0; i < numDices; i++) {
		dices[i]  = (rand() % sides) + 1;
		sumDices += dices[i];
	}

	// Return the sum of the dices
	return sumDices;
}

int32_t keepDice(int32_t index) {
	// Check for invalid input
	if (index < 0 || index >= diceCount) {
		return -1;
	}

	// Check if the dice is already selected
	if (diceKept[index] == 1) {
		return -1;
	}

	// Select the dice if it is not selected
	diceKept[index] = 1;
	diceKeptCount++;

	/*
	 * TODO: different color for kept dice
	 */

	// Add the dice to the sum of kept dices
	sumKeptDices += dices[index];

	return dices[index];
}

int32_t keepHighestLowest(int32_t highest, int32_t lowest) {
	// Check for invalid input
	if (highest < 0 || highest > diceCount || lowest < 0 || lowest > diceCount) {
		return -1;
	}
	
	// Check highest + lowest is less than the dice count
	if (highest + lowest > diceCount) {
		return -1;
	}

	// Keep the highest dices
	for (int32_t i = 0; i < highest; i++) {
		// Highest dice and index
		int32_t highestDice  = 0;
		int32_t highestIndex = 0;

		// Find the highest dice
		for (int32_t j = 0; j < diceCount; j++) {
			// Skip the dice if it is already kept
			if (diceKept[j] == 0 && dices[j] > highestDice) {
				highestDice  = dices[j];
				highestIndex = j;
			}
		}

		// Keep the highest dice
		keepDice(highestIndex);
	}

	// Keep the lowest dices
	for (int32_t i = 0; i < lowest; i++) {
		// Lowest dice and index
		int32_t lowestDice  = 101;
		int32_t lowestIndex = 0;

		// Find the lowest dice
		for (int32_t j = 0; j < diceCount; j++) {
			// Skip the dice if it is already kept
			if (diceKept[j] == 0 && dices[j] < lowestDice) {
				lowestDice  = dices[j];
				lowestIndex = j;
			}
		}

		// Keep the lowest dice
		keepDice(lowestIndex);
	}
}

int32_t setSumShift(int32_t value) {
	// Check for invalid input
	if (value < -10 || value > 10) {
		return -1;
	}

	// Set the sum shift
	sumShift = value;
	return 0;
}
