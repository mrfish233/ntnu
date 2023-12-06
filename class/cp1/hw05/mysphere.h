#pragma once

#include <stdint.h>
#include <stdlib.h>
// #include <math.h>

/**
 * Calculate the cap area, a portion of sphere cut off by plane.
 * @param r The radius of sphere.
 * @param a,b,c,d The plane `ax+by+cz=d`.
 * @param pArea The pointer of cap area to calculate.
 * @return -1 if invalid input, 0 if invalid plane, 1 otherwise.
 */
int32_t get_cap_area(double r, double a, double b, double c, double d, double *pArea);
