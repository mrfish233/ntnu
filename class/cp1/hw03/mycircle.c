#include "mycircle.h"

// Constant
static const double PI = 3.141592653589793;

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

	return 2 * g_radius * PI;
}

double get_circle_area() {
	if (g_radius <= 0) {
		return -1;
	}

	return g_radius * g_radius * PI;
}

double get_tangent_area(double x) {
	if (g_radius <= 0) {
		return -1;
	}

	// Check x is valid
	if (x <= -g_radius || x >= g_radius || x == 0) {
		return -1;
	}

	// Calculate the tangent line's slope
	double y = sqrt(g_radius * g_radius - x * x);
	double m = -x / y;

	// Calculate the tangent line's x-intercept and y-intercept
	// Y - y = m(X - x), Y = 0; X = 0
	double x_intercept = x - y / m;
	double y_intercept = y - m * x;

	// Calculate the area bounded by the tangent line, x-axis and y-axis
	double area = 0.5 * x_intercept * y_intercept;

	return (area < 0) ? -area : area;
}

double get_inner_regular_polygon_area(int32_t n) {
	if (g_radius <= 0 || n < 3) {
		return -1;
	}

	return 0.5 * n * g_radius * g_radius * sin(2.0 * PI / n);
}

double get_outer_regular_polygon_area(int32_t n) {
	if (g_radius <= 0 || n < 3) {
		return -1;
	}

	// Using radius as apothem to calculate the area
	return n * g_radius * g_radius * tan(PI / n);
}
