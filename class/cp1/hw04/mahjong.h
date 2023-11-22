#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mahjong_var.h"
#include "mahjong_yaku.h"

/**
 * Check if the tile is valid.
 * @param tile The given tile.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidTile(int32_t tile);

/**
 * Check if the amount of tiles are valid.
 * @param mahjong The mahjong struct.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidAmountOfTiles(myMahjong mahjong);

/**
 * Check if the meld is valid.
 * @param mahjong The mahjong struct.
 * @param meld The meld index to check.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidMeld(myMahjong mahjong, int32_t meld);

/**
 * Check if the pair is valid.
 * @param tile1 The first tile.
 * @param tile2 The second tile.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidPair(int32_t tile1, int32_t tile2);

/**
 * Check if the winning tile is valid.
 * @param mahjong The mahjong struct.
 * @param tile The winning tile.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidWinningTile(myMahjong mahjong, int32_t tile);

/**
 * Check if the wind is valid.
 * @param wind The wind.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidWind(int32_t wind);

/**
 * Calculate and print han from tiles.
 * @param mahjong The mahjong struct.
 */
void calculateHan(myMahjong mahjong);
