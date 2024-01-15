#include <stdio.h>
#include "diceMenu.h"

int main() {
	// Clear the screen
	system("clear");

	// Print the menu
	printMenu();
	printf("\n");

	// Handle the user's choice
	while (handleChoice() != 0);

	return 0;
}
