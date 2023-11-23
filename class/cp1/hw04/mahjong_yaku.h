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
 * @param mahjong The mahjong struct.
 * @param count The amount of tiles.
 * @return 1 if special, 0 otherwise.
 */
int32_t isSpecialMeld(myMahjong mahjong, int32_t count);

/**
 * Check if the hand is closed hand.
 * @param mahjong The mahjong struct.
 * @return 1 if closed hand, 0 otherwise.
 */
int32_t isClosedHand(myMahjong mahjong);

/**
 * Handle yakuman. Yakuman follows 2 rules to print:
 * amount of yakuman decreasingly, then lexicographical order.
 * @param mahjong The mahjong struct.
 * @return Total yakuman.
 */
int32_t handleYakuman(myMahjong mahjong);

/**
 * 2 Yakuman: Big four wind;
 * 1 Yakuman: Little four wind
 * @param mahjong The mahjong struct.
 * @return 2 yakuman if valid, 0 otherwise.
 */
int32_t isFourWinds(myMahjong mahjong);

/**
 * 2 Yakuman: Four concealed triplets single wait;
 * 1 Yakuman: Four concealed triplets
 * @param mahjong The mahjong struct.
 * @return 2 yakuman if 1 wait, 1 yakuman if 2 waits, 0 otherwise.
 */
int32_t isFourConcealedTriplets(myMahjong mahjong);

/**
 * 2 Yakuman: Nine gates nine waits;
 * 1 Yakuman: Nine gates
 * @param mahjong The mahjong struct.
 * @return 2 yakuman if 9 waits, 1 yakuman if 1 wait, 0 otherwise.
 */
int32_t isNineGates(myMahjong mahjong);

/**
 * 2 Yakuman: Thirteen orphans 13 waits;
 * 1 Yakuman: Thirteen orphans
 * @param mahjong The mahjong struct.
 * @return 2 yakuman if 13 wait, 1 yakuman if 1 wait, 0 otherwise.
 */
int32_t isThirteenOrphans(myMahjong mahjong);

/**
 * 1 Yakuman: All green
 * @param mahjong The mahjong struct.
 * @return 1 yakuman if all green, 0 otherwise.
 */
int32_t isAllGreen(myMahjong mahjong);

/**
 * 1 Yakuman: All honors
 * @param mahjong The mahjong struct.
 * @return 1 yakuman if all honors, 0 otherwise.
 */
int32_t isAllHonors(myMahjong mahjong);

/**
 * 1 Yakuman: All terminals
 * @param mahjong The mahjong struct.
 * @return 1 yakuman if all terminals, 0 otherwise.
 */
int32_t isAllTerminals(myMahjong mahjong);

/**
 * 1 Yakuman: Big three dragons
 * @param mahjong The mahjong struct.
 * @return 1 yakuman if big dragons, 0 otherwise.
 */
int32_t isBigThreeDragons(myMahjong mahjong);

/**
 * 1 Yakuman: Four kans
 * @param mahjong The mahjong struct.
 * @return 1 yakuman if four kans, 0 otherwise.
 */
int32_t isFourKans(myMahjong mahjong);

/**
 * Handle yaku. Han follows 2 rules to print:
 * amount of han decreasingly, then lexicographical order.
 * @param mahjong The mahjong struct.
 * @return Total han.
 */
int32_t handleYaku(myMahjong mahjong);

/**
 * 2 Han: seven pairs check
 * @param mahjong The mahjong struct.
 * @return 2 han if valid, 0 otherwise.
 */
int32_t isSevenPairs(myMahjong mahjong);

/**
 * Print yaku of the tiles.
 * @param yaku The given yaku.
 */
void printYaku(int32_t yaku);
