#include <stdio.h>
#include <stdint.h>

void checkQuadrangle(int32_t sides[4]) {
    int32_t i = 0, j = 0;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (sides[i] < sides[j]) {
                int32_t temp = sides[i];
                sides[i] = sides[j];
                sides[j] = temp;
            }
        }
    }

    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        if (sides[1] == sides[2]) {
            printf("square\n");
        } else {
            printf("rectangle\n");
        }
    } else if (sides[0] <= (sides[1] + sides[2] + sides[3])) {
        printf("quadrangle\n");
    } else {
        printf("banana\n");
    }

    return;
}

int main() {
    int32_t cases = 0;
    scanf("%d", &cases);

    while (cases--) {
        int32_t sides[4] = {0};

        int32_t i = 0;
        for (i = 0; i < 4; i++) {
            scanf("%d", &sides[i]);
        }

        checkQuadrangle(sides);
    }

    return 0;
}
