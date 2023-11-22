#pragma once

#include <stdio.h>
#include <stdint.h>
#include "mahjong_var.h"

/**
 * Sort the tiles.
 * @param tiles The tiles array of a meld.
 * @param count The amount of tiles.
 */
void sortTiles(int32_t *tiles, int32_t count);

/**
 * Check if the meld is straight meld.
 * @param tiles The tiles array of a meld.
 * @param count The amount of tiles.
 * @return 1 if straight, 0 otherwise.
 */
int32_t isStraightMeld(int32_t *tiles, int32_t count);

/**
 * Check if the meld is triplet or kan meld.
 * @param tiles The tiles array of a meld.
 * @param count The amount of tiles.
 * @return 2 if kan, 1 if straight, 0 otherwise.
 */
int32_t isTripletOrKanMeld(int32_t *tiles, int32_t count);

/**
 * Check if the meld is special meld.
 * @param count The amount of tiles.
 * @return 1 if special, 0 otherwise.
 */
int32_t isSpecialMeld(int32_t count);

/**
 * Handle yakuman hand.
 * @param mahjong The mahjong struct.
 * @return total yakuman, 0 if no yakuman.
 */
int32_t handleYakuman(myMahjong mahjong);

/**
 * Handle all required yaku.
 * @param mahjong The mahjong struct.
 * @return total han.
 */
int32_t handleYaku(myMahjong mahjong);

/**
 * Print yaku of the tiles.
 * @param yaku The given yaku.
 */
void printYaku(int32_t yaku);
