#include "rpgHandle.h"

#ifndef RPG_CONSTANT
#define ATTRIBUTE_STR 1
#define ATTRIBUTE_INT 2
#define ATTRIBUTE_DEX 3

#define ITEM_BOOK    1
#define ITEM_COUPON  2
#define ITEM_MAP     3
#define ITEM_CARD    4
#define ITEM_FOOD    5

#define BIG_SUCCESS  2
#define SUCCESS      1
#define FAILURE      0
#define BIG_FAILURE -1
#endif // RPG_CONSTANT

int32_t rpgHandleStatus() {
	// Return -1 if the player is dead or insane
	if (getPlayerHealth() == 0 || getPlayerSanity() == 0) {
		return -1;
	}

	// Return 0 if the player is alive
	return 0;
}

int32_t rpgHandleHealth(int32_t numDices, int32_t sides, int32_t value) {
	int32_t healthChange = 0;

	// Roll dices
	if (numDices != 0) {
		if (numDices < 0) {
			numDices = -numDices;
			healthChange += -rollDices(numDices, sides);
		} else {
			healthChange += rollDices(numDices, sides);
		}
		printf("\033[33m");
		if (value < 0) {
			printf("> Roll %dd%d+%d: \n", numDices, sides, -value);
		} else if (value == 0) {
			printf("> Roll %dd%d: \n", numDices, sides);
		} else {
			printf("> Roll %dd%d+%d: \n", numDices, sides, value);
		}
		printDice(0);
		printf("\033[0m");
	}

	// Add value to sum
	healthChange += value;

	int32_t oldHealth = getPlayerHealth();
	int32_t newHealth = 0;

	// Set the health
	setPlayerHealth(getPlayerHealth() + healthChange);
	newHealth = getPlayerHealth();

	// Check the health change
	if (newHealth > oldHealth) {
		printf("\033[33m> You gained %d HP.\033[0m\n", newHealth - oldHealth);
	} else if (newHealth < oldHealth) {
		printf("\033[33m> You lost %d HP.\033[0m\n", oldHealth - newHealth);
	} else {
		printf("\033[33m> Your HP remained unchanged.\033[0m\n");
	}

	// Check if the player is dead
	if (getPlayerHealth() == 0) {
		printf("\033[33m> You died.\033[0m\n");
	}

	// Handle the status
	return rpgHandleStatus();
}

int32_t rpgHandleSanity(int32_t numDices, int32_t sides, int32_t value) {
	int32_t sanChange = 0;

	// Roll dices
	if (numDices != 0) {
		if (numDices < 0) {
			numDices = -numDices;
			sanChange += -rollDices(numDices, sides);
		} else {
			sanChange += rollDices(numDices, sides);
		}
		printf("\033[33m");
		if (value < 0) {
			printf("> Roll %dd%d+%d: \n", numDices, sides, -value);
		} else if (value == 0) {
			printf("> Roll %dd%d: \n", numDices, sides);
		} else {
			printf("> Roll %dd%d+%d: \n", numDices, sides, value);
		}
		printDice(0);
		printf("\033[0m");
	}

	// Add value to sum
	sanChange += value;

	int32_t oldSanity = getPlayerSanity();
	int32_t newSanity = 0;

	// Set the sanity
	setPlayerSanity(getPlayerSanity() + sanChange);
	newSanity = getPlayerSanity();

	// Check the sanity change
	if (newSanity > oldSanity) {
		printf("\033[33m> You gained %d SAN.\033[0m\n", newSanity - oldSanity);
	} else if (newSanity < oldSanity) {
		printf("\033[33m> You lost %d SAN.\033[0m\n", oldSanity - newSanity);
	} else {
		printf("\033[33m> Your SAN remained changed.\033[0m\n");
	}

	// Check if the player is insane
	if (getPlayerSanity() == 0) {
		printf("\033[33m> You went insane.\033[0m\n");
	}

	// Handle the status
	return rpgHandleStatus();
}

void rpgHandleAttribute(int32_t attribute, int32_t value) {
	int32_t oldAttribute = 0;
	int32_t newAttribute = 0;

	if (attribute == ATTRIBUTE_STR) {
		// Get the old value
		oldAttribute = getPlayerSTR();

		// Set the new value
		setPlayerSTR(getPlayerSTR() + value);
		newAttribute = getPlayerSTR();

		// Compare the old value and the new value
		if (newAttribute > oldAttribute) {
			printf("\033[33m> You gained %d STR.\033[0m\n", newAttribute - oldAttribute);
		} else if (newAttribute < oldAttribute) {
			printf("\033[33m> You lost %d STR.\033[0m\n", oldAttribute - newAttribute);
		} else {
			printf("\033[33m> Your STR remained unchanged.\033[0m\n");
		}
	} else if (attribute == ATTRIBUTE_INT) {
		// Get the old value
		oldAttribute = getPlayerINT();

		// Set the new value
		setPlayerINT(getPlayerINT() + value);
		newAttribute = getPlayerINT();

		// Compare the old value and the new value
		if (newAttribute > oldAttribute) {
			printf("\033[33m> You gained %d INT.\033[0m\n", newAttribute - oldAttribute);
		} else if (newAttribute < oldAttribute) {
			printf("\033[33m> You lost %d INT.\033[0m\n", oldAttribute - newAttribute);
		} else {
			printf("\033[33m> Your INT remained unchanged.\033[0m\n");
		}
	} else if (attribute == ATTRIBUTE_DEX) {
		// Get the old value
		oldAttribute = getPlayerDEX();

		// Set the new value
		setPlayerDEX(getPlayerDEX() + value);
		newAttribute = getPlayerDEX();

		// Compare the old value and the new value
		if (newAttribute > oldAttribute) {
			printf("\033[33m> You gained %d DEX.\033[0m\n", newAttribute - oldAttribute);
		} else if (newAttribute < oldAttribute) {
			printf("\033[33m> You lost %d DEX.\033[0m\n", oldAttribute - newAttribute);
		} else {
			printf("\033[33m> Your DEX remained unchanged.\033[0m\n");
		}
	} else {
		printf("\033[33m> Unknown attribute.\033[0m\n");
	}
}

void rpgHandleInventory(int32_t index, int32_t value) {
	int32_t handler = setPlayerInventory(index, value);

	const char item[6][32] = {
		"Book 'C'",
		"Book Coupon",
		"CPI Town Map",
		"\"I Pass\" Card",
		"Food \"O Pass\"",
	};

	// Handle the inventory
	printf("\033[33m> ");
	if (handler == -2) {
		printf("The item %s is not in the inventory.", item[index - 1]);
	} else if (handler == -3) {
		printf("The item %s is already in the inventory.", item[index - 1]);
	} else if (handler == 1) {
		printf("Item added: %s", item[index - 1]);
	} else if (handler == 0) {
		printf("Item removed: %s", item[index - 1]);
	} else {
		printf("Unknown error.\033[0m\n");
	}
	printf("\033[0m\n");
}
