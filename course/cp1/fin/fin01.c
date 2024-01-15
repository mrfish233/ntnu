#include <stdio.h>
#include <stdint.h>
#include "frac.h"

int main() {
    int32_t x = 0, y = 0;
    int32_t a = 1, b = -2, c = 1, d = 2;

    if (frac_add(&x, &y, a, b, c, d) == 0) {
        printf("x/y: %d/%d\n", x, y);
    } else {
        printf("Error add\n");
    }

    if (frac_del(&x, &y, a, b, c, d) == 0) {
        printf("x/y: %d/%d\n", x, y);
    } else {
        printf("Error del\n");
    }

    if (frac_mul(&x, &y, a, b, c, d) == 0) {
        printf("x/y: %d/%d\n", x, y);
    } else {
        printf("Error mul\n");
    }

    if (frac_div(&x, &y, a, b, c, d) == 0) {
        printf("x/y: %d/%d\n", x, y);
    } else {
        printf("Error div\n");
    }

    return 0;
}
