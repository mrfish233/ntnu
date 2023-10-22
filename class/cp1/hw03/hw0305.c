#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"
#include "diceMenu.h"

int main() {
	// int menuChoice = -1;

	// Print the menu
	printMenu();

	// Handle the user's choice
	while (handleChoice() != 0);

	// while (menuChoice != 0) {
		// char term = '\0';

		// // Read the user's choice
		// printf("--------------------------------------------------------------------------------\n");
		// printf("Your choice: ");
		// if (scanf("%d%c", &menuChoice, &term) != 2 || term != '\n') {
		// 	printf("Uh oh, looks like this is not a valid choice.\n");
		// 	while (getchar() != '\n');
		// 	continue;
		// }
		// printf("\n");

		// // Handle the user's choice
		// if (menuChoice == 0) {
		// 	printf("Goodbye!\n");
		// } else if (menuChoice == 1) {
		// 	rollDices(1, 6);
		// } else if (menuChoice == 2) {
		// 	// Read the number of dices and sides
		// 	int32_t numDices = 0;
		// 	int32_t sides    = 0;

		// 	printf("Roll AdX dices (A = number of dices, X = number of sides)\n");
		// 	printf("Number of dices(A): ");
		// 	if (scanf("%d%c", &numDices, &term) != 2 || term != '\n') {
		// 		printf("Uh oh, looks like this is not a valid number.\n");
		// 		while (getchar() != '\n');
		// 		continue;
		// 	}
		// 	printf("Number of sides(X): ");
		// 	if (scanf("%d%c", &sides, &term) != 2 || term != '\n') {
		// 		printf("Uh oh, looks like this is not a valid number.\n");
		// 		while (getchar() != '\n');
		// 		continue;
		// 	}

		// 	// Check for invalid input
		// 	if (numDices < 0 || numDices > 10) {
		// 		printf("Uh oh, looks like the number of dices is out of range (0-10).\n");
		// 		continue;
		// 	} else if (sides < 2 || sides > 100) {
		// 		printf("Uh oh, looks like the number of sides is out of range (2-100).\n");
		// 		continue;
		// 	}

		// 	// Roll the dices
		// 	printf("\n");
		// 	rollDices(numDices, sides);
		// } else {
		// 	printf("Uh oh, looks like this is not a valid choice.\n");
		// }
		// printf("\n");
	// }

	return 0;
}
