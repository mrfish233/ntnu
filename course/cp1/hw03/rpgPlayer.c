#include "rpgPlayer.h"

// Player struct
static struct Player {
	enum PlayerClass class;

	int32_t STR;
	int32_t INT;
	int32_t DEX;

	int32_t health;
	int32_t sanity;
	int32_t luck;

	int32_t maxHealth;
	int32_t maxSanity;

	struct Inventory {
		int32_t total;
		int32_t book_c;
		int32_t book_coupon;
		int32_t map;
		int32_t i_pass;
		int32_t o_pass;
	} inventory;
} gPlayer;

void clearPlayer() {
	gPlayer.class = CLASS_NONE;

	gPlayer.STR = 0;
	gPlayer.INT = 0;
	gPlayer.DEX = 0;

	gPlayer.health = 0;
	gPlayer.sanity = 0;
	gPlayer.luck   = 0;

	gPlayer.maxHealth = 0;
	gPlayer.maxSanity = 0;

	// Clear the inventory with loop
	int32_t *inventory = (int32_t *)&gPlayer.inventory;
	for (uint64_t i = 0; i < sizeof(gPlayer.inventory) / sizeof(int32_t); i++) {
		inventory[i] = 0;
	}
}

void initPlayer(enum PlayerClass class) {
	// Clear the player
	clearPlayer();

	// Set the class
	gPlayer.class = class;

	// Roll the attributes (STR, DEX, INT) with 4d6, keep 3 highest
	gPlayer.STR = rollPlayerStat(4, 6, 3);

	// Print STR dice rolls
	// if (class == CLASS_WARRIOR) {
	// 	printf("==== STR (4d6k\e[0;31mh3\e[0m+4) ====\n");
	// } else {
	// 	printf("==== STR (4d6k\e[0;31mh3\e[0m) ====\n");
	// }
	printf("STR Roll: ");
	printSimpleDices();

	gPlayer.INT = rollPlayerStat(4, 6, 3);

	// Print INT dice rolls
	// if (class == CLASS_MAGE) {
	// 	printf("==== INT (4d6k\e[0;31mh3\e[0m+4) ====\n");
	// } else {
	// 	printf("==== INT (4d6k\e[0;31mh3\e[0m) ====\n");
	// }
	printf("INT Roll: ");
	printSimpleDices();

	gPlayer.DEX = rollPlayerStat(4, 6, 3);

	// Print DEX dice rolls
	// if (class == CLASS_ROGUE) {
	// 	printf("==== DEX (4d6k\e[0;31mh3\e[0m+4) ====\n");
	// } else {
	// 	printf("==== DEX (4d6k\e[0;31mh3\e[0m) ====\n");
	// }
	printf("DEX Roll: ");
	printSimpleDices();

	// Set the health, sanity, and luck based on the attributes
	gPlayer.health = gPlayer.DEX / 2 + gPlayer.STR / 2;
	gPlayer.sanity = gPlayer.STR / 2 + gPlayer.INT / 2;
	gPlayer.luck   = gPlayer.INT / 2 + gPlayer.DEX / 2;

	// Set the max health and sanity
	gPlayer.maxHealth = gPlayer.health;
	gPlayer.maxSanity = gPlayer.sanity;

	int32_t bonus = 3;

	// Different classes have different bonuses
	if (class == CLASS_WARRIOR) {
		gPlayer.STR += bonus;
		if (gPlayer.STR > 18) {
			gPlayer.STR = 18;
		}

		gPlayer.health += bonus;
		gPlayer.maxHealth += bonus;
	} else if (class == CLASS_MAGE) {
		gPlayer.INT += bonus;
		if (gPlayer.INT > 18) {
			gPlayer.INT = 18;
		}

		gPlayer.sanity += bonus;
		gPlayer.maxSanity += bonus;
	} else if (class == CLASS_ROGUE) {
		gPlayer.DEX += bonus;
		if (gPlayer.DEX > 18) {
			gPlayer.DEX = 18;
		}

		gPlayer.luck += bonus;
	}
}

void printPlayer() {

	/* Example output:
		+----------- Player Stats -----------+
		|                                    |
		| CLASS: WARRIOR                     |
		|                                    |
		| HP:  20/20  SAN: 20/20  Luck: 20   |
		| STR: 20     INT: 20     DEX:  20   |
		|                                    |
		| ITEMS:                             |
		|   1. BOOK OF C                     |
		|                                    |
		+------------------------------------+
	*/

	// Print the top border
	printf("+----------- Player Stats -----------+\n");
	printf("|                                    |\n");

	// Print the class
	printf("| CLASS: ");
	if (gPlayer.class == CLASS_NONE) {
		printf("NONE   ");
	} else if (gPlayer.class == CLASS_WARRIOR) {
		printf("WARRIOR");
	} else if (gPlayer.class == CLASS_ROGUE) {
		printf("ROGUE  ");
	} else if (gPlayer.class == CLASS_MAGE) {
		printf("MAGE   ");
	}
	printf("                     |\n");
	printf("|                                    |\n");

	// Print the health, sanity, and luck
	printf("| HP:  %02d/%02d  SAN: %02d/%02d  Luck: %2d   |\n",
		gPlayer.health, gPlayer.maxHealth,
		gPlayer.sanity, gPlayer.maxSanity,
		gPlayer.luck);

	// Print the attributes
	printf("| STR: %02d     INT: %02d     DEX:  %02d   |\n",
		gPlayer.STR, gPlayer.INT, gPlayer.DEX);
	printf("|                                    |\n");

	// Print the items
	printf("| ITEMS:                             |\n");
	if (gPlayer.inventory.total == 0) {
		printf("|   None                             |\n");
	} else {
		// Loop through the inventory, starting from the second item (first item is total)
		int32_t *inventory = (int32_t *)&gPlayer.inventory;
		int32_t counter = 1;
		for (uint64_t i = 1; i < sizeof(gPlayer.inventory) / sizeof(int32_t); i++) {
			// Print the item if it is not 0
			if (inventory[i] != 0) {
				printf("|   %2d. ", counter);
				if (i == 1) {
					printf("Book 'C'                     |");
				} else if (i == 2) {
					printf("Book Coupon                  |");
				} else if (i == 3) {
					printf("CPI Town Map                 |");
				} else if (i == 4) {
					printf("\"I Pass\" Card                |");
				} else if (i == 5) {
					printf("Food \"O Pass\"                |");
				}
				printf("\n");

				// Increase the counter
				counter++;
			}
		}
	}

	// Print the bottom border
	printf("|                                    |\n");
	printf("+------------------------------------+\n");
}

int32_t getPlayerSTR() {
	return gPlayer.STR;
}

int32_t getPlayerINT() {
	return gPlayer.INT;
}

int32_t getPlayerDEX() {
	return gPlayer.DEX;
}

int32_t getPlayerHealth() {
	return gPlayer.health;
}

int32_t getPlayerSanity() {
	return gPlayer.sanity;
}

int32_t getPlayerLuck() {
	return gPlayer.luck;
}

int32_t getPlayerInventory(uint64_t index) {
	// Check if the index is valid (index 0 is total)
	if (index >= sizeof(gPlayer.inventory) / sizeof(int32_t)) {
		return -1;
	}

	// Return 1 if the item is in the inventory, 0 otherwise
	int32_t *inventory = (int32_t *)&gPlayer.inventory;
	return (inventory[index] != 0);
}

void setPlayerSTR(int32_t newSTR) {
	if (newSTR < 6) {
		newSTR = 6;
	} else if (newSTR > 18) {
		newSTR = 18;
	}

	gPlayer.STR = newSTR;
}

void setPlayerINT(int32_t newINT) {
	if (newINT < 6) {
		newINT = 6;
	} else if (newINT > 18) {
		newINT = 18;
	}

	gPlayer.INT = newINT;
}

void setPlayerDEX(int32_t newDEX) {
	if (newDEX < 6) {
		newDEX = 6;
	} else if (newDEX > 18) {
		newDEX = 18;
	}

	gPlayer.DEX = newDEX;
}

void setPlayerHealth(int32_t newHealth) {
	if (newHealth < 0) {
		newHealth = 0;
	} else if (newHealth > gPlayer.maxHealth) {
		newHealth = gPlayer.maxHealth;
	}

	gPlayer.health = newHealth;
}

void setPlayerSanity(int32_t newSanity) {
	if (newSanity < 0) {
		newSanity = 0;
	} else if (newSanity > gPlayer.maxSanity) {
		newSanity = gPlayer.maxSanity;
	}

	gPlayer.sanity = newSanity;
}

void setPlayerLuck(int32_t newLuck) {
	if (newLuck < 0) {
		newLuck = 0;
	} else if (newLuck > 18) {
		newLuck = 18;
	}

	gPlayer.luck = newLuck;
}

int32_t setPlayerInventory(uint64_t index, int32_t newValue) {
	// Check if the index is valid (index 0 is total)
	if (index >= sizeof(gPlayer.inventory) / sizeof(int32_t)) {
		return -1;
	}

	// Get the inventory
	int32_t *inventory = (int32_t *)&gPlayer.inventory;

	// Check if the item is not in the inventory
	if (inventory[index] == 0 && newValue == 0) {
		return -2;
	}

	// Check if the item is already in the inventory
	if (inventory[index] == 1 && newValue == 1) {
		return -3;
	}

	// Update total
	if (newValue == 0 && inventory[index] == 1) {
		gPlayer.inventory.total--;
	} else if (newValue == 1 && inventory[index] == 0) {
		gPlayer.inventory.total++;
	}

	// Set the item
	inventory[index] = newValue;

	// Return 1 if the item is added successfully, 0 if the item is removed successfully
	return newValue;
}

int32_t rollPlayerStat(int32_t numDice, int32_t numSides, int32_t highest) {
	// Roll the dices
	rollDices(numDice, numSides);

	// Keep the highest dices
	keepHighest(highest);

	// Return the sum of the kept dices
	return getSumKept();
}
