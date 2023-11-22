#pragma once

/**
 * Mahjong Struct
 */
typedef struct MyMahjong {
	int32_t tiles[20];
	int32_t melds[4][2];
	int32_t totalTiles;
	int32_t totalMelds;
	int32_t winningTile;
	int32_t selfDrawn;
	int32_t playerWind;
	int32_t prevailingWind;
} myMahjong;

#define MELD_TILES 0
#define MELD_OPEN  1

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
