#include <stdio.h>
#include <stdint.h>

int32_t oddSum(int32_t x, int32_t y) {
    if (x % 2 == 0) {
        x += 1;
    }

    if (y % 2 == 0) {
        y -= 1;
    }

    int32_t result = 0, i = 0;
    for (i = x; i <= y; i += 2) {
        result += i;
    }

    return result;
}

int main() {
    int32_t cases = 0;

    scanf("%d", &cases);

    int32_t i = 0;
    for (i = 1; i <= cases; i++) {
        int32_t x = 0, y = 0;
        scanf("%d%d", &x, &y);

        printf("Case %d: %d\n", i, oddSum(x, y));
    }

    return 0;
}
