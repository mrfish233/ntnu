#include <stdio.h>
#include <stdint.h>
#include "mycircle.h"

void testTangentArea(double r) {
	printf("tangent area at x: %20lf = %20lf\n", r, get_tangent_area(r));
}

void testPolygonArea(int32_t n) {
	printf("inner regular polygon area = %20lf\n", get_inner_regular_polygon_area(n));
	printf("outer regular polygon area = %20lf\n", get_outer_regular_polygon_area(n));
}

void testCircle(double r) {
	printf("radius        = %lf, success = %d\n", r, set_radius(r));
	printf("circumference = %lf\n", get_circle_circumference());
	printf("area          = %lf\n", get_circle_area());

	printf("------------------------------------------------------------\n");

	testTangentArea(r);
	testTangentArea(r + 1.0);
	testTangentArea(r - 1.0);
	testTangentArea(r / 2.0);
	testTangentArea(-r / 2.0);
	testTangentArea(0.0);

	printf("------------------------------------------------------------\n");

	testPolygonArea(3);
	testPolygonArea(10);
	testPolygonArea(100);
	testPolygonArea(INT32_MAX);

	printf("============================================================\n");
}

int main() {
	testCircle(10.0);
	testCircle(0);
	testCircle(-10.0);
	testCircle(123456789);
	return 0;
}
