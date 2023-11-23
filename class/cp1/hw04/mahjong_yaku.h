#pragma once

#include <stdio.h>
#include <stdint.h>
#include "mahjong_var.h"

/**
 * Check the tile is Yaochu (1, 9, or honors).
 * @param tile The given tile.
 * @return 1 if Yaochu, 0 otherwise.
 */
int32_t isYaochuTile(int32_t tile);

/**
 * Check if the meld is straight meld.
 * @param mahjong The mahjong struct.
 * @param meld The given meld.
 * @return 1 if straight, 0 otherwise.
 */
int32_t isStraightMeld(myMahjong mahjong, int32_t meld);

/**
 * Check if the meld is triplet or kan meld.
 * @param mahjong The mahjong struct.
 * @param meld The given meld.
 * @return 2 if kan, 1 if straight, 0 otherwise.
 */
int32_t isTripletOrKanMeld(myMahjong mahjong, int32_t meld);

/**
 * Check if the meld is special meld.
 * @param mahjong The mahjong struct.
 * @param meld The given meld.
 * @return 1 if special, 0 otherwise.
 */
int32_t isSpecialMeld(myMahjong mahjong, int32_t meld);

/**
 * Check if the hand is closed hand.
 * @param mahjong The mahjong struct.
 * @return 1 if closed hand, 0 otherwise.
 */
int32_t isClosedHand(myMahjong mahjong);

/**
 * Check the amount of honors of the hand.
 * @param mahjong The mahjong struct.
 * @return The amount of honors.
 */
int32_t amountOfHonors(myMahjong mahjong);

/**
 * Check the amount of terminals of the hand.
 * @param mahjong The mahjong struct.
 * @return The amount of terminals.
 */
int32_t amountOfTerminals(myMahjong mahjong);

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
 * @return 2 yakuman if big, 1 yakuman if small, 0 otherwise.
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
 * @return 2 yakuman if 13 waits, 1 yakuman if 1 wait, 0 otherwise.
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
 * 6 Han: Flush
 * 5 Han: Flush with open meld
 * @param mahjong The mahjong struct.
 * @return 6 or 5 han if condition met, 0 otherwise.
 */
int32_t isFlush(myMahjong mahjong);

/**
 * 3 Han: Half flush
 * 2 Han: Half flush with open meld
 * @param mahjong The mahjong struct.
 * @return 3 or 2 han if condition met, 0 otherwise.
 */
int32_t isHalfFlush(myMahjong mahjong);

/**
 * 3 Han: Terminal in each set
 * 2 Han: Terminal in each set with open meld
 * @param mahjong The mahjong struct.
 * @return 3 or 2 han if condition met, 0 otherwise.
 */
int32_t isTerminalInEachSet(myMahjong mahjong);

/**
 * 2 Han: All terminals and honors
 * @param mahjong The mahjong struct.
 * @return 2 han if condition met, 0 otherwise.
 */
int32_t isAllTerminalsAndHonors(myMahjong mahjong);

/**
 * 2 Han: All triplets
 * @param mahjong The mahjong struct.
 * @return 2 han if condition met, 0 otherwise.
 */
int32_t isAllTriplets(myMahjong mahjong);

/**
 * 2 Han: Seven pairs
 * @param mahjong The mahjong struct.
 * @return 2 han if condition met, 0 otherwise.
 */
int32_t isSevenPairs(myMahjong mahjong);

/**
 * Print yaku of the tiles.
 * @param yaku The given yaku.
 */
void printYaku(int32_t yaku);
