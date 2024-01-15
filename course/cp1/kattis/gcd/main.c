#include <stdio.h>
#include <stdint.h>

int32_t gcd(int32_t a, int32_t b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int32_t a=0,b=0;

    if (scanf("%d %d", &a, &b) == 2) {
        printf("%d\n", gcd(a, b));
    }

    return 0;
}
