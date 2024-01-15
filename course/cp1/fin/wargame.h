#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void printMap(int32_t **map, int32_t height, int32_t width);

void initMap(int32_t **map, int32_t height, int32_t width);

void initRandom();

void initPos(int32_t **map, int32_t height, int32_t width);

void playerAction(int32_t **map, char input);
void playerMove(int32_t **map, char input);
void enemyAction(int32_t **map);
void enemyMove(int32_t **map);
void updateMuzzle(int32_t tankX, int32_t tankY, int32_t *muzzX, int32_t *muzzY);

void playerShoot();
void enemyShoot();
void updateBullet(int32_t **map, int32_t height, int32_t width);

int32_t isPlayerDead();
int32_t isPlayerWin();
