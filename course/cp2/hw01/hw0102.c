#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "mycal.h"

int main() {
    char pExpr[] = "01_2 - ABCDE_16 - 0010_2 * 123_8 - 40_7 + 100_14 + 33_4";
    // char pExpr[] = "01_2 - 01_2";
    int base = 10;
    char *pResult = NULL;

    int32_t result = calculate(pExpr, base, &pResult);

    if (result == 0) {
        printf("Result: %s\n", pResult);
    }

    free(pResult);

    return 0;
}
