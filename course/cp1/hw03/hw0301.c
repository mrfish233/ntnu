#include <stdio.h>
#include <stdint.h>
#include "mycircle.h"

void printMenu() {
	printf("0. Exit\n");
	printf("1. Set radius\n");
	printf("2. Get circle circumference\n");
	printf("3. Get circle area\n");
	printf("4. Get tangent area\n");
	printf("5. Get inner regular polygon area\n");
	printf("6. Get outer regular polygon area\n");
}

void handleMenuOption(int32_t menuOption) {
	if (menuOption == 0) {
		// Exit
		printf("Bye!\n");
	} else if (menuOption == 1) {
		// Set the radius
		double rad = 0;
		printf("Enter the radius: ");
		scanf("%lf", &rad);

		int32_t r = set_radius(rad);

		if (r == -1) {
			printf("Invalid radius!\n");
		} else {
			printf("Radius set!\n");
		}
	} else if (menuOption == 2) {
		// Get the circle circumference
		double c = get_circle_circumference();

		if (c == -1) {
			printf("The radius is not set!\n");
		} else {
			printf("The circumference is %lf\n", c);
		}
	} else if (menuOption == 3) {
		// Get the circle area
		double a = get_circle_area();

		if (a == -1) {
			printf("The radius is not set!\n");
		} else {
			printf("The area is %lf\n", a);
		}
	} else if (menuOption == 4) {
		// Get the tangent area
		double x;
		printf("Enter x: ");
		scanf("%lf", &x);

		double a = get_tangent_area(x);

		if (a == -1) {
			printf("The radius is not set or x is not valid!\n");
		} else {
			printf("The area is %lf\n", a);
		}
	} else if (menuOption == 5) {
		// Get the inner regular polygon area
		int32_t n;
		printf("Enter n: ");
		scanf("%d", &n);

		double a = get_inner_regular_polygon_area(n);

		if (a == -1) {
			printf("The radius is not set or n is not valid!\n");
		} else {
			printf("The area is %lf\n", a);
		}
	} else if (menuOption == 6) {
		// Get the outer regular polygon area
		int32_t n;
		printf("Enter n: ");
		scanf("%d", &n);

		double a = get_outer_regular_polygon_area(n);

		if (a == -1) {
			printf("The radius is not set or n is not valid!\n");
		} else {
			printf("The area is %lf\n", a);
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
