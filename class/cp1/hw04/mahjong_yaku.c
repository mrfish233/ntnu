#include "mahjong_yaku.h"

void sortTiles(int32_t *tiles, int32_t count) {
	if (count != 3 && count != 4 && count != 14) {
		return;
	}

	for (int32_t i = 0; i < count - 1; i++) {
		for (int32_t j = i + 1; j < count; j++) {
			if (tiles[i] > tiles[j]) {
				int32_t temp = tiles[i];
				tiles[i] = tiles[j];
				tiles[j] = temp;
			}
		}
	}
}

int32_t isStraightMeld(int32_t *tiles, int32_t count) {
	if (count != 3) {
		return 0;
	}

	sortTiles(tiles, count);

	switch (tiles[0]) {
		case PIN_8: case PIN_9:
		case SO_8:  case SO_9:
		case MAN_8: case MAN_9:
		case EAST:  case SOUTH: case WEST: case NORTH:
		case WHITE: case GREEN: case RED:
		return 0;
		break;

		default:
		break;
	}

	if ((tiles[0] + 1 == tiles[1]) && (tiles[1] + 1 == tiles[2])) {
		return 1;
	}

	return 0;
}

int32_t isTripletOrKanMeld(int32_t *tiles, int32_t count) {
	if (count != 3 && count != 4) {
		return 0;
	}

	for (int32_t i = 0; i < count - 1; i++) {
		if (tiles[i] != tiles[i + 1]) {
			return 0;
		}
	}

	return count - 2;
}

int32_t isSpecialMeld(int32_t count) {
	if (count != 14) {
		return 0;
	}

	return 1;
}

void printYaku(int32_t yaku) {
	printf("    ");

	switch (yaku) {
		case -1:
		default: 
		printf("Unreasonable case\n");
		break;
	}
}
