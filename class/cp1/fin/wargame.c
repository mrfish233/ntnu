#include "wargame.h"

#define EMPTY   0
#define BORDER -1

#define PLAYER_MUZZLE  9
#define PLAYER_TANK   10

#define ENEMY_MUZZLE  19
#define ENEMY_TANK    20

#define BULLET        50
#define OBSTACLE      99

#define TANK 0
#define MUZZ 1
#define X 0
#define Y 1

#define POS 0
#define DIR 1

int32_t initRand = 0;

int32_t player[2][2] = {0};
int32_t enemy[3][2][2] = {0};

int32_t enemyCount = 3;
int32_t playerDead = 0;

int32_t playerBulletDur = -1;
int32_t playerBullet[2][2] = {0};

int32_t enemyBulletDur[3] = {-1,-1,-1};
int32_t enemyBullet[3][2][2] = {0};

int32_t maxBulletDur = 10;

void printMap(int32_t **map, int32_t height, int32_t width) {
    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            int32_t tmp = map[i][j];

            if (tmp == BORDER) {
                printf((i == 0 || i == height-1) ? "-" : "|");
            } else if (tmp == PLAYER_TANK) {
                printf("P");
            } else if (tmp == ENEMY_TANK) {
                printf("C");
            } else if (tmp == PLAYER_MUZZLE || tmp == ENEMY_MUZZLE) {
                printf("I");
            } else if (tmp == BULLET) {
                printf("o");
            } else if (tmp == OBSTACLE) {
                printf("R");
            } else {
                printf(" ");
            }

            // printf("%2d", tmp);
        }
        printf("\n");
    }
}

void initMap(int32_t **map, int32_t height, int32_t width) {
    for (int32_t i = 0; i < width; i++) {
        map[0][i] = BORDER;
        map[height-1][i] = BORDER;
    }

    for (int32_t i = 0; i < height; i++) {
        map[i][0] = BORDER;
        map[i][width-1] = BORDER;
    }
}

void initRandom() {
    if (initRand != 0) {
        return;
    }

    srand(time(0));
    initRand = 1;
}

void initPos(int32_t **map, int32_t height, int32_t width) {
    initRandom();

    // Player

    int32_t validPos = 0, ranX = 0, ranY = 0;
    while (!validPos) {
        validPos = 1;

        ranX = rand() % height;
        ranY = rand() % width;

        if (map[ranX][ranY] != EMPTY || ranX == 1) {
            validPos = 0;
        }
    }

    map[ranX][ranY]   = PLAYER_TANK;
    map[ranX-1][ranY] = PLAYER_MUZZLE;

    player[TANK][X] = ranX;
    player[TANK][Y] = ranY;
    player[MUZZ][X] = ranX-1;
    player[MUZZ][Y] = ranY;

    // Enemies

    for (int32_t i = 0; i < 3; i++) {
        validPos = 0, ranX = 0, ranY = 0;
        while (!validPos) {
            validPos = 1;

            ranX = rand() % height;
            ranY = rand() % width;

            if (map[ranX][ranY] != EMPTY || ranX == 1) {
                validPos = 0;
                continue;
            }
        }

        map[ranX][ranY]   = ENEMY_TANK;
        map[ranX-1][ranY] = ENEMY_MUZZLE;

        enemy[i][TANK][X] = ranX;
        enemy[i][TANK][Y] = ranY;
        enemy[i][MUZZ][X] = ranX-1;
        enemy[i][MUZZ][Y] = ranY;
    }

    // Obstacles

    int32_t totalObstacles = (height * width) / 40;

    for (int32_t i = 0; i < totalObstacles; i++) {
        validPos = 0, ranX = 0, ranY = 0;
        while (!validPos) {
            validPos = 1;

            ranX = rand() % height;
            ranY = rand() % width;

            if (map[ranX][ranY] != EMPTY) {
                validPos = 0;
                continue;
            }
        }

        map[ranX][ranY] = OBSTACLE;
    }
}

void playerAction(int32_t **map, char input) {
    if ((input == 'W' || input == 'w') ||
        (input == 'S' || input == 's') ||
        (input == 'A' || input == 'a') ||
        (input == 'D' || input == 'd') ||
        (input == 'R' || input == 'r')) {
        playerMove(map, input);
    } else if (input == 'Q' || input == 'q') {
        playerShoot();
    }
}

void enemyAction(int32_t **map) {
    enemyMove(map);
    enemyShoot();
}

void playerMove(int32_t **map, char input) {
    int32_t oldTankX = 0, oldTankY = 0, oldMuzzX = 0, oldMuzzY = 0;
    int32_t newTankX = 0, newTankY = 0, newMuzzX = 0, newMuzzY = 0;

    oldTankX = player[TANK][X];
    oldTankY = player[TANK][Y];
    oldMuzzX = player[MUZZ][X];
    oldMuzzY = player[MUZZ][Y];

    if (input == 'R' || input == 'r') {
        newTankX = player[TANK][X];
        newTankY = player[TANK][Y];
        newMuzzX = player[MUZZ][X];
        newMuzzY = player[MUZZ][Y];
    } else if (input == 'W' || input == 'w') {
        newTankX = player[TANK][X] - 1;
        newTankY = player[TANK][Y];
        newMuzzX = player[MUZZ][X] - 1;
        newMuzzY = player[MUZZ][Y];
    } else if (input == 'S' || input == 's') {
        newTankX = player[TANK][X] + 1;
        newTankY = player[TANK][Y];
        newMuzzX = player[MUZZ][X] + 1;
        newMuzzY = player[MUZZ][Y];
    } else if (input == 'A' || input == 'a') {
        newTankX = player[TANK][X];
        newTankY = player[TANK][Y] - 1;
        newMuzzX = player[MUZZ][X];
        newMuzzY = player[MUZZ][Y] - 1;
    } else if (input == 'D' || input == 'd') {
        newTankX = player[TANK][X];
        newTankY = player[TANK][Y] + 1;
        newMuzzX = player[MUZZ][X];
        newMuzzY = player[MUZZ][Y] + 1;
    }

    updateMuzzle(newTankX, newTankY, &newMuzzX, &newMuzzY);

    map[oldTankX][oldTankY] = EMPTY;
    map[oldMuzzX][oldMuzzY] = EMPTY;

    if (map[newTankX][newTankY] != EMPTY || map[newMuzzX][newMuzzY] != EMPTY) {
        map[oldTankX][oldTankY] = PLAYER_TANK;
        map[oldMuzzX][oldMuzzY] = PLAYER_MUZZLE;
    } else {
        map[newTankX][newTankY] = PLAYER_TANK;
        map[newMuzzX][newMuzzY] = PLAYER_MUZZLE;

        player[TANK][X] = newTankX;
        player[TANK][Y] = newTankY;
        player[MUZZ][X] = newMuzzX;
        player[MUZZ][Y] = newMuzzY;
    }
}

void enemyMove(int32_t **map) {
    for (int32_t i = 0; i < 3; i++) {
        int32_t tankX = 0, tankY = 0;
        int32_t oldMuzzX = 0, oldMuzzY = 0, newMuzzX = 0, newMuzzY = 0;

        tankX = enemy[i][TANK][X];
        tankY = enemy[i][TANK][Y];

        oldMuzzX = enemy[i][MUZZ][X];
        oldMuzzY = enemy[i][MUZZ][Y];
        newMuzzX = enemy[i][MUZZ][X];
        newMuzzY = enemy[i][MUZZ][Y];

        updateMuzzle(tankX, tankY, &newMuzzX, &newMuzzY);

        map[oldMuzzX][oldMuzzY] = EMPTY;

        if (map[newMuzzX][newMuzzY] != EMPTY) {
            map[oldMuzzX][oldMuzzY] = ENEMY_MUZZLE;
        } else {
            map[newMuzzX][newMuzzY] = ENEMY_MUZZLE;

            enemy[i][MUZZ][X] = newMuzzX;
            enemy[i][MUZZ][Y] = newMuzzY;
        }
    }
}

void updateMuzzle(int32_t tankX, int32_t tankY, int32_t *muzzX, int32_t *muzzY) {
    if (*muzzX < tankX && *muzzY <= tankY) {
        *muzzY += 1;
    } else if (*muzzX > tankX && *muzzY >= tankY) {
        *muzzY -= 1;
    } else if (*muzzX <= tankX && *muzzY > tankY) {
        *muzzX += 1;
    } else if (*muzzX >= tankX && *muzzY < tankY) {
        *muzzX -= 1;
    }
}

void playerShoot() {
    if (playerBulletDur != -1) {
        return;
    }

    playerBulletDur = maxBulletDur;

    playerBullet[POS][X] = player[MUZZ][X];
    playerBullet[POS][Y] = player[MUZZ][Y];

    playerBullet[DIR][X] = player[MUZZ][X] - player[TANK][X];
    playerBullet[DIR][Y] = player[MUZZ][Y] - player[TANK][Y];
}

void enemyShoot() {
    for (int32_t i = 0; i < 3; i++) {
        if ((enemy[i][TANK][X] == 0 && enemy[i][TANK][Y] == 0) || enemyBulletDur[i] != -1) {
            continue;
        }

        enemyBulletDur[i] = maxBulletDur;

        enemyBullet[i][POS][X] = enemy[i][MUZZ][X];
        enemyBullet[i][POS][Y] = enemy[i][MUZZ][Y];

        enemyBullet[i][DIR][X] = enemy[i][MUZZ][X] - enemy[i][TANK][X];
        enemyBullet[i][DIR][Y] = enemy[i][MUZZ][Y] - enemy[i][TANK][Y];
    }
}

void updateBullet(int32_t **map, int32_t height, int32_t width) {
    if (playerBulletDur > 0) {
        playerBulletDur--;

        int32_t oldBulletX = playerBullet[POS][X];
        int32_t oldBulletY = playerBullet[POS][Y];

        int32_t newBulletX = playerBullet[POS][X] + playerBullet[DIR][X];
        int32_t newBulletY = playerBullet[POS][Y] + playerBullet[DIR][Y];

        if (map[oldBulletX][oldBulletY] != PLAYER_MUZZLE) {
            map[oldBulletX][oldBulletY] = EMPTY;
        }

        if (map[newBulletX][newBulletY] == BORDER) {
            if (newBulletX == 0 || newBulletX == height - 1) {
                playerBullet[DIR][X] = -playerBullet[DIR][X];
                newBulletX += playerBullet[DIR][X] + playerBullet[DIR][X];
            }

            if (newBulletY == 0 || newBulletY == width - 1) {
                playerBullet[DIR][Y] = -playerBullet[DIR][Y];
                newBulletY += playerBullet[DIR][Y] + playerBullet[DIR][Y];
            }
        } else if (map[newBulletX][newBulletY] == OBSTACLE) {
            map[newBulletX][newBulletY] = EMPTY;

            playerBullet[POS][X] = 0;
            playerBullet[POS][Y] = 0;

            playerBulletDur = -1;

            return;
        } else if (map[newBulletX][newBulletY] == ENEMY_MUZZLE || map[newBulletX][newBulletY] == ENEMY_TANK) {
            int32_t i = 0;
            for (i = 0; i < 3; i++) {
                if ((enemy[i][TANK][X] == newBulletX && enemy[i][TANK][Y] == newBulletY) ||
                    (enemy[i][MUZZ][X] == newBulletX && enemy[i][MUZZ][Y] == newBulletY)) {
                    break;
                }
            }

            map[enemy[i][TANK][X]][enemy[i][TANK][Y]] = EMPTY;
            map[enemy[i][MUZZ][X]][enemy[i][MUZZ][Y]] = EMPTY;

            enemyCount--;

            enemy[i][TANK][X] = 0;
            enemy[i][TANK][Y] = 0;
            enemy[i][MUZZ][X] = 0;
            enemy[i][MUZZ][Y] = 0;

            playerBullet[POS][X] = 0;
            playerBullet[POS][Y] = 0;

            playerBulletDur = -1;

            return;
        } else if (map[newBulletX][newBulletY] == PLAYER_MUZZLE || map[newBulletX][newBulletY] == PLAYER_TANK) {
            map[player[TANK][X]][player[TANK][Y]] = EMPTY;
            map[player[MUZZ][X]][player[MUZZ][Y]] = EMPTY;

            playerDead = 1;

            player[TANK][X] = 0;
            player[TANK][Y] = 0;
            player[MUZZ][X] = 0;
            player[MUZZ][X] = 0;

            playerBullet[POS][X] = 0;
            playerBullet[POS][Y] = 0;

            playerBulletDur = -1;

            return;
        }

        map[newBulletX][newBulletY] = BULLET;

        playerBullet[POS][X] = newBulletX;
        playerBullet[POS][Y] = newBulletY;
    } else if (playerBulletDur == 0) {
        playerBulletDur--;

        map[playerBullet[POS][X]][playerBullet[POS][Y]] = EMPTY;

        playerBullet[POS][X] = 0;
        playerBullet[POS][Y] = 0;
    }

    for (int32_t i = 0; i < 3; i++) {
        if (enemyBulletDur[i] > 0) {
            enemyBulletDur[i]--;

            int32_t oldBulletX = enemyBullet[i][POS][X];
            int32_t oldBulletY = enemyBullet[i][POS][Y];

            int32_t newBulletX = enemyBullet[i][POS][X] + enemyBullet[i][DIR][X];
            int32_t newBulletY = enemyBullet[i][POS][Y] + enemyBullet[i][DIR][Y];


            if (map[oldBulletX][oldBulletY] != ENEMY_MUZZLE) {
                map[oldBulletX][oldBulletY] = EMPTY;
            }

            if (map[newBulletX][newBulletY] == BORDER) {
                if (newBulletX == 0 || newBulletX == height - 1) {
                    enemyBullet[i][DIR][X] = -enemyBullet[i][DIR][X];
                    newBulletX += enemyBullet[i][DIR][X] + enemyBullet[i][DIR][X];
                }

                if (newBulletY == 0 || newBulletY == width - 1) {
                    enemyBullet[i][DIR][Y] = -enemyBullet[i][DIR][Y];
                    newBulletY += enemyBullet[i][DIR][Y] + enemyBullet[i][DIR][Y];
                }
            } else if (map[newBulletX][newBulletY] == OBSTACLE) {
                map[newBulletX][newBulletY] = EMPTY;

                enemyBullet[i][POS][X] = 0;
                enemyBullet[i][POS][Y] = 0;

                enemyBulletDur[i] = -1;

                return;
            } else if (map[newBulletX][newBulletY] == ENEMY_MUZZLE || map[newBulletX][newBulletY] == ENEMY_TANK) {
                int32_t i = 0;
                for (i = 0; i < 3; i++) {
                    if ((enemy[i][TANK][X] == newBulletX && enemy[i][TANK][Y] == newBulletY) ||
                        (enemy[i][MUZZ][X] == newBulletX && enemy[i][MUZZ][Y] == newBulletY)) {
                        break;
                    }
                }

                map[enemy[i][TANK][X]][enemy[i][TANK][Y]] = EMPTY;
                map[enemy[i][MUZZ][X]][enemy[i][MUZZ][Y]] = EMPTY;

                enemyCount--;

                enemy[i][TANK][X] = 0;
                enemy[i][TANK][Y] = 0;
                enemy[i][MUZZ][X] = 0;
                enemy[i][MUZZ][Y] = 0;

                enemyBullet[i][POS][X] = 0;
                enemyBullet[i][POS][Y] = 0;

                enemyBulletDur[i] = -1;

                return;
            } else if (map[newBulletX][newBulletY] == PLAYER_MUZZLE || map[newBulletX][newBulletY] == PLAYER_TANK) {
                map[player[TANK][X]][player[TANK][Y]] = EMPTY;
                map[player[MUZZ][X]][player[MUZZ][Y]] = EMPTY;

                playerDead = 1;

                player[TANK][X] = 0;
                player[TANK][Y] = 0;
                player[MUZZ][X] = 0;
                player[MUZZ][X] = 0;

                enemyBullet[i][POS][X] = 0;
                enemyBullet[i][POS][Y] = 0;

                enemyBulletDur[i] = -1;

                return;
            }


            map[newBulletX][newBulletY] = BULLET;

            enemyBullet[i][POS][X] = newBulletX;
            enemyBullet[i][POS][Y] = newBulletY;
        } else if (enemyBulletDur[i] == 0) {
            enemyBulletDur[i]--;

            map[enemyBullet[i][POS][X]][enemyBullet[i][POS][Y]] = EMPTY;

            enemyBullet[i][POS][X] = 0;
            enemyBullet[i][POS][Y] = 0;
        }
    }
}

int32_t isPlayerDead() {
    return playerDead;
}

int32_t isPlayerWin() {
    return (enemyCount == 0);
}
