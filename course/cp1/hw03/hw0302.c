#include <stdio.h>
#include <stdint.h>
#include "mycontrol.h"

// Constant
const long double PI = 3.14159265358979323846L;

void printMenu() {
	printf("0. Exit\n");
	printf("1. Initialize the character\n");
	printf("2. Move forward\n");
	printf("3. Turn clockwise\n");
	printf("4. Turn counterclockwise\n");
	printf("5. Print the character's position and angle\n");
}

double degreeToRadians(double degree) {
	return degree * PI / 180.0;
}

void handleMenuOption(int32_t menuOption) {
	if (menuOption == 0) {
		// Exit
		printf("Bye!\n");
	} else if (menuOption == 1) {
		// Initialize the character
		double x = 0, y = 0, a = 0;

		printf("Enter x, y, a: ");
		scanf("%lf %lf %lf", &x, &y, &a);

		initialize(x, y, degreeToRadians(a));
	} else if (menuOption == 2) {
		// Move forward
		double length = 0;

		printf("Enter length: ");
		scanf("%lf", &length);

		if (forward(length) == -1) {
			printf("The character is not initialized!\n");
			return;
		}

		printf("The character moved!\n");
	} else if (menuOption == 3 || menuOption == 4) {
		// Turn clockwise
		double angle = 0;

		printf("Enter angle: ");
		scanf("%lf", &angle);

		if (menuOption == 4) {
			angle = -angle;
		}

		if (clock_turn(degreeToRadians(angle)) == -1) {
			printf("The character is not initialized!\n");
			return;
		}

		if (menuOption == 4) {
			printf("The character turned counterclockwise!\n");
		} else {
			printf("The character turned clockwise!\n");
		}
	} else if (menuOption == 5) {
		// Print the character's position and angle
		if (print() == -1) {
			printf("The character is not initialized!\n");
			return;
		}
	} else {
		printf("Invalid option\n");
	}
}

int main() {
	int32_t menuOption = -1;

	printMenu();

	while (menuOption != 0) {
		printf("--------------------------------------\n");
		printf("Enter your option: ");
		scanf("%d", &menuOption);

		handleMenuOption(menuOption);
	}

	return 0;
}
