#pragma once

#include <stdint.h>
#include <math.h>

/**
 * Setup the radius r of the circle.
 * This function must be called before all other functions.
 * @param rad The radius of the circle.
 * @return 0 on success, -1 if r <= 0.
 */
int32_t set_radius(double rad);

/**
 * Return the circumference of the circle.
 * @return The circumference of the circle, -1 if the radius is not set.
 */
double get_circle_circumference();

/**
 * Return the area of the circle.
 * @return The circumference of the circle, -1 if the radius is not set.
 */
double get_circle_area();

/**
 * Given x, (x,y) is a point on the upper circle.
 * Calculate the area bounded by the tangent line at (x,y), x-axis and y-axis.
 * @param x The x coordinate of the point.
 * @return The bounded area, -1 if the radius is not set or x is not a valid value.
 */
double get_tangent_area(double x);

/**
 * Calculate the inner regular polygon area.
 * @param n The number of sides of the polygon.
 * @return The inner regular polygon area, -1 if the radius is not set or n < 3.
 */
double get_inner_regular_polygon_area(int32_t n);

/**
 * Calculate the outer regular polygon area.
 * @param n The number of sides of the polygon.
 * @return The outer regular polygon area, -1 if the radius is not set or n < 3.
 */
double get_outer_regular_polygon_area(int32_t n);
