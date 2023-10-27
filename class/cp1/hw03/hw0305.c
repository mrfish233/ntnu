#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"
#include "diceMenu.h"

int main() {
	// Print the menu
	printMenu();

	// Handle the user's choice
	while (handleChoice() != 0);

	return 0;
}
