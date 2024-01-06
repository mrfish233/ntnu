#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "wargame.h"

int main() {
    int32_t height = 0, width = 0, **map = NULL;

    printf("Please input the height of the map: ");
    scanf("%d", &height);

    printf("Please input the width of the map: ");
    scanf("%d", &width);

    map = calloc(height, sizeof(int32_t *));
    for (int32_t i = 0; i < height; i++) {
        map[i] = calloc(width, sizeof(int32_t));
    }

    initMap(map, height, width);
    initPos(map, height, width);

    char input = 0;
    while (input != '0') {
        printMap(map, height, width);

        if (isPlayerDead()) {
            printf("You are dead.\n");
            break;
        } else if (isPlayerWin()) {
            printf("You win!\n");
            break;
        }

        while (getchar() != '\n');
        printf("Please input the action: ");
        scanf("%c", &input);

        playerAction(map, input);
        enemyAction(map);
        updateBullet(map, height, width);
    }

    for (int32_t i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}
