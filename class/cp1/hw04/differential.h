#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Initialize the degree in range of unsigned 32-bit integer.
 * @param str The function name
 * @return Input degree, -1 if invalid input.
 */
int64_t initDegree(char *str);

/**
 * Initialize the equation by given degree, highest degree has lowest index.
 * @param str The function name
 * @param degree The degree of equation
 * @return equation if success initialized, NULL if failed.
 */
int64_t *initEquation(char *str, int64_t degree);

/**
 * Print the equation form.
 * @param str The function name
 * @param equation The coefficient array of equation
 * @param degree The degree of equation
 */
void printEquation(char *str, int64_t *equation, int64_t degree);

/**
 * Free the equation.
 * @param equation The equation to be freed.
 */
void freeEquation(int64_t *equation);
