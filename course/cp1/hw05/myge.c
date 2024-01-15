#include "myge.h"

static void swapRow(double **mat, int32_t n, int32_t row1, int32_t row2) {
    if (row1 == row2 || mat == NULL || n < 0) {
        return;
    }

    for (int32_t i = 0; i < n; i++) {
        double temp  = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

int32_t gaussian_elimination(int32_t n, int32_t *pA, int32_t *py, int32_t **px) {
    if (n <= 0 || pA == NULL || py == NULL || *px != NULL) {
        return -1;
    }

    // Augmented matrix
    double **matrixAy = calloc(n, sizeof(double *));

    for (int32_t i = 0; i < n; i++) {
        matrixAy[i] = calloc(n + 1, sizeof(double));

        for (int32_t j = 0; j < n; j++) {
            matrixAy[i][j] = (double) *(pA + (n*i + j));
        }

        matrixAy[i][n] = (double) *(py + i);
    }

    // Reduce to row echelon form

    for (int32_t i = 0; i < n - 1; i++) {
        int32_t largest = i;
        for (int32_t j = i + 1; j < n; j++) {
            if (fabs(matrixAy[largest][i]) < fabs(matrixAy[j][i])) {
                largest = j;
            }
        }
        swapRow(matrixAy, n + 1, i, largest);

        for (int32_t j = i + 1; j < n; j++) {
            double factor = -(matrixAy[j][i] / matrixAy[i][i]);

            for (int32_t k = i; k < n + 1; k++) {
                matrixAy[j][k] += factor * matrixAy[i][k];
            }
        }
    }

    // Check if 0 or many answers

    int32_t check = 0;
    for (int32_t i = 0; i < n; i++) {
        if (matrixAy[n-1][i] != 0) {
            break;
        }

        check++;
    }

    if (check == n) {
        return (matrixAy[n-1][n] != 0) ? 0 : 2;
    }

    // Continue to reduce to find answers

    for (int32_t i = n - 1; i > 0; i--) {
        for(int32_t j = i - 1; j >= 0; j--) {
            double factor = -(matrixAy[j][i] / matrixAy[i][i]);

            for (int32_t k = n; k >= i; k--) {
                matrixAy[j][k] += factor * matrixAy[i][k];
            }
        }
    }

    // Save result to argument pointer

    *px = calloc(n, sizeof(int32_t));

    for (int32_t i = 0; i < n; i++) {
        (*px)[i] = (int32_t) roundf(matrixAy[i][n] / matrixAy[i][i]);
    }

    // Free allocated memory

    for (int32_t i = 0; i < n; i++) {
        free(matrixAy[i]);
    }
    free(matrixAy);

    return 1;
}
