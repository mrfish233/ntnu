#include <stdio.h>
#include <stdint.h>

void triangleWave(int32_t amp, int32_t freq) {
    int32_t i = 0, j = 0, k = 0;
    for (i = 0; i < freq; i++) {
        for (j = 1; j <= amp; j++) {
            for (k = 1; k <= j; k++) {
                printf("%d", j);
            }
            printf("\n");
        }

        for (j = amp - 1; j >= 1; j--) {
            for (k = 1; k <= j; k++) {
                printf("%d", j);
            }
            printf("\n");
        }

        if (i != freq - 1) {
            printf("\n");
        }
    }

    return;
}

int main() {
    int32_t cases = 0;

    scanf("%d", &cases);

    int32_t i = 0;
    for (i = 0; i < cases; i++) {
        int32_t amp = 0, freq = 0;

        if (i != 0) {
            printf("\n");
        }

        scanf("%d%d", &amp, &freq);
        triangleWave(amp, freq);
    }

    return 0;
}
