#include "rpgEvent.h"

void rpgEventStartGame() {
	// Print the welcome message
	printf("Welcome to CPI-RPG!\n");

	// CPI RPG Logo
	printf("    +-------+\n");
	printf("    |   C   |\n");
	printf("    |  RPG  |\n");
	printf("    |   I   |\n");
	printf("    +-------+\n");

	// Introduction
	printf("--- Introduction ---\n");
	printf("You are a new player at CPI Town.\n");
	printf("You are excited to start your new life here.\n");
	printf("You are going to live in this town.\n");
	printf("You will have to make many decisions.\n");
	printf("Now, let's start your journey!\n");
	printf("\n");

	// Select the class
	printf("--- Select Class ---\n");
	printf("You can select one of the following classes:\n");
	printf("1. WARRIOR, a class with higher STR and HP\n");
	printf("2. ROGUE,   a class with higher DEX and Luck\n");
	printf("3. MAGE,    a class with higher INT and SAN\n");
	printf("\n");

	// Get the class
	int32_t class = 0;
	while (class < 1 || class > 3) {
		printf("Select your class: ");
		scanf("%d", &class);

		// Check if the input is valid
		if (class < 1 || class > 3) {
			printf("Uh oh, that's not a valid class, please select again.\n");
		}
	}
	printf("\n");

	// Initialize the player
	printf("--- Initialize Player ---\n");
	printf("Rolling stats...\n");
	initPlayer(class);

	// Print the player stats
	printPlayer();
	printf("\n");

	// Start the game
	printf("Let's play the game!\n");
	printf("--- Game Start ---\n");
}

void rpgEventGameProcess() {
	// Start the game
	rpgEventStartGame();

	// Initialize the story file and check if it is opened successfully
	if (rpgStoryInit() == -1) {
		return;
	}

	// Handle the week
	int32_t week = 1;
	while (rpgStoryWeek(week) == 0) {
		// Handle the option
		int32_t option = 0, handleOption = -1;
		while (handleOption == -1) {
			// Get the option
			printf("\033[33m> Select your option: ");
			scanf("%d", &option);
			printf("\033[0m\n");

			// Handle the option
			handleOption = rpgStoryOptionHandle(week, option);

			// Handle the special case
			if (handleOption == -2) {
				// If the option is -2, print the player stats
				printPlayer();
				printf("\n");

				// Reset the handle option
				handleOption = -1;
				continue;
			} else if (handleOption == -1) {
				// If the option is invalid, reinput the option
				printf("Uh oh, that's not a valid option, please select again.\n");
			} else if (handleOption == 0 || handleOption == -3) {
				// If the option is 0 or -3, the game is over
				break;
			} else {
				// If the option is valid, update the week
				week = handleOption;
			}
		}

		// Check if the game is over
		if (handleOption == 0) {
			printf("The game is over.\n");
			break;
		} else if (handleOption == -3) {
			printf("The game is ended by the player.\n");
			break;
		}
	}

	// Clear the story
	rpgStoryClear();
}
