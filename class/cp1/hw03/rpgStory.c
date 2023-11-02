#include "rpgStory.h"

FILE *gStoryFile = NULL;
char gStoryFileName[256] = "rpgStory.txt";

static const int32_t BIG_SUCCESS = 2;
static const int32_t SUCCESS     = 1;
static const int32_t FAILURE     = 0;
static const int32_t BIG_FAILURE = -1;

static void printSystemMessageLine(char *str);

static void rpgStoryHandleHealth(int32_t numDices, int32_t sides, int32_t value);
static void rpgStoryHandleSanity(int32_t numDices, int32_t sides, int32_t value);
static int32_t rpgStoryHandlePlayerStatus();
static void rpgStoryHandleInventory(char *itemName, int32_t index, int32_t value);

static int32_t week1(int32_t option);
static int32_t week2(int32_t option);
static int32_t week3(int32_t option);
static int32_t week4(int32_t option);
static int32_t week5(int32_t option);
static int32_t week6(int32_t option);

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
	char buffer[512];
	for (int32_t i = 0; i < line; i++) {
		fgets(buffer, 512, gStoryFile);

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
	printf("\033[33m> %s: \n", str);

	// Roll a d20
	int32_t roll = rollDices(1, 20);
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
	if (week == 2) return week2(option);
	if (week == 3) return week3(option);
	if (week == 4) return week4(option);
	if (week == 5) return week5(option);
	if (week == 6) return week6(option);

	// Return -1 if the option is invalid
	return -1;
}

static void printSystemMessageLine(char *str) {
	// Print in yellow color
	printf("\033[33m> %s\033[0m\n", str);
}

static void rpgStoryHandleHealth(int32_t numDices, int32_t sides, int32_t value) {
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

	// Set the healtn
	setPlayerHealth(getPlayerHealth() + healthChange);

	// Check if the value is positive
	if (healthChange < 0) {
		printf("\033[33m> You lost %d HP.\033[0m\n", -healthChange);
	} else if (healthChange > 0) {
		printf("\033[33m> You gained %d HP.\033[0m\n", healthChange);
	} else {
		printf("\033[33m> Your HP remained unchanged.\033[0m\n");
	}
}

static void rpgStoryHandleSanity(int32_t numDices, int32_t sides, int32_t value) {
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

	// Set the sanity
	setPlayerSanity(getPlayerSanity() + sanChange);

	// Check if the value is positive
	if (sanChange < 0) {
		printf("\033[33m> You lost %d SAN.\033[0m\n", -sanChange);
	} else if (sanChange > 0) {
		printf("\033[33m> You gained %d SAN.\033[0m\n", sanChange);
	} else {
		printf("\033[33m> Your SAN remained changed.\033[0m\n");
	}
}

static int32_t rpgStoryHandlePlayerStatus() {
	// Return -1 if the player is dead or insane
	if (getPlayerHealth() <= 0) {
		printSystemMessageLine("You died.");
		return -1;
	} else if (getPlayerSanity() <= 0) {
		printSystemMessageLine("You went insane.");
		return -1;
	}

	// Return 0 if the player is alive
	return 0;
}

static void rpgStoryHandleInventory(char *itemName, int32_t index, int32_t value) {
	int32_t handler = setPlayerInventory(index, value);

	// Handle the inventory
	printf("\033[33m> ");
	if (handler == -2) {
		printf("The item %s is not in the inventory.", itemName);
	} else if (handler == -3) {
		printf("The item %s is already in the inventory.", itemName);
	} else if (handler == 1) {
		printf("Item added: %s", itemName);
	} else if (handler == 0) {
		printf("Item removed: %s", itemName);
	} else {
		printf("Unknown error.\033[0m\n");
	}
	printf("\033[0m\n");
}

static int32_t week1(int32_t option) {
	int32_t rollCheck = 0;

	if (option != 1 && option != 2) {
		return -1;
	}

	if (option == 1) {
		printf("You looked around the town and tried to find some useful items.\n");

		// Make a DEX check
		rollCheck = rpgStoryRollCheck(getPlayerDEX(), "DEX Check");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You found a book. The book's cover has a big letter 'C'. You put the book into your bag.\n");

			// Add the book to the inventory
			rpgStoryHandleInventory("Book 'C'", 1, 1);
		} else { // if (rollCheck == BIG_FAILURE || rollCheck == FAILURE) {
			printf("You found a coupon. Seems like it's a book coupon. You put the coupon into your bag.\n");

			// Add the coupon to the inventory
			rpgStoryHandleInventory("Book Coupon", 2, 1);
		}

		printf("While you were looking around, you heard someone talking about an event. The event is called \"CPI Town Festival\". The event will be held in the other village next week. You decided to go to the event.\n");
	} else if (option == 2) {
		printf("You asked the townspeople about the town. You met a person who is willing to help you. His name is W.D.Roha and he is a local.\n");

		// Make a INT check
		rollCheck = rpgStoryRollCheck(getPlayerINT(), "INT Check");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You got a map of the town from him. You put the map into your bag.\n");

			// Add the map to the inventory
			rpgStoryHandleInventory("CPI Town Map", 3, 1);
		} else { // if (rollCheck == BIG_FAILURE || rollCheck == FAILURE) {
			printf("You knew that this town has 3 villages. The village you are in is called \"Village C\".\n");
		}

		printf("From the conversation, you learned that the town has a festival every year. The festival is called \"CPI Town Festival\". The festival will be held in the other village next week. You decided to go to the festival.\n");
	}

	printf("\n");

	// Go to week 2
	return 2;
}

static int32_t week2(int32_t option) {
	int32_t rollCheck = 0;

	if (option != 1 && option != 2) {
		return -1;
	}

	if (option == 1) {
		printf("You went to the show. The show was held at the center of the village. The show just started when you arrived. From the show, you learned that the show was called \"LET ME PASS\". Around 60 people performed in the show and everyone looked scary. Suddenly, they started to run towards you. You felt scared.\n");

		// Make a SAN check
		rollCheck = rpgStoryRollCheck(getPlayerSanity(), "SAN Check 0/1");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("Although you were scared, you were able to stay calm. You realized the performers were just trying to scare you.\n");

			// Decrease the SAN by 0
			rpgStoryHandleSanity(0, 0, 0);
		} else { // if (rollCheck == FAILURE || rollCheck == BIG_FAILURE) {
			printf("You were scared and decided to leave the show.\n");

			// Decrease the SAN by 1
			rpgStoryHandleSanity(0, 0, -1);
		}

		// Check the player status
		if (rpgStoryHandlePlayerStatus() == -1) {
			return -1;
		}

		printf("After the show, a person came to you. His name is A.A.Klat and watched the show. From the conversation, you knew that the show was inspired by a card. The card is called \"I Pass\". He gave you one.\n");

		// Add the card to the inventory
		rpgStoryHandleInventory("I Pass", 4, 1);

		printf("The card is used to pass village I. Every year, there was about half of the people who can't pass village I. That made them unable to go to village II and some other town. You kept that in mind.\n");
	} else if (option == 2) {
		printf("You went to the \"FOOD FES\". There were many food stalls in the festival. You tried some of the food and found a special one. The food is called \"O Pass\". The food stall owner gave you one of the food.\n");

		// Add the food to the inventory
		rpgStoryHandleInventory("O Pass", 5, 1);

		printf("The food can be used to pass village II. The food was important to intel people in the village. You kept that in mind.\n");
	}

	printf("\n");

	// Go to week 3
	return 3;
}

static int32_t week3(int32_t option) {
	int32_t rollCheck = 0;

	if (option != 1 && option != 2) {
		return -1;
	}

	if (option == 1) {
		printf("You talked to the shop keeper H.K.Snogy.\n");

		// If the player has the book
		if (getPlayerInventory(1) == 1) {
			printf("You showed the book 'C' to the shop keeper. The shop keeper was surprised and told you that the book is very important. You learned more about the book.\n");

			// INcrease INT by 1
			setPlayerINT(getPlayerINT() + 1);
			printSystemMessageLine("You gained 1 INT.");
		} else if (getPlayerInventory(2) == 1) { // If the player has the coupon
			printf("You showed the book coupon to the shop keeper. The shop keeper gave you the book 'C'.\n");

			// Remove the coupon from the inventory
			rpgStoryHandleInventory("Book Coupon", 2, 0);

			// Add the book to the inventory
			rpgStoryHandleInventory("Book 'C'", 1, 1);
		} else { // If the player has nothing
			printf("You asked the shop keeper about this place. The shop keeper told you that this place is called \"Village I\".\n");

			// Make a INT check
			rollCheck = rpgStoryRollCheck(getPlayerINT(), "INT Check");

			if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
				printf("He also gave you a book.\n");

				// Add the book to the inventory
				rpgStoryHandleInventory("Book 'C'", 1, 1);
			} else { // if (rollCheck == BIG_FAILURE || rollCheck == FAILURE) {
				printf("He said that he want to give you a book, but he doesn't have any.\n");
			}
		}
	} else if (option == 2) {
		printf("You found a random person in the store and talked to him. Suddenly, the man tried to attack you.\n");

		// Make a DEX check
		rollCheck = rpgStoryRollCheck(getPlayerDEX(), "DEX Check");

		if (rollCheck == BIG_SUCCESS) {
			printf("You dodged the attack and tried to counter attack. The man blocked your attack, said that you're strong.\n");

			// Increase STR by 1
			setPlayerSTR(getPlayerSTR() + 1);
			printSystemMessageLine("You gained 1 STR.");
		} else if (rollCheck == SUCCESS) {
			printf("You dodged the attack.\n");
		} else if (rollCheck == FAILURE) {
			printf("You were hit by the attack.\n");

			// Decrease the HP by 1
			rpgStoryHandleHealth(0, 0, -1);
		} else { // if (rollCheck == BIG_FAILURE) {
			printf("You were hit by the attack and fell down.\n");

			// Decrease the HP by 1
			rpgStoryHandleHealth(0, 0, -1);

			// Decrease the SAN by 1
			rpgStoryHandleSanity(0, 0, -1);
		}

		// Check the player status
		if (rpgStoryHandlePlayerStatus() == -1) {
			return -1;
		}

		printf("His name is B.J.Linaco and he fought the boss before. He attacked you because he wanted to test your strength.\n");
	}

	printf("From the conversation, you learned that there's a boss in this village and the boss will come after 5 weeks. The book 'C' is the key item to defeat the boss. You also learned that the map of the town was also useful when fighting boss. As fighting boss is not an easy task, you decided to improve yourself before the boss come.\n\n");

	// Go to week 4
	return 4;
}

static int32_t week4(int32_t option) {
	int32_t rollCheck = 0;

	if (option != 1 && option != 2) {
		return -1;
	}

	if (option == 1) {
		printf("You ran to the guy and tried to help him without hesitation. You realized there's monster in front of you. The monster was so terrifying.\n");

		// Make a SAN check 1/1d3
		rollCheck = rpgStoryRollCheck(getPlayerSanity(), "SAN Check 1/1d3");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You were not really scared by the monster.\n");

			// Decrease the SAN by 1
			rpgStoryHandleSanity(0, 0, -1);
		} else { // if (rollCheck == FAILURE || rollCheck == BIG_FAILURE) {
			printf("You were scared by the monster.\n");

			// Decrease the SAN by 1d3
			rpgStoryHandleSanity(-1, 3, 0);
		}

		// Check the player status
		if (rpgStoryHandlePlayerStatus() == -1) {
			return -1;
		}

		printf("You heard a voice from the guy. He told you that he needed 10 seconds to cast his ultimate spell. You protected him for 10 seconds. The monster tried to attack you.\n");

		// Make a STR check
		rollCheck = rpgStoryRollCheck(getPlayerSTR(), "STR Check");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You blocked the attack from the monster.\n");
			
		} else if (rollCheck == FAILURE) {
			printf("You got hit by the monster.\n");

			// Decrease the HP by 1
			rpgStoryHandleHealth(0, 0, -1);
		} else { // if (rollCheck == BIG_FAILURE) {
			printf("You got hit by the monster badly.\n");

			// Decrease the HP by 1d3+1
			rpgStoryHandleHealth(-1, 3, -1);
		}

		printf("\"SWITCH!\" The guy shouted. You switched position with the guy. He casted a spell and the monster was killed.\n");
	} else if (option == 2) {
		printf("You observed the situation before you help the guy. You saw a monster in front of him. The monster was so terrifying.\n");

		// Make a SAN check 0/1d2
		rollCheck = rpgStoryRollCheck(getPlayerSanity(), "SAN Check 0/1d2");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You were not scared by the monster.\n");

			// Decrease the SAN by 0
			rpgStoryHandleSanity(0, 0, 0);
		} else { // if (rollCheck == FAILURE || rollCheck == BIG_FAILURE) {
			printf("You were scared by the monster.\n");

			// Decrease the SAN by 1d2
			rpgStoryHandleSanity(-1, 2, 0);
		}

		// Check the player status
		if (rpgStoryHandlePlayerStatus() == -1) {
			return -1;
		}

		printf("You found a chance to backstab the monster. You tried to backstab the monster.\n");

		// Make a DEX check
		rollCheck = rpgStoryRollCheck(getPlayerDEX(), "DEX Check");

		if (rollCheck == BIG_SUCCESS || rollCheck == SUCCESS) {
			printf("You backstabbed the monster and killed it.\n");
		} else if (rollCheck == FAILURE) {
			printf("You missed your attack. Instead, the monster hit you.\n");

			// Decrease the HP by 1
			rpgStoryHandleHealth(0, 0, -1);

			printf("Although you were hit by the monster, you distracted the monster for 10 seconds \"SWITCH!\" The guy shouted. The guy casted a spell and the monster was killed.\n");
		} else { // if (rollCheck == BIG_FAILURE) {
			printf("You missed the monster. Instead, the monster hit you hard.\n");

			// Decrease the HP by 1d2+1
			rpgStoryHandleHealth(-1, 2, -1);

			printf("Although you were hit by the monster, you distracted the monster for 10 seconds. \"SWITCH!\" The guy shouted. The guy casted a spell and the monster was killed.\n");
		}
	}

	printf("The guy thanked you for helping him.\n\n");

	// Go to week 5
	return 5;
}

static int32_t week5(int32_t option) {
	int32_t rollCheck = 0;

	if (option < 1 || option > 3) {
		return -1;
	}

	if (option == 1) {
		printf("You opened the red iron door and entered the room. The door disappeared after entering the room. A group of people were waiting for you. They were the people who failed to pass village I. You didn't know what they were doing here. They were angry and tried to attack you.\n");

		// Make a STR check
		rollCheck = rpgStoryRollCheck(getPlayerSTR(), "STR Check");

		if (rollCheck == BIG_SUCCESS) {
			printf("As you were strong enough, you were able to defeat the group of people. You felt your strength increased.\n");

			// Increase STR by 2
			setPlayerSTR(getPlayerSTR() + 2);
			printSystemMessageLine("You gained 2 STR.");
		} else if (rollCheck == SUCCESS) {
			printf("As you were strong enough, you were able to defeat the group of people. You felt your strength increased.\n");

			// Increase STR by 1
			setPlayerSTR(getPlayerSTR() + 1);
			printSystemMessageLine("You gained 1 STR.");
		} else if (getPlayerInventory(4) == 1) { // If the player has the card
			printf("You showed the card to the group of people. They stopped attacking you and stared at the card. You took the chance, threw the card to the ground and ran away. They ran to the card and started to fight for the card. You escaped from them.\n");

			// Remove the card from the inventory
			rpgStoryHandleInventory("I Pass", 4, 0);

			// Increase DEX by 1
			setPlayerDEX(getPlayerDEX() + 1);
			printSystemMessageLine("You gained 1 DEX.");
		} else { // if (rollCheck == FAILURE || rollCheck == BIG_FAILURE) {
			printf("You were not strong enough to defeat the group of people. You were defeated by them.\n");

			// Decrease the HP by 1d2
			rpgStoryHandleHealth(-1, 2, 0);
		}
	} else if (option == 2) {
		printf("You opened the green glass door and entered the room. The door disappeared after entering the room. A lot of trees were sorrounding you. One of the trees started talking to you and asked you to help him. He told you that he was trapped in this place for a long time. You decided to help him to get out of this place.\n");

		if (getPlayerInventory(3) == 1) { // If the player has the map
			printf("You showed the map of the town to the tree. You didn't know if the tree could read the map. The tree told you that the map was the key to get out of this room. You were surprised. The tree copied the map and thanked you for helping him. You felt your intelligence increased after helping the tree.\n");

			// Increase INT by 1
			setPlayerINT(getPlayerINT() + 1);
			printSystemMessageLine("You gained 1 INT.");
		} else {
			printf("You didn't know how to help the tree. You decided to look around to find something useful.\n");

			// Make a DEX check
			rollCheck = rpgStoryRollCheck(getPlayerDEX(), "DEX Check");

			if (rollCheck == BIG_SUCCESS) {
				printf("You found a direction sign. You told the tree to follow you and you followed the direction sign. You found the exit and the tree was able to get out of this place. The tree thanked you for helping him. You felt your dexeirty increased after helping the tree.\n");

				// Increase DEX by 2
				setPlayerDEX(getPlayerDEX() + 2);
				printSystemMessageLine("You gained 2 DEX.");
			} else if (rollCheck == SUCCESS) {
				printf("You found a direction sign. You told the tree to follow you and you followed the direction sign. You found the exit and the tree was able to get out of this place. The tree thanked you for helping him. You felt your dexeirty increased after helping the tree.\n");

				// Increase DEX by 1
				setPlayerDEX(getPlayerDEX() + 1);
				printSystemMessageLine("You gained 1 DEX.");
			} else { // if (rollCheck == FAILURE || rollCheck == BIG_FAILURE) {
				printf("You didn't find anything useful. You told the tree to follow you and you walked randomly. You walked for a long time and you were tired. You decided to rest for a while. You fell asleep and never woke up again.\n");

				// Decrease the HP by 1d2
				rpgStoryHandleHealth(-1, 2, 0);
			}
		}
	} else if (option == 3) {
		printf("You opened the blue wooden door and entered the room. The door disappeared after entering the room. You saw a magician standing in front of you. He asked a question to you. \"What is the answer to life, the universe, and everything?\" You tried to answer the question.\n");

		// Make a INT check
		rollCheck = rpgStoryRollCheck(getPlayerINT(), "INT Check");

		if (rollCheck == BIG_SUCCESS) {
			printf("You answered, \"42\". The magician smiled. He twisted his hand and you felt asleep. You felt your intelligence increased after answering the question.\n");

			// Increase INT by 2
			setPlayerINT(getPlayerINT() + 2);
			printSystemMessageLine("You gained 2 INT.");
		} else if (rollCheck == SUCCESS) {
			printf("You answered, \"42\". The magician smiled. He twisted his hand and you felt asleep. You felt your intelligence increased after answering the question.\n");

			// Increase INT by 1
			setPlayerINT(getPlayerINT() + 1);
			printSystemMessageLine("You gained 1 INT.");
		} else if (getPlayerInventory(5) == 1) {
			printf("You answered, \"O Pass\". The magician smiled. He took away your \"O Pass\", twisted his hand and you felt asleep. You felt your strength increased after answering the question.\n");

			// Remove the food from the inventory
			rpgStoryHandleInventory("O Pass", 5, 0);

			// Increase STR by 1
			setPlayerSTR(getPlayerSTR() + 1);
			printSystemMessageLine("You gained 1 STR.");
		} else { // if (rollCheck == BIG_FAILURE || rollCheck == FAILURE) {
			printf("You answered, \"I don't know\". The magician didn't like your answer. He twisted his hand and you felt asleep. You felt your sanity decreased after answering the question.\n");

			// Decrease the SAN by 1
			rpgStoryHandleSanity(0, 0, -1);
		}
	}

	printf("You suddenly found yourself in a dark room. You saw nothing. You heard nothing. You felt you were dead. You felt you were insane. You felt you were nothing. You felt this is the end. Or is it?\n\n");

	// Go to week 6
	return 6;
}

static int32_t week6(int32_t option) {
	int32_t rollCheck = 0;

	if (option < 1 || option > 3) {
		return -1;
	}

	if (option == 1) {
		printf("You opened the green iron door and entered the room. You felt better. You had no time to think what was going on and you felt asleep.\n");

		// Increase HP by 1d3
		rpgStoryHandleHealth(1, 3, 0);
	} else if (option == 2) {
		printf("You opened the blue glass door and entered the room. You felt better. You had no time to think what was going on and you felt asleep.\n");

		// Increase SAN by 1
		rpgStoryHandleSanity(0, 0, 1);

		// Increase HP by 1
		rpgStoryHandleHealth(0, 0, 1);
	} else if (option == 3) {
		printf("You opened the blue glass door and entered the room. You felt better. You had no time to think what was going on and you felt asleep.\n");

		// Increase SAN by 1d3
		rpgStoryHandleSanity(1, 3, 0);
	}

	printf("You suddenly found yourself in a dark room. You saw nothing. You heard nothing. You felt you were dead. You felt you were insane. You felt you were nothing. You felt this is the end. Or is it?\n\n");

	// Go to week 7
	return 7;
}
