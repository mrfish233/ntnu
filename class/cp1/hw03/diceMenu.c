#include "diceMenu.h"
#include "diceRolls.h"

// Menu choice
static int32_t gMenuChoice = -1;

// Global variables
static int32_t gNumDices = 0;
static int32_t gSides    = 0;

// Constants
static const int32_t MENU_EXIT	            = 0;
static const int32_t MENU_ROLL_SIX          = 1;
static const int32_t MENU_ROLL_GIVEN        = 2;
static const int32_t MENU_KEEP_DICE         = 3;
static const int32_t MENU_KEEP_HIGH_AND_LOW = 4;

void printMenu() {
	// Print the menu
	printf("Welcome to the dice roller!\n");
	printf("Please refer to README.md for more instructions.\n");
	printf("0. Exit the roller\n");
	printf("1. Roll a 6-sided dice\n");
	printf("2. Roll given number of given-sided dices\n");
	printf("3. Roll given number of given-sided dices, keep some of dices and set the value\n");
	printf("    to add to the sum\n");
	printf("4. Roll given number of given-sided dices, keep some of the highest and lowest\n");
	printf("    dices and set the value to add to the sum\n");
}

int32_t handleChoice() {
	// Handle the user's choice
	int32_t handle = -1;

	// Read the user's choice
	printf("--------------------------------------------------------------------------------\n");
	printf("Your choice: ");
	if (scanf("%d", &gMenuChoice) != 1) {
		printf("\nUh oh, this is not a valid choice.\n\n");
		while (getchar() != '\n');
		return -1;
	}
	printf("\n");

	// Handle the user's choice
	if (gMenuChoice == MENU_EXIT) {
		callExit();
	} else if (gMenuChoice == MENU_ROLL_SIX) {
		rollDices(1, 6);

		// Print the dices and the sum
		printf("==== Roll 1d6 ====\n");
		printDices();
		printSum();
	} else if (gMenuChoice == MENU_ROLL_GIVEN) {
		// Roll given number of given-sided dices
		handle = callRollGiven();

		// If roll is valid
		if (handle == 0) {
			// Print the dices and the sum
			printf("\n==== Roll %dd%d ====\n", gNumDices, gSides);
			printDices();
			printSum();
		}
	} else if (gMenuChoice == MENU_KEEP_DICE) {
		// Roll given number of given-sided dices
		handle = callRollGiven();

		// If roll is valid
		if (handle == 0) {
			// Print the dices with index
			printf("\n==== Roll %dd%d ====\n", gNumDices, gSides);
			printDicesWithIndex();

			// Keep the dices
			printf("\n");
			handle = callKeepDice();
		}

		// If keep is valid
		if (handle == 0) {
			// Set the sum shift
			handle = callSetSumShift();
		}

		// If set shift is valid
		if (handle == 0) {
			// Print the dices with index and the sum of kept dices
			printf("\n==== \e[0;32mSelected dices\e[0m ====\n");
			printDicesWithIndex();
			printSumKept();
		}
	} else if (gMenuChoice == MENU_KEEP_HIGH_AND_LOW) {
		// Roll given number of given-sided dices
		handle = callRollGiven();

		// If roll is valid
		if (handle == 0) {
			// Print the dices with index
			printf("\n==== Roll %dd%d ====\n", gNumDices, gSides);
			printDicesWithIndex();

			// Keep the highest and lowest dices
			printf("\n");
			handle = callKeepHighestLowest();
		}

		// If keep highest and lowest is valid
		if (handle == 0) {
			// Print the dices with index
			printf("\n==== \e[0;32mSelected dices\e[0m ====\n");
			printDicesWithIndex();

			// Keep the dices
			printf("\n");
			handle = callKeepDice();
		}

		// If keep is valid
		if (handle == 0) {
			// Set the sum shift
			handle = callSetSumShift();
		}

		// If set shift is valid
		if (handle == 0) {
			// Print the dices with index and the sum of kept dices
			printf("\n==== \e[0;32mSelected dices\e[0m ====\n");
			printDicesWithIndex();
			printSumKept();
		}
	} else {
		printf("Uh oh, this is not a valid choice.\n");
	} // End of handle the user's choice
	printf("\n");

	// Return the user's choice
	return gMenuChoice;
}

void callExit() {
	printf("Goodbye!\n");
}

int32_t callRollGiven() {
	// Read the number of dices and sides
	printf("Roll AdX (A = number of dices (0<=A<=10), X = number of sides (2<=X<=100))\n");
	printf("Number of dices(A): ");
	if (scanf("%d", &gNumDices) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}
	printf("Number of sides(X): ");
	if (scanf("%d", &gSides) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Check for invalid input
	if (gNumDices < 0 || gNumDices > 10) {
		printf("Uh oh, the number of dices (A) is out of range (0~10).\n");
		return -1;
	} else if (gNumDices == 0) {
		printf("Hmm, it's hard to roll 0 dices with %d sides.\n", gSides);
		return -1;
	} else if (gSides < 2 || gSides > 100) {
		printf("Uh oh, the number of sides (X) is out of range (2~100).\n");
		return -1;
	}

	// Roll the dices
	rollDices(gNumDices, gSides);

	// Return 0 if success
	return 0;
}

int32_t callKeepDice() {
	int32_t numKept = 0;
	int32_t index   = 0;
	int32_t loop    = 0;

	// Read the number of dices to keep
	printf("Select number of dices to keep (0<=Y<=%d): ", gNumDices);
	if (scanf("%d", &numKept) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Check for invalid input
	if (numKept < 0 || numKept > gNumDices) {
		printf("Uh oh, the number of dices to keep (Y) is out of range (0~%d).\n", gNumDices);
		return -1;
	}

	// Loop number of keep times
	while(loop < numKept) {
		// Read the index of the dice to keep
		printf("Dice %d: ", loop + 1);
		if (scanf("%d", &index) != 1) {
			printf("Uh oh, this is not a valid number.\n");
			while (getchar() != '\n');
			return -1;
		}

		// Check for invalid input
		if (index < 1 || index > gNumDices) {
			printf("Uh oh, the index is out of range (1~%d).\n", gNumDices);
			return -1;
		}

		// Select the dice at the given index
		if (keepDice(index - 1) == -1) {
			printf("Uh oh, the index was selected. Please select again.\n");
			continue;
		}

		// Increase the loop counter
		loop++;
	}
	printf("\n");

	// Return 0 if success
	return 0;
}

int32_t callKeepHighestLowest() {
	int32_t highest = 0;
	int32_t lowest  = 0;

	// Read the number of highest and lowest dices to keep
	printf("Select number of highest dices to keep (0<=H<=%d): ", gNumDices);
	if (scanf("%d", &highest) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Read the number of lowest dices to keep
	printf("Select number of lowest dices to keep (0<=L<=%d): ", gNumDices);
	if (scanf("%d", &lowest) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Check for invalid input
	if (highest < 0 || highest > gNumDices) {
		printf("Uh oh, the number of highest dices to keep (H) is out of range (0~%d).\n", gNumDices);
		return -1;
	}

	// Check for invalid input
	if (lowest < 0 || lowest > gNumDices) {
		printf("Uh oh, the number of lowest dices to keep (L) is out of range (0~%d).\n", gNumDices);
		return -1;
	}

	// Keep the highest and lowest dices
	if (keepHighestLowest(highest, lowest) == -1) {
		printf("Uh oh, the number of highest and lowest dices to keep (H+L) is out of range (0~%d).\n", gNumDices);
		return -1;
	}

	// Return 0 if success
	return 0;
}

int32_t callSetSumShift() {
	int32_t value = 0;

	// Read the value of the sum shift
	printf("Amount to add to the sum (-10<=B<=10): ");
	if (scanf("%d", &value) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Check for invalid input
	if (value < -10 || value > 10) {
		printf("Uh oh, the value of the sum shift (X) is out of range (-10~10).\n");
		return -1;
	}

	// Set the sum shift
	setSumShift(value);

	// Return 0 if success
	return 0;
}
