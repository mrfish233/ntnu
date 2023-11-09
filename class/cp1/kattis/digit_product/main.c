#include <stdio.h>
#include <stdint.h>

int32_t digitProduct(int32_t n) {
    if (n < 10) {
        return n;
    }

    int32_t product = 1;
    int32_t digit = 0;

    while (n > 0) {
        digit = n % 10;
        n /= 10;

        if (digit != 0) {
            product *= digit;
        }
    }

    return digitProduct(product);
}

int main() {
    int32_t a=0;

    if (scanf("%d", &a) == 1) {
        printf("%d\n", digitProduct(a));
    }

    return 0;
}
