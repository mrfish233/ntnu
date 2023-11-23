#include "mahjong.h"

int32_t isValidNewTile(myMahjong mahjong, int32_t tile) {
	// return (tile >= 1 && tile <= 34);
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

	// int32_t head  = (meld == 0) ? 0 : mahjong.melds[meld-1][MELD_TILES];
	// int32_t tail  = mahjong.melds[meld][MELD_TILES];
	// int32_t tiles = tail - head;

	// // printf("tiles=%d, tail=%d, head=%d\n", tiles, tail, head);

	// if (tiles != 3 && tiles != 4 && tiles != 14) {
	// 	return 0;
	// }

	// int32_t *meldTiles = calloc(tiles, sizeof(int32_t));

	// // printf("Current meld: ");
	// for (int32_t i = head; i < tail; i++) {
	// 	// printf("%d ", mahjong.tiles[i]);
	// 	meldTiles[i - head] = mahjong.tiles[i]; 
	// }
	// // printf("\n");

	// if (isStraightMeld(meldTiles, tiles) || isTripletOrKanMeld(meldTiles, tiles)) {
	// 	return 1;
	// }

	// if (isSpecialMeld(mahjong, tiles)) {
	// 	return 2;
	// }

	// printf("Current meld in meldTiles: ");
	// for (int32_t i = 0; i < tiles; i++) {
	// 	printf("%d ", meldTiles[i]);
	// }
	// printf("\n");

	// free(meldTiles);

	return 0;
}

int32_t isValidPair(int32_t tile1, int32_t tile2) {
	return (tile1 == tile2);
}

int32_t isValidWinningTile(myMahjong mahjong, int32_t tile) {
	for (int32_t i = 0; i < mahjong.totalTiles; i++) {
		if (mahjong.tiles[i] == tile) {
			return 1;
		}
	}

	return 0;
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

	printf("Total: %d Han", result);
	if (result >= 13) {
		printf(" (Kazoe-yakuman)");
	}
	printf("\n");
}