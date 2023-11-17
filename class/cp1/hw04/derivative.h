#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Gives new degree of a equation.
 * @param degree The new degree
 * @return The degree, -1 if invalid.
 */
int64_t newDegree(int64_t degree);

/**
 * Generates new equation.
 * @param degree The degree of equation
 * @return The new function, NULL if invalid
 */
int64_t *newEquation(int64_t degree);

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
 * @return The equation if success initialized, NULL if failed.
 */
int64_t *initEquation(char *str, int64_t degree);

/**
 * Differentiate the equation.
 * @param equation The coefficient array of equation
 * @param degree The degree of equation
 * @return The differentiated equation, NULL if failed.
 */
int64_t *differentiate(int64_t *equation, int64_t degree);

/**
 * Sum 2 equations.
 * @param eqn1 The coefficient array of equation 1
 * @param deg1 The degree of equation 1
 * @param eqn2 The coefficient array of equation 2
 * @param deg2 The degree of equation 2
 * @return The sum of 2 equations, NULL if failed.
 */
int64_t *sumEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2);

/**
 * Subtract 2 equations.
 * @param eqn1 The coefficient array of equation 1 to be subtracted
 * @param deg1 The degree of equation 1
 * @param eqn2 The coefficient array of equation 2 to subtract
 * @param deg2 The degree of equation 2
 * @return The subtract of 2 equations, NULL if failed.
 */
int64_t *subtractEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2);

/**
 * Product 2 equations.
 * @param eqn1 The coefficient array of equation 1
 * @param deg1 The degree of equation 1
 * @param eqn2 The coefficient array of equation 2
 * @param deg2 The degree of equation 2
 * @return The product of 2 equations, NULL if failed.
 */
int64_t *productEquation(int64_t *eqn1, int64_t deg1, int64_t *eqn2, int64_t deg2);

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
void clearEquation(int64_t *equation);
