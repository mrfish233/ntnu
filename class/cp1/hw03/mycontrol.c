#include "mycontrol.h"

// Constant
// static const long double M_PI = 3.14159265358979323846;

// Initialization flag
static int32_t g_initialized = 0;

// Position and angle of the character
static double g_x = 0.0;
static double g_y = 0.0;
static double g_a = 0.0;

void initialize(double x, double y, double a) {
	// Set the initialization flag
	g_initialized = 1;

	// Set the position and angle
	g_x = x;
	g_y = y;
	g_a = a;

	// Convert the angle range
	convert_angle(g_a);
}

void convert_angle() {
	// Convert the angle range
	if (g_a < 0.0) {
		while (g_a < 0.0) {
			g_a += 2.0 * M_PI;
		}
	} else if (g_a >= 2.0 * M_PI) {
		while (g_a >= 2.0 * M_PI) {
			g_a -= 2.0 * M_PI;
		}
	}
}

int32_t forward(double length) {
	// Check if the character is initialized
	if (!g_initialized) {
		return -1;
	}

	// Move the character
	g_x += length * cos(g_a);
	g_y += length * sin(g_a);

	return 0;
}

int32_t clock_turn(double angle) {
	// Check if the character is initialized
	if (!g_initialized) {
		return -1;
	}

	// Turn the character
	g_a -= angle;

	// Convert the angle range
	convert_angle(g_a);

	return 0;
}

int32_t counterclock_turn(double angle) {
	// Turn the character clockwise by -angle
	clock_turn(-angle);
}

int32_t print(void) {
	// Check if the character is initialized
	if (!g_initialized) {
		return -1;
	}

	// Print the position and angle
	printf("position: (%.2lf, %.2lf), angle: %.2lf\n", g_x, g_y, g_a / M_PI);

	return 0;
}
