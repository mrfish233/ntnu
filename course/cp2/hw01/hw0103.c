#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "mychain.h"

int main() {
    sPoly pResult = {
        .size = 0,
        .pPowers = NULL,
        .pCoefficients = NULL
    };

    // sPoly pFy = {
    //     .size = 4,
    //     .pPowers = (uint32_t[]){3, 2, 1, 0},
    //     .pCoefficients = (int32_t[]){2, -3, 4, -5}
    // };

    // sPoly pFy = {
    //     .size = 1,
    //     .pPowers = (uint32_t[]) {3},
    //     .pCoefficients = (int32_t[]) {2}
    // };

    // sPoly pFx = {
    //     .size = 3,
    //     .pPowers = (uint32_t[]) {3, 1, 0},
    //     .pCoefficients = (int32_t[]) {2, -3, 5}
    // };

    sPoly pFy = {
        .size = 1,
        .pPowers = (uint32_t[]) {2},
        .pCoefficients = (int32_t[]) {1}
    };

    sPoly pFx = {
        .size = 2,
        .pPowers = (uint32_t[]) {1, 0},
        .pCoefficients = (int32_t[]) {4, -3}
    };

    printf("pFy:\n");
    for (uint32_t i = 0; i < pFy.size; i++) {
        printf("%3d %3d\n", pFy.pCoefficients[i], pFy.pPowers[i]);
    }

    printf("pFx:\n");
    for (uint32_t i = 0; i < pFx.size; i++) {
        printf("%3d %3d\n", pFx.pCoefficients[i], pFx.pPowers[i]);
    }

    int32_t res = chain_rule(&pResult, &pFy, &pFx);

    if (res == 0) {
        printf("pResult:\n");
        for (uint32_t i = 0; i < pResult.size; i++) {
            printf("%3d %3d\n", pResult.pCoefficients[i], pResult.pPowers[i]);
        }
    } else {
        printf("Error\n");
    }

    // Free memory
    clear(&pResult);

    return 0;
}
