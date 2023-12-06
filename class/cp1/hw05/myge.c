#include "myge.h"

int32_t gaussian_elimination(int32_t n, int32_t *pA, int32_t *py, int32_t **px) {
    *px = calloc(n, sizeof(int32_t));

    double **matA = calloc(n, sizeof(double *));

    for (int32_t i = 0; i < n; i++) {
        matA[i] = calloc(n, sizeof(double));

        for (int32_t j = 0; j < n; j++) {
            matA[i][j] = (double) *(pA + (n*i + j));
        }
    }

    double *y = calloc(n, sizeof(double));
    double *x = calloc(n, sizeof(double));

    for (int32_t i = 0; i < n; i++) {
        y[i] = (double) *(py + i);
    }

    for (int32_t i = 0; i < n; i++) {
        
    }


    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < n; j++) {
            printf("%f ", matA[i][j]);
        }
        printf("\n");
    }

    printf("y: ");
    for (int32_t i = 0; i < n; i++) {
        printf("%f ", y[i]);
    }
    printf("\n");



    for (int32_t i = 0; i < n; i++) {
        free(matA[i]);
    }
    free(matA);
    free(y);
    free(x);

    return 1;
}
