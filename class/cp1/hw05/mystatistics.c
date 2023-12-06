#include "mystatistics.h"

int32_t statistics(int32_t *pData, int32_t size, double *pMean, double *pVariance, double *pStd) {
    if (pData == NULL || pMean == NULL || pVariance == NULL || pStd == NULL) {
        return 0;
    }

    if (size < 0) {
        return 0;
    }

    double total = 0.0;

    for (int32_t i = 0; i < size; i++) {
        total += pData[i];
    }

    *pMean = total / size;

    double totalMeanDiff = 0;

    for (int32_t i = 0; i < size; i++) {
        totalMeanDiff += (pData[i] - *pMean) * (pData[i] - *pMean);
    }

    *pVariance = totalMeanDiff / size;

    *pStd = sqrt(*pVariance);

    return 1;
}