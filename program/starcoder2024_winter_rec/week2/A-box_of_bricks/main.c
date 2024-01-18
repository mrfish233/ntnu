#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t minimumMoves(int32_t stacks[], int32_t size) {
    int32_t total = 0, i = 0;

    for (i = 0; i < size; i++) {
        total += stacks[i];
    }

    int32_t height = total / size, moves = 0;

    for (i = 0; i < size; i++) {
        if (stacks[i] > height) {
            moves += stacks[i] - height;
        }
    }

    return moves;
}

int main() {
    int32_t set = 0, size = 0, stacks[50] = {0};

    while (1) {
        scanf("%d", &size);

        if (size == 0) {
            break;
        }

        int32_t i = 0;
        for(i = 0; i < size; i++) {
            scanf("%d", &stacks[i]);
        }

        printf("Set #%d\n", ++set);
        printf("The minimum number of moves is %d.\n\n", minimumMoves(stacks, size));
    }

    return 0;
}
