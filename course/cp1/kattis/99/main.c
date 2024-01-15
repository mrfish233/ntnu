#include <stdio.h>
#include <stdint.h>

int32_t nearest99(int32_t n) {
    if (n < 100) {
        return 99;
    }

    int32_t d1 = n % 100 + 1;
    int32_t d2 = 100 - d1;

    if (d1 < d2) {
        return n - d1;
    } else {
        return n + d2;
    }
}

int main() {
    int32_t a=0;

    if (scanf("%d", &a) == 1) {
        printf("%d\n", nearest99(a));
    }

    return 0;
}
