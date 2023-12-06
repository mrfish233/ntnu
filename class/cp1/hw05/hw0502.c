#include <stdio.h>
#include <stdint.h>
#include "myge.h"

int main() {
    int32_t matA[3][3] = {
        {1, 1, 1},
        {1, 2, 4},
        {1, 3, 9}
    };

    int32_t y[3] = {6, 17, 37};
    int32_t *x = NULL;

    gaussian_elimination(3, &matA[0][0], &y[0], &x);

    free(x);

    return 0;
}
