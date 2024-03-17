#include "mymaze.h"

int32_t find_min_path(const sRoom *pMaze, const uint8_t row, const uint8_t col, sPath *pMinPath) {
    if (pMaze == NULL || pMinPath == NULL || row == 0 || col == 0) {
        return -1;
    }

    if (pMinPath->length == 0) {
        pMinPath->pPath = (sPoint *) calloc(1, sizeof(sPoint));

        pMinPath->pPath[0].row = 0;
        pMinPath->pPath[0].col = 0;

        pMinPath->length = 1;
        pMinPath->cost = pMaze[0].cost;
    }

    sPoint *path = pMinPath->pPath;

    sPath availablePath[4] = {
        {0, -1, NULL},
        {0, -1, NULL},
        {0, -1, NULL},
        {0, -1, NULL}
    };

    int32_t dx[] = {-1, 0, 1, 0};
    int32_t dy[] = {0, 1, 0, -1};

    int32_t x = path[pMinPath->length - 1].row;
    int32_t y = path[pMinPath->length - 1].col;

    int32_t prev_x = -1;
    int32_t prev_y = -1;

    // Check if the current position is the destination
    if (x == row - 1 && y == col - 1) {
        return 1;
    }

    if (pMinPath->length > 1) {
        prev_x = path[pMinPath->length - 2].row;
        prev_y = path[pMinPath->length - 2].col;
    }

    for (uint8_t i = 0; i < 4; i++) {
        int32_t new_x = x + dx[i];
        int32_t new_y = y + dy[i];

        if (new_x < 0 || new_x >= row || new_y < 0 || new_y >= col) {
            continue;
        }

        if (new_x == prev_x && new_y == prev_y) {
            continue;
        }

        int32_t currPos = x * col + y;
        int32_t nextPos = new_x * col + new_y;

        int32_t currDoor = doorNum(pMaze[currPos].doors, i);
        int32_t nextDoor = doorNum(pMaze[nextPos].doors, (i + 2) % 4);

        // Check if the next position is reachable

        if (currDoor != nextDoor) {
            continue;
        }

        // Check if the next position is already in the path

        for (uint32_t j = 0; j < pMinPath->length; j++) {
            int32_t temp_x = pMinPath->pPath[j].row;
            int32_t temp_y = pMinPath->pPath[j].col;

            if (temp_x == prev_x && temp_y == prev_y) {
                continue;
            }

            if (temp_x == new_x && temp_y == new_y) {
                return 0;
            }
        }

        // printf("new_x: %d, new_y: %d, length: %d, cost: %d\n", new_x, new_y, pMinPath->length, pMinPath->cost);

        // Recursively find the path

        sPath newPath = {
            .length = pMinPath->length + 1,
            .cost   = pMinPath->cost + pMaze[nextPos].cost,
            .pPath  = (sPoint *) calloc(newPath.length, sizeof(sPoint))
        };

        for (uint32_t j = 0; j < pMinPath->length; j++) {
            newPath.pPath[j] = pMinPath->pPath[j];
        }

        newPath.pPath[newPath.length - 1].row = new_x;
        newPath.pPath[newPath.length - 1].col = new_y;

        int32_t find = find_min_path(pMaze, row, col, &newPath);

        // Add the new path to the available path

        if (find == 1) {
            availablePath[i] = newPath;
        } else {
            free(newPath.pPath);
        }
    }

    // Find the minimum cost path

    return findMinDir(availablePath, pMinPath);
}

int32_t doorNum(uint8_t door, uint8_t direction) {
    return (door >> ((3 - direction) * 2)) & 0x03;
}

int32_t findMinDir(sPath *pDir, sPath *pMinPath) {
    if (pDir == NULL || pMinPath == NULL) {
        return 0;
    }

    uint32_t index = 0, found = 0;

    for (uint32_t i = 0; i < 4; i++) {
        if (pDir[i].length == 0) {
            continue;
        }

        if (found == 0) {
            index = i;
            found = 1;
        } else if (pDir[i].cost < pDir[index].cost) {
            free(pDir[index].pPath);
            index = i;
        } else {
            free(pDir[i].pPath);
        }
    }

    if (found == 0) {
        return 0;
    }

    free(pMinPath->pPath);

    pMinPath->length = pDir[index].length;
    pMinPath->cost   = pDir[index].cost;
    pMinPath->pPath  = pDir[index].pPath;

    return 1;
}
