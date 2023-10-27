#include <stdio.h>
#include <stdint.h>
#include "mycontrol.h"

// Constant
const long double PI = 3.14159265358979323846L;

void testControl(double x, double y, double a) {
	// Setup the initial position to (x,y) and the moving direction.
	initialize(x, y, a);
	print();

	// Move forward by the given distance.
	forward(1.333);
	print();

	// Turn clockwise by the given angle.
	clock_turn(0.5 * PI);
	forward(5.678);
	print();

	// Turn counterclockwise by the given angle.
	counterclock_turn(PI);
	forward(2.345);
	print();

	printf("========================================\n");
}

int main() {

	// Test 1
	printf("Test 1\n");
	testControl(0.0, 0.0, 0.0);

	// Test 2
	printf("Test 2\n");
	testControl(1.0, 2.0, 0.0);

	// Test 3
	printf("Test 3\n");
	testControl(1.0, 2.0, 0.5 * PI);

	// Test 4
	printf("Test 4\n");
	testControl(1024.0, 2048.0, 4096.0);

	// Test 5
	printf("Test 5\n");
	testControl(123.456, 789.012, 1.5 * PI);

	return 0;
}
