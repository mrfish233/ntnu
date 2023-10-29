#include "rpgStory.h"

FILE *gStoryFile = NULL;
char gStoryFileName[256] = "rpgStory.txt";

static const int32_t BIG_SUCCESS = 2;
static const int32_t SUCCESS     = 1;
static const int32_t FAILURE     = 0;
static const int32_t BIG_FAILURE = -1;

static void printSystemMessageLine(char *str);

static int32_t week1(int32_t option);

int32_t rpgStoryInit() {
	// Open the file
	gStoryFile = fopen(gStoryFileName, "r");

	// Check if the file is opened successfully
	if (gStoryFile == NULL) {
		printf("Uh oh, the file %s cannot be opened.\n", gStoryFileName);
		printf("Please check if the file exists and you have the permission to access it.\n");
		printf("The game will stop now.\n");
		return -1;
	}

	// Return 0
	return 0;
}

int32_t rpgStoryClear() {
	// Check if the file is opened
	if (gStoryFile == NULL) {
		printf("Uh oh, the file %s is not opened.\n", gStoryFileName);
		printf("Please check if the file exists and you have the permission to access it.\n");
		printf("The game will stop now.\n");
		return -1;
	}

	// Close the file
	fclose(gStoryFile);

	// Return 0
	return 0;
}

int32_t rpgStoryWeek(int32_t week) {
	// Check week number is valid (1-8)
	if (week < 1 || week > 8) {
		printf("Uh oh, the week number %d is invalid.\n", week);
		printf("Please check if the week number is between 1 and 8.\n");
		printf("The game will stop now.\n");
		return -1;
	}

	// Rewind the file
	rewind(gStoryFile);

	// Check if the file is opened
	if (gStoryFile == NULL) {
		printf("Uh oh, the file %s is not opened.\n", gStoryFileName);
		printf("Please check if the file exists and you have the permission to access it.\n");
		printf("The game will stop now.\n");
		return -1;
	}

	// Find the week in the file, each week has 15 lines
	int32_t line = (week - 1) * 15;

	// Skip the lines
	for (int32_t i = 0; i < line; i++) {
		char buffer[256];
		fgets(buffer, 256, gStoryFile);

		// Check if the file is ended
		if (feof(gStoryFile)) {
			printf("Uh oh, the file %s is ended.\n", gStoryFileName);
			printf("Please check if the file is corrupted.\n");
			printf("The game will stop now.\n");
			return -1;
		}
	}

	// Print the story until the character '&'
	char c = 0;
	while ((c = fgetc(gStoryFile)) != '&') {
		printf("%c", c);

		// Check if the file is ended
		if (feof(gStoryFile)) {
			printf("Uh oh, the file %s is ended.\n", gStoryFileName);
			printf("Please check if the file is corrupted.\n");
			printf("The game will stop now.\n");
			return -1;
		}
	}
	printf("\n");

	// Return 0
	return 0;
}

int32_t rpgStoryRollCheck(int32_t check, char *str) {
	int32_t result = 0;

	// Print in yellow color
	printf("\033[33m> %s Check 1d20: \n", str);

	// Roll a d20
	int32_t roll = rollDices(1, 20);
	printf("> ");
	printDice(0);

	printf("> ");
	if (roll == 1) {
		printf("Critical success!");
		result = BIG_SUCCESS;
	} else if (roll <= check) {
		printf("Success!");
		result = SUCCESS;
	} else if (roll == 20) {
		printf("Critical failure!");
		result = BIG_FAILURE;
	} else {
		printf("Failure!");
		result = FAILURE;
	}

	// Reset the color
	printf("\033[0m\n");

	// Return the result
	return result;
}

int32_t rpgStoryOptionHandle(int32_t week, int32_t option) {
	if (option == 0) {
		// Print the player stats if the option is 0
		return -2;
	} else if (option == 99) {
		// Force the game to end if the option is 99
		return -3;
	}

	// Different options for different weeks
	if (week == 1) return week1(option);

	// Return -1 if the option is invalid
	return -1;
}

static void printSystemMessageLine(char *str) {
	// Print in yellow color
	printf("\033[33m> %s\033[0m\n", str);
}

static int32_t week1(int32_t option) {
	int32_t rollCheck = 0;

	if (option != 1 && option != 2) {
		return -1;
	}

	if (option == 1) {
		printf("You looked around the town.\n");
		printf("You tried to find some useful items.\n");

		// Make a DEX check
		rollCheck = rpgStoryRollCheck(getPlayerDEX(), "DEX");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You found a book. The book's cover has a big letter \'C\'.\n");
			printf("You put the book into your bag.\n");

			printSystemMessageLine("Item added: Book \'C\'");

			// Add the book to the inventory
			setPlayerInventory(1, 1);
		} else { // if (rollCheck == BIG_FAILURE || rollCheck == FAILURE) {
			printf("You found a coupon. Seems like it's a book coupon.\n");
			printf("You put the coupon into your bag.\n");

			printSystemMessageLine("Item added: Book Coupon");

			// Add the coupon to the inventory
			setPlayerInventory(2, 1);
		}

		printf("While you were looking around, you heard someone talking about an event.\n");
		printf("The event is called \"CPI Town Festival\".\n");
		printf("The event will be held in the other village next week.\n");
		printf("You decided to go to the event.\n");
		printf("\n");
	} else if (option == 2) {
		printf("You asked the townspeople about the town.\n");
		printf("You met a person who is willing to help you.\n");
		printf("His name is W.D.Roha and he is a local.\n");

		// Make a INT check
		rollCheck = rpgStoryRollCheck(getPlayerINT(), "INT");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You got a map of the town from him.\n");
			printf("You put the map into your bag.\n");

			printSystemMessageLine("Item added: Map");

			// Add the map to the inventory
			setPlayerInventory(3, 1);
		} else { // if (rollCheck == BIG_FAILURE || rollCheck == FAILURE) {
			printf("You knew that this town has 4 villages.\n");
			printf("The village you are in is called \"Village C\".\n");
		}

		printf("From the conversation, you learned that the town has a festival every year.\n");
		printf("The festival is called \"CPI Town Festival\".\n");
		printf("The festival will be held in the other village next week.\n");
		printf("You decided to go to the festival.\n");
		printf("\n");
	}

	// Go to week 2
	return 2;
}
