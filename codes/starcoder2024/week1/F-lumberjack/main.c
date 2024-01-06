#include <stdio.h>
#include <stdint.h>

void checkOrdered(int32_t beards[]) {
    int32_t increasing = 0, decreasing = 0;

    int32_t i = 0;
    for (i = 1; i < 10; i++) {
        decreasing += (beards[i-1] >= beards[i]);
        increasing += (beards[i-1] <= beards[i]);
    }

    if (increasing == 9 || decreasing == 9) {
        printf("Ordered\n");
    } else {
        printf("Unordered\n");
    }

    return;
}

int main() {
    int32_t cases = 0;

    scanf("%d", &cases);

    int32_t i = 0;
    for (i = 0; i < cases; i++) {
        int32_t beards[10] = {0}, j = 0;
        for (j = 0; j < 10; j++) {
            scanf("%d", &beards[j]);
        }

        if (i == 0) {
            printf("Lumberjacks:\n");
        }

        checkOrdered(beards);
    }

    return 0;
}
