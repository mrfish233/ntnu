#include "mycircle.h"

// Constant
// static const long double M_PI = 3.14159265358979323846;

// Global variable
static double g_radius = -1;

int32_t set_radius(double rad) {
	if (rad <= 0) {
		return -1;
	}

	g_radius = rad;
	return 0;
}

double get_circle_circumference() {
	if (g_radius <= 0) {
		return -1;
	}

	return 2 * g_radius * M_PI;
}

double get_circle_area() {
	if (g_radius <= 0) {
		return -1;
	}

	return g_radius * g_radius * M_PI;
}

double get_tangent_area(double x) {
	if (g_radius <= 0) {
		return -1;
	}

	// Check x is valid
	if (x <= -g_radius || x >= g_radius || x == 0) {
		return -1;
	}

	double y = sqrt(g_radius * g_radius - x * x);
	double area = 0.5 * x * y;

	if (area < 0) {
		area = -area;
	}

	return area;
}

double get_inner_regular_polygon_area(int32_t n) {
	if (g_radius <= 0 || n < 3) {
		return -1;
	}

	return 0.5 * n * g_radius * g_radius * sin(2.0 * M_PI / n);
}

double get_outer_regular_polygon_area(int32_t n) {
	if (g_radius <= 0 || n < 3) {
		return -1;
	}

	return 0.5 * n * g_radius * g_radius * tan(M_PI / n);
}
