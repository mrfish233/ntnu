#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// I promise that A is an nxn matrix (2d array).
// However , you need to check if the inputs are valid.
// You should malloc for x.
// Return -1 if the inputs are invalid.
// Return 0 if there is no solution.
// Return 1 if there is only one solution.
// Return 2 if there are more than one solutions.

/**
 * Given n*n matrix A and vector y, solve for vector x.
 * @param n the size of matrix.
 * @param pA the matrix A
 * @param py the vector y
 * @param px the pointer of vector x
 * @return -1 if invalid input, 0 if no solution, 1 if 1 solution,
 * 2 if more than 1 solution.
 */
int32_t gaussian_elimination(int32_t n, int32_t *pA, int32_t *py, int32_t **px);
