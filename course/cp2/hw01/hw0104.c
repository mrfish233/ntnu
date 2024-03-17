#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mymaze.h"

int main() {
    uint8_t row = 3;
    uint8_t col = 4;

    uint32_t costs[] = {
        1, 7, 2, 8,
        2, 5, 1, 2,
        9, 1, 1, 3
    };

    uint8_t rDoors[] = {
        0b01110101, 0b11000011, 0b11011100, 0b11100101,
        0b00101111, 0b00111100, 0b10011010, 0b01111001,
        0b00101100, 0b11110111, 0b01110111, 0b10001111
    };

    sRoom *pMaze = (sRoom *) calloc(row * col, sizeof(sRoom));

    for (uint8_t i = 0; i < row * col; i++) {
        pMaze[i].cost  = costs[i];
        pMaze[i].doors = rDoors[i];
    }

    sPath pMinPath = {
        .length = 0,
        .cost   = 0,
        .pPath  = NULL
    };

    int32_t find = find_min_path(pMaze, row, col, &pMinPath);

    if (find == 1) {
        printf("pMinPath: length=%d, cost=%d\n", pMinPath.length, pMinPath.cost);
        for (uint32_t i = 0; i < pMinPath.length; i++) {
            if (i != 0) {
                printf("->");
            }

            printf("(%d,%d)", pMinPath.pPath[i].row, pMinPath.pPath[i].col);
        }
        printf("\n");

        free(pMinPath.pPath);
    } else if (find == 0) {
        printf("No path\n");
    } else {
        printf("Invalid input\n");
    }

    free(pMaze);

    return 0;
}
