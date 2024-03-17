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
        pMinPath->cost   = pMaze[0].cost;
    }

    sPath availablePath[4] = {
        {0, 0, NULL}, {0, 0, NULL}, {0, 0, NULL}, {0, 0, NULL}
    };

    // Check if the current position is the destination

    sPoint currPos = pMinPath->pPath[pMinPath->length - 1];

    if (currPos.row == (uint32_t) row - 1 && currPos.col == (uint32_t) col - 1) {
        return 1;
    }

    // printf("currPos: (%d,%d)\n", currPos.row, currPos.col);

    for (int32_t i = 0; i < 4; i++) {
        int32_t valid = isValidPos(pMaze, row, col, pMinPath, i);

        if (valid == 0) {
            continue;
        } else if (valid == -1) {
            return 0;
        }

        sPoint nextPos = currPos;

        if (i == NORTH) {
            nextPos.row--;
        } else if (i == EAST) {
            nextPos.col++;
        } else if (i == SOUTH) {
            nextPos.row++;
        } else if (i == WEST) {
            nextPos.col--;
        }

        int32_t next = nextPos.row * col + nextPos.col;

        // Recursively find the path

        sPath newPath = {
            .length = pMinPath->length + 1,
            .cost   = pMinPath->cost + pMaze[next].cost,
            .pPath  = (sPoint *) calloc(newPath.length, sizeof(sPoint))
        };

        for (uint32_t j = 0; j < pMinPath->length; j++) {
            newPath.pPath[j] = pMinPath->pPath[j];
        }

        newPath.pPath[newPath.length - 1] = nextPos;

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

int32_t isValidPos(const sRoom *pMaze, const uint8_t row, const uint8_t col, const sPath *pMinPath, Direction dir) {
    sPoint currPos = pMinPath->pPath[pMinPath->length - 1];
    sPoint prevPos = {row, col};
    sPoint nextPos = currPos;

    if (pMinPath->length > 1) {
        prevPos = pMinPath->pPath[pMinPath->length - 2];
    }

    // Check invalid position

    if ((dir == NORTH && currPos.row == 0) ||
        (dir == EAST  && currPos.col == (uint32_t) col - 1) ||
        (dir == SOUTH && currPos.row == (uint32_t) row - 1) ||
        (dir == WEST  && currPos.col == 0)) {
        return 0;
    }

    if (dir == NORTH) {
        nextPos.row--;
    } else if (dir == EAST) {
        nextPos.col++;
    } else if (dir == SOUTH) {
        nextPos.row++;
    } else if (dir == WEST) {
        nextPos.col--;
    }

    // Check if walking back

    if (nextPos.row == prevPos.row && nextPos.col == prevPos.col) {
        return 0;
    }

    // Check if the next position is reachable

    int32_t currDoor = doorNum(pMaze[currPos.row * col + currPos.col].doors, dir);
    int32_t nextDoor = doorNum(pMaze[nextPos.row * col + nextPos.col].doors, (dir + 2) % 4);

    if (currDoor != nextDoor) {
        return 0;
    }

    // Check if the next position is already in the path

    for (int32_t i = 0; i < (int32_t) pMinPath->length - 2; i++) {
        sPoint tempPos = pMinPath->pPath[i];

        if (tempPos.row == nextPos.row && tempPos.col == nextPos.col) {
            return -1;
        }
    }

    return 1;
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
