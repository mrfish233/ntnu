#include "mahjong.h"

int32_t isValidNewTile(myMahjong mahjong, int32_t tile) {
	if (tile < 1 || tile > 34) {
		return 0;
	}

	if (mahjong.tilesAmount[tile] == 4) {
		return 0;
	}

	return 1;
}

int32_t isValidAmountOfTiles(myMahjong mahjong) {
	int32_t tilesAmount[35] = {0};

	for (int32_t i = 0; i < mahjong.totalTiles; i++) {
		int32_t tile = mahjong.tiles[i];

		tilesAmount[tile]++;

		if (tilesAmount[tile] > 4) {
			return 0;
		}
	}

	return 1;
}

int32_t isValidMeld(myMahjong mahjong, int32_t meld) {
	if (meld < 0 || meld > 4) {
		return 0;
	}

	if (isStraightMeld(mahjong, meld) || isTripletOrKanMeld(mahjong, meld)) {
		return 1;
	}

	if (isSpecialMeld(mahjong, meld)) {
		return 2;
	}

	return 0;
}

int32_t isValidPair(int32_t tile1, int32_t tile2) {
	return (tile1 == tile2);
}

int32_t isValidWinningTile(myMahjong mahjong, int32_t tile) {
	int32_t check = 0;

	if (mahjong.tiles[mahjong.totalTiles-1] == tile) {
		return 1;
	}

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];

		for (int32_t j = head; j < tail; j++) {
			if ((mahjong.tiles[j] == tile) && (isTripletOrKanMeld(mahjong, i) != 2)) {
				check = 1;
				break;
			}
		}
	}

	// printf("check=%d\n", check);

	return check;
}

int32_t isValidDrawn(myMahjong mahjong, int32_t drawn) {
	if (drawn != 0 && drawn != 1) {
		return 0;
	}

	if (mahjong.tiles[mahjong.totalTiles-1] == mahjong.winningTile) {
		return 1;
	}

	if (mahjong.totalMelds == 1) {
		return 1;
	}

	int32_t check = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];

		for (int32_t j = head; j < tail; j++) {
			if ((mahjong.tiles[j] == mahjong.winningTile) && 
				(isTripletOrKanMeld(mahjong, i) != 2) &&
				(drawn == 0 || mahjong.melds[i][MELD_OPEN] == 0)) {
				check = 1;
				break;
			}
		}
	}

	printf("check=%d\n", check);

	return check;
}

int32_t isValidWind(int32_t wind) {
	return (wind == 0 || wind == 1 || wind == 2 || wind == 3);
}

void calculateHan(myMahjong mahjong) {
	int32_t result = 0;

	printf("The Score is...\n");

	if (mahjong.totalMelds == -1) {
		printYaku(ERROR_YAKU);
		printf("Total: 0 Han\n");
		return;
	}

	result = handleYakuman(mahjong);

	if (result != 0) {
		printf("Total: %d Yakuman\n", result / 100);
		return;
	}

	result = handleYaku(mahjong);

	if (result == 0) {
		printYaku(NO_YAKU);
	}

	printf("Total: %d Han", result);
	if (result >= 13) {
		printf(" (Kazoe-yakuman)");
	}
	printf("\n");
}
