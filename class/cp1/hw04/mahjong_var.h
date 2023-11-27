#pragma once

#include<stdint.h>

/**
 * Mahjong Struct
 */
typedef struct MyMahjong {
	int32_t tiles[20];
	int32_t tilesAmount[35];
	int32_t melds[4][2];
	int32_t totalTiles;
	int32_t totalMelds;
	int32_t winningTile;
	int32_t playerWind;
	int32_t prevailingWind;
} myMahjong;

#define MELD_TILES 0
#define MELD_OPEN  1

#define TILE_TYPE 34

#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9

#define SO_1 10
#define SO_2 11
#define SO_3 12
#define SO_4 13
#define SO_5 14
#define SO_6 15
#define SO_7 16
#define SO_8 17
#define SO_9 18

#define MAN_1 19
#define MAN_2 20
#define MAN_3 21
#define MAN_4 22
#define MAN_5 23
#define MAN_6 24
#define MAN_7 25
#define MAN_8 26
#define MAN_9 27

#define EAST  28
#define SOUTH 29
#define WEST  30
#define NORTH 31

#define WHITE 32
#define GREEN 33
#define RED   34

#define ERROR_YAKU -1
#define NO_YAKU 0

#define ONE_YAKUMAN 100
#define TWO_YAKUMAN 200

#define ONE_HAN   1
#define TWO_HAN   2
#define THREE_HAN 3
#define FOUR_HAN  4
#define FIVE_HAN  5
#define SIX_HAN   6

#define BIG_FOUR_WINDS                      2001
#define FOUR_CONCEALED_TRIPLETS_SINGLE_WAIT 2002
#define NINE_GATES_NINE_WAIT                2003
#define THIRTEEN_ORPHANS_13_WAIT            2004

#define ALL_GREEN                           1001
#define ALL_HONORS                          1002
#define ALL_TERMINALS                       1003
#define BIG_THREE_DRAGONS                   1004
#define FOUR_CONCEALED_TRIPLETS             1005
#define FOUR_KANS                           1006
#define LITTLE_FOUR_WINDS                   1007
#define NINE_GATES                          1008
#define THIRTEEN_ORPHANS                    1009

#define FLUSH                               601

#define FLUSH_OPEN                          501

#define HALF_FLUSH                          301
#define TERMINAL_IN_EACH_SET                302

#define ALL_TERMINALS_AND_HONORS            201
#define ALL_TRIPLETS                        202
#define HALF_FLUSH_OPEN                     203
#define LITTLE_THREE_DRAGONS                204
#define SEVEN_PAIRS                         205
#define STRAIGHT                            206
#define TERMINAL_IN_EACH_SET_OPEN           207
#define TERMINAL_OR_HONOR_IN_EACH_SET       208
#define THREE_COLOUR_STRAIGHTS              209
#define THREE_COLOUR_TRIPLETS               210
#define THREE_CONCEALED_TRIPLETS            211
#define THREE_KANS                          212
#define TWO_SETS_OF_IDENTICAL_SEQUENCES     213

#define ALL_SIMPLES                         101
#define HONER_GREEN                         102
#define HONER_PLAYER_WIND                   103
#define HONER_PREVAILING_WIND               104
#define HONER_RED                           105
#define HONER_WHITE                         106
#define NO_POINTS_HAND                      107
#define ONE_SET_OF_IDENTICAL_SEQUENCES      108
#define STRAIGHT_OPEN                       109
#define TERMINAL_OR_HONOR_IN_EACH_SET_OPEN  110
#define THREE_COLOUR_STRAIGHTS_OPEN         111
