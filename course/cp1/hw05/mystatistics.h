#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/**
 * Calculate mean, variance and standard deviation based on
 * data given.
 * @param pData the given data
 * @param size the size of data
 * @param pMean the mean value of data
 * @param pVariance the variance of the data
 * @param pStd the standard deviation of the data
 * @return something here.
 */
int32_t statistics(int32_t *pData, int32_t size, double *pMean, double *pVariance, double *pStd);
