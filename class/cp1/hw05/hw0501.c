#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mystatistics.h"

int main() {
    int32_t n = 0;
    int32_t *data = NULL;

    scanf("%d", &n);
    data = calloc(n, sizeof(int32_t));

    for (int32_t i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    double mean = 0, var = 0, std = 0;

    if (statistics(data, n, &mean, &var, &std)) {
        printf("Mean: %lf\n", mean);
        printf("Variance: %lf\n", var);
        printf("Standard Deviation: %lf\n", std);
    }

    free(data);
    return 0;
}
