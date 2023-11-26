#include <stdio.h>
#include <stdint.h>
#include "mahjong.h"

int main() {
	// myMahjong mahjong = { {0}, {0}, { {0},{0} }, 0, 0, 0, 0, 0, 0 };
	myMahjong mahjong = { {0}, {0}, { {0},{0} }, 0, 0, 0, 0, 0 };

	// Hand input

	int32_t meld = 0, validHand = 1;
	while (meld != 4) {
		printf("Please input meld: ");

		int32_t tile = 0, count = 0;
		while (count <= 14) {
			if (scanf("%d", &tile) != 1 || !isValidNewTile(mahjong, tile)) {
				if (tile != 0) {
					validHand = 0;
				}
				break;
			}

			mahjong.tilesAmount[tile]++;
			mahjong.tiles[mahjong.totalTiles++] = tile;
			count++;
		}

		mahjong.melds[meld][MELD_TILES] = mahjong.totalTiles;
		int32_t check = isValidMeld(mahjong, meld);
		// printf("check=%d, total=%d\n", check, mahjong.totalTiles);
		if (validHand == 0 || check == 0) {
			validHand = 0;
			meld = -1;
			break;
		} else if (check == 2) {
			meld = 1;
			break;
		}

		printf("Is open/closed group(1: YES 0: NO): ");

		int32_t openMeld = 0;
		if (scanf("%d", &openMeld) != 1 || (openMeld != 0 && openMeld != 1)) {
			validHand = 0;
			meld = -1;
			break;
		}

		mahjong.melds[meld][MELD_OPEN] = openMeld;

		meld++;
	}

	mahjong.totalMelds = meld;

	// Pair input

	if (validHand && meld != 1) {
		printf("Please input pair: ");

		int32_t pair = 0;
		while (pair < 2) {
			int32_t tile = 0;
			if (scanf("%d", &tile) != 1 || !isValidNewTile(mahjong, tile)) {
				validHand = 0;
				break;
			}

			mahjong.tilesAmount[tile]++;
			mahjong.tiles[mahjong.totalTiles++] = tile;

			pair++;
		}
	}

	if (validHand && meld != 1) {
		int32_t pair1 = mahjong.tiles[mahjong.totalTiles - 1];
		int32_t pair2 = mahjong.tiles[mahjong.totalTiles - 2];
		if (!isValidPair(pair1, pair2)) {
			validHand = 0;
		}
	}

	// Winning tile input

	if (validHand) {
		int32_t tile = 0;
		printf("Please input winning tile: ");

		if (scanf("%d", &tile) != 1 || !isValidWinningTile(mahjong, tile)) {
			// printf("Invalid winning tile!\n");
			validHand = 0;
		}

		mahjong.winningTile = tile;
	}

	// Self drawn input

	// if (validHand) {
	// 	int32_t selfDrawn = 0;
	// 	printf("Is Self-drawn win?(1: YES 0: NO): ");

	// 	if (scanf("%d", &selfDrawn) != 1 || !isValidDrawn(mahjong, selfDrawn)) {
	// 		// printf("Invalid self drawn!\n");
	// 		validHand = 0;
	// 	}

	// 	mahjong.selfDrawn = selfDrawn;
	// }

	// Wind input

	if (validHand) {
		int32_t playerWind = 0;
		printf("Player's wind(0:E 1:S 2:W 3:N): ");

		if (scanf("%d", &playerWind) != 1 || !isValidWind(playerWind)) {
			// printf("Invalid player wind!\n");
			validHand = 0;
		}

		mahjong.playerWind = playerWind;
	}

	if (validHand) {
		int32_t prevailingWind = 0;
		printf("Prevailing wind(0:E 1:S 2:W 3:N): ");

		if (scanf("%d", &prevailingWind) != 1 || !isValidWind(prevailingWind)) {
			// printf("Invalid player wind!\n");
			validHand = 0;
		}

		mahjong.prevailingWind = prevailingWind;
	}

	// printf("All tiles: \n");
	// for (int32_t i = 0; i < mahjong.totalMelds; i++) {
	// 	int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
	// 	int32_t tail = mahjong.melds[i][MELD_TILES];

	// 	for (int32_t j = head; j < tail; j++) {
	// 		printf("%d ", mahjong.tiles[j]);
	// 	}
	// 	printf("\n");
	// }

	if (!validHand) {
		mahjong.totalMelds = -1;
	}

	printf("\n");
	calculateHan(mahjong);

	return 0;
}
