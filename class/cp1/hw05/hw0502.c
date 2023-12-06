#include <stdio.h>
#include <stdint.h>
#include "myge.h"

#define SIZE 4

int main() {
    // int32_t matA[3][3] = {
    //     {0, 1, 1},
    //     {1, 2, 4},
    //     {2, 3, 8}
    // };

    // int32_t y[3] = {6, 17, 34};

    int32_t matA[SIZE][SIZE] = {
        {1,1,1,1},
        {0,3,4,2},
        {-1,-1,0,3},
        {3,2,-3,1},
    };
    int32_t y[SIZE] = {10,26,9,2};

    int32_t *x = NULL;

    int check = gaussian_elimination(SIZE, &matA[0][0], &y[0], &x);
    if (check == 1) {
        for (int32_t i = 0; i < SIZE; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
    } else {
        printf("Return: %d\n", check);
    }

    if (x != NULL) free(x);

    return 0;
}
