#include <stdio.h>
#include <stdint.h>

int32_t lcf(int32_t a, int32_t b) {
    int32_t i=0;
    int32_t max = a > b ? a : b;

    for (i=max; i<=a*b; i++) {
        if (i % a == 0 && i % b == 0) {
            return i;
        }
    }

    return 0;
}

int main() {
    int32_t k=0;
    int32_t y=0, c1=0, c2=0;
    int32_t res[105] = {0};
    int32_t min = 0;

    if (scanf("%d", &k) != 0){}

    for (int32_t i=0; i<k; i++) {
        if (scanf("%d %d %d", &y, &c1, &c2) != 0){}
        res[i] = y + lcf(c1, c2);

        min = i == 0 ? res[i] : (res[i] < min ? res[i] : min);
    }

    // for (int32_t i=0; i<k; i++) {
    //     printf("%d ", res[i]);
    // }
    // printf("\n");

    printf("%d\n", min);

    return 0;
}
