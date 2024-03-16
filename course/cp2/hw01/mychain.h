#pragma once

// #include <stdio.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Polynomial structure
 * size: number of terms
 * pPowers: array of exponents
 * pCoefficients: array of coefficients
 */
typedef struct _sPoly {
    uint32_t size;
    uint32_t *pPowers;
    int32_t  *pCoefficients;
} sPoly;

/**
 * Calculate the chain rule of two polynomials.
 * @param pResult: pointer to the result polynomial
 * @param pFy: pointer to the polynomial f(y)
 * @param pFx: pointer to the polynomial f(x)
 * @return 0: success; -1: error input
 */
int32_t chain_rule(sPoly *pResult, const sPoly *pFy, const sPoly *pFx);

/**
 * Check if the polynomial is valid.
 * @param pF: pointer to the polynomial
 * @return true: valid; false: invalid
 */
bool isValid(const sPoly *pF);

/**
 * Derivative of a polynomial.
 * @param pResult: pointer to the result polynomial
 * @param pF: pointer to the polynomial f(x)
 * @return 0: success; -1: error input
 */
int32_t derivative(sPoly *pResult, const sPoly *pF);

/**
 * Substitude polynomial F into polynomial G.
 * @param pResult: pointer to the result polynomial
 * @param pG: pointer to the polynomial
 * @param pF: pointer to the polynomial
 * @return 0: success; -1: error input
 */
int32_t substitute(sPoly *pResult, const sPoly *pG, const sPoly *pF);

/**

 * Add a polynomial to result polynomial.
 * @param pResult: pointer to the result polynomial
 * @param pF: pointer to the polynomial
 * @return 0: success; -1: error input
 */
int32_t add(sPoly *pResult, const sPoly *pF);

/**
 * Multiply a polynomial with another polynomial.
 * @param pResult: pointer to the result polynomial
 * @param pF: pointer to the polynomial
 * @return 0: success; -1: error input
 */
int32_t multiply(sPoly *pResult, const sPoly *pF);

/**
 * Add new term to a polynomial.
 * @param pF: pointer to the polynomial
 * @param power: exponent of the new term
 * @param coefficient: coefficient of the new term
 * @return 0: success; -1: error input
 */
int32_t addTerm(sPoly *pF, uint32_t power, int32_t coefficient);

/**
 * Clear a polynomial.
 * @param pF: pointer to the polynomial
 */
void clear(sPoly *pF);
