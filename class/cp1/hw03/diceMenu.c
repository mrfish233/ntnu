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
static const int32_t MENU_PRINT_MENU        = 8;
static const int32_t MENU_CLEAR_AND_PRINT   = 9;
static const int32_t MENU_PLAY_RPG          = 99;

void printMenu() {
	// Print the menu
	printf("Welcome to the Dice Roll 3000!\n\n");

	printf(" ____  _            _____ _____ _ _    ___ ___ ___ ___ \n");
	printf("|    \\|_|___ ___   | __  |     | | |  |_  |   |   |   |\n");
	printf("|  |  | |  _| -_|  |    -|  |  | | |  |_  | | | | | | |\n");
	printf("|____/|_|___|___|  |__|__|_____|_|_|  |___|___|___|___|\n");

	printf("\nPlease refer to README.md for more instructions.\n");
	printf("0. Exit the roller\n");
	printf("1. Roll a 6-sided dice\n");
	printf("2. Roll given number of given-sided dices\n");
	printf("3. Roll given number of given-sided dices, keep given dices and set the value to add to the sum\n");
	printf("4. Roll given number of given-sided dices, keep given, highest and lowest dices and set the value to add to the sum\n");
	printf("8. Print this menu\n");
	printf("9. Clear the screen and print this menu\n");
	printf("99. Let's play the game CPI-SRPG!\n");
}

int32_t handleChoice() {
	// Handle the user's choice
	int32_t handle = -1;

	// Read the user's choice
	printf("---------------------------------------------------------------------\n");
	printf("Menu choice: ");
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
			printf("\n==== Selected dices ====\n");
			printDices();
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
			handle = callKeepHighestLowest();
		}

		// If keep highest and lowest is valid
		if (handle == 0) {
			// Print the dices with index
			printf("\n==== Selected dices ====\n");
			printDicesWithIndex();

			// Keep the dices
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
			printf("\n==== Selected dices ====\n");
			printDices();
			printSumKept();
		}
	} else if (gMenuChoice == MENU_PRINT_MENU) {
		// Print the menu
		printMenu();
	} else if (gMenuChoice == MENU_CLEAR_AND_PRINT) {
		// Clear the screen
		system("clear");

		// Print the menu
		printMenu();
	} else if (gMenuChoice == MENU_PLAY_RPG) {
		// Clear the screen
		system("clear");

		// Start the game
		rpgEventGameProcess();
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
	printf("==== Roll the dice ====\n");
	printf("Number of dices(0<=A<=10): ");
	if (scanf("%d", &gNumDices) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}
	printf("Number of sides(2<=X<=100): ");
	if (scanf("%d", &gSides) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Roll the dices
	int32_t handleRollDices = rollDices(gNumDices, gSides);

	// Check for invalid input
	if (handleRollDices == -1) { 
		printf("Uh oh, the number of dices (A) is out of range (0~10).\n");
		return -1;
	} else if (handleRollDices == -2) {
		printf("Uh oh, the number of sides (X) is out of range (2~100).\n");
		return -1;
	}

	// Return 0 if success
	return 0;
}

int32_t callKeepDice() {
	// Read the number of dices to keep
	int32_t numKept = 0;

	// Read the index of the dice to keep
	int32_t index   = 0;

	// Loop counter
	int32_t loop    = 0;

	// Maximum number of dices to keep
	int32_t maxKept = gNumDices - getKeptDices();

	// Skip if no dices to keep
	if (maxKept == 0) {
		return 0;
	}

	// Read the number of dices to keep
	printf("==== Keep the \e[0;32mselected\e[0m dices ====\n");
	printf("Number of \e[0;32mselected\e[0m dices (0<=\e[0;32mY\e[0m<=%d): ", maxKept);
	if (scanf("%d", &numKept) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Check for invalid input
	if (numKept < 0 || numKept > maxKept) {
		printf("Uh oh, the number of \e[0;32mselected\e[0m dices (\e[0;32mY\e[0m) is out of range (0~%d).\n", maxKept);
		return -1;
	}

	// Keep all dices if numKept is maximum
	if (numKept == maxKept) {
		for (int32_t i = 0; i < gNumDices; i++) {
			keepDice(i);
		}
		printf("\n");
		return 0;
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

		// Select the dice at the given index
		int32_t handleKeepDice = keepDice(index - 1);

		// Check for invalid input
		if (handleKeepDice == -1) {
			printf("Uh oh, the index is out of range (1~%d).\n", gNumDices);
			return -1;
		} else if (handleKeepDice == -2) {
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
	printf("==== Keep \e[0;31mhighest\e[0m and \e[0;36mlowest\e[0m dices ====\n");
	printf("Number of \e[0;31mhighest\e[0m dices to keep (0<=\e[0;31mH\e[0m<=%d): ", gNumDices);
	if (scanf("%d", &highest) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Keep the highest dices
	int32_t handleKeepHighest = keepHighest(highest);

	// Check for invalid input
	if (handleKeepHighest == -1) {
		printf("Uh oh, the number of \e[0;31mhighest\e[0m dices to keep (\e[0;31mH\e[0m) is out of range (0~%d).\n", gNumDices);
		return -1;
	}

	// Skip if no dices to keep
	if (gNumDices - getKeptDices() == 0) {
		return 0;
	}

	// Read the number of lowest dices to keep
	printf("Number of \e[0;36mlowest\e[0m  dices to keep (0<=\e[0;36mL\e[0m<=%d): ", gNumDices - highest);
	if (scanf("%d", &lowest) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Keep the lowest dices
	int32_t handleKeepLowest = keepLowest(lowest);

	// Check for invalid input
	if (handleKeepLowest == -1) {
		printf("Uh oh, the number of \e[0;36mlowest\e[0m dices to keep (\e[0;36mL\e[0m) is out of range (0~%d).\n", gNumDices);
		return -1;
	}

	// Return 0 if success
	return 0;
}

int32_t callSetSumShift() {
	int32_t value = 0;

	// Read the value of the sum shift
	printf("==== \e[0;33mAdd\e[0m number to sum ====\n");
	printf("Number to \e[0;33madd\e[0m to the sum (-10<=\e[0;33mB\e[0m<=10): ");
	if (scanf("%d", &value) != 1) {
		printf("Uh oh, this is not a valid number.\n");
		while (getchar() != '\n');
		return -1;
	}

	// Set the sum shift
	int32_t handleSetSumShift = setSumShift(value);

	// Check for invalid input
	if (handleSetSumShift == -1) {
		printf("Uh oh, the value to add to the sum (\e[0;33mB\e[0m) is out of range (-10~10).\n");
		return -1;
	}

	// Return 0 if success
	return 0;
}
