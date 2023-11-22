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

int32_t isSpecialMeld(myMahjong mahjong, int32_t count) {
	if (count != 14) {
		return 0;
	}

	if (!isThirteenOrphans(mahjong) && !isSevenPairs(mahjong)) {
		return 0;
	}

	return 1;
}

int32_t handleYakuman(myMahjong mahjong) {
	int32_t total = 0;

	// 2 Yakuman

	if (isFourWinds(mahjong) == TWO_YAKUMAN) {
		printYaku(BIG_FOUR_WINDS);
		total += TWO_YAKUMAN;
	}

	if (isFourConcealedTriplets(mahjong) == TWO_YAKUMAN) {
		printYaku(FOUR_CONCEALED_TRIPLETS_SINGLE_WAIT);
		total += TWO_YAKUMAN;
	}

	if (isNineGates(mahjong) == TWO_YAKUMAN) {
		printYaku(NINE_GATES_NINE_WAIT);
		total += TWO_YAKUMAN;
	}

	if (isThirteenOrphans(mahjong) == TWO_YAKUMAN) {
		printYaku(THIRTEEN_ORPHANS_13_WAIT);
		total += TWO_YAKUMAN;
	}

	// 1 Yakuman

	if (isAllGreen(mahjong) == ONE_YAKUMAN) {
		printYaku(ALL_GREEN);
		total += ONE_YAKUMAN;
	}

	if (isFourConcealedTriplets(mahjong) == ONE_YAKUMAN) {
		printYaku(FOUR_CONCEALED_TRIPLETS);
		total += ONE_YAKUMAN;
	}



	if (isFourWinds(mahjong) == ONE_YAKUMAN) {
		printYaku(LITTLE_FOUR_WINDS);
		total += ONE_YAKUMAN;
	}

	if (isNineGates(mahjong) == ONE_YAKUMAN) {
		printYaku(NINE_GATES);
		total += ONE_YAKUMAN;
	}

	if (isThirteenOrphans(mahjong) == ONE_YAKUMAN) {
		printYaku(THIRTEEN_ORPHANS);
		total += ONE_YAKUMAN;
	}

	return total;
}

int32_t isFourWinds(myMahjong mahjong) {
	int32_t triplet = 0, pair = 0;

	for (int32_t i = EAST; i <= NORTH; i++) {
		if (mahjong.tilesAmount[i] >= 3) {
			triplet++;
		} else if (mahjong.tilesAmount[i] == 2) {
			pair++;
		}
	}

	if (triplet == 4 && pair == 0) {
		return TWO_YAKUMAN;
	} else if (triplet == 3 && pair == 1) {
		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t isFourConcealedTriplets(myMahjong mahjong) {
	int32_t triplet = 0, pair = 0, close = 0;

	for (int32_t i = 1; i <= TILE_TYPE; i++) {
		int32_t tile = mahjong.tilesAmount[i];
		if (tile >= 3) {
			triplet++;
		}
		if (tile == 2 && mahjong.winningTile == i) {
			pair = 1;
		}
	}

	for (int32_t i = 0; i < 4; i++) {
		if (mahjong.melds[i][MELD_OPEN] == 0) {
			close++;
		}
	}

	if (triplet == 4 && close == 4) {
		return (pair == 1) ? TWO_YAKUMAN : ONE_YAKUMAN;
	}

	return 0;
}

int32_t isNineGates(myMahjong mahjong) {
	for (int32_t i = 0; i < 3; i++) {
		int32_t check = 0, nineWait = 0;

		for (int32_t j = 1; j <= 9; j++) {
			int32_t tile   = i * 9 + j;
			int32_t amount = mahjong.tilesAmount[tile];

			if ((j == 1 || j == 9) && amount >= 3) {
				check++;

				if (amount == 4 && mahjong.winningTile == tile) {
					nineWait = 1;
				}
			} else if (amount >= 1) {
				check++;

				if (amount == 2 && mahjong.winningTile == tile) {
					nineWait = 1;
				}
			}
		}

		// printf("check=%d wait=%d\n", check, nineWait);

		if (check == 9) {
			return (nineWait == 1) ? TWO_YAKUMAN : ONE_YAKUMAN;
		}
	}

	return 0;
}

int32_t isThirteenOrphans(myMahjong mahjong) {
	if (mahjong.tilesAmount[PIN_1] >= 1 && mahjong.tilesAmount[PIN_9] >= 1 &&
		mahjong.tilesAmount[SO_1]  >= 1 && mahjong.tilesAmount[SO_9]  >= 1 &&
		mahjong.tilesAmount[MAN_1] >= 1 && mahjong.tilesAmount[MAN_9] >= 1 &&
		mahjong.tilesAmount[EAST]  >= 1 && mahjong.tilesAmount[SOUTH] >= 1 &&
		mahjong.tilesAmount[WEST]  >= 1 && mahjong.tilesAmount[NORTH] >= 1 &&
		mahjong.tilesAmount[WHITE] >= 1 && mahjong.tilesAmount[GREEN] >= 1 &&
		mahjong.tilesAmount[RED]   >= 1 && mahjong.totalTiles == 14) {
		if (mahjong.tilesAmount[mahjong.winningTile] == 2) {
			return TWO_YAKUMAN;
		}

		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t isAllGreen(myMahjong mahjong) {
	int32_t so2   = mahjong.tilesAmount[SO_2];
	int32_t so3   = mahjong.tilesAmount[SO_3];
	int32_t so4   = mahjong.tilesAmount[SO_4];
	int32_t so6   = mahjong.tilesAmount[SO_6];
	int32_t so8   = mahjong.tilesAmount[SO_8];
	int32_t green = mahjong.tilesAmount[GREEN];

	// printf("total=%d\n", (so2 + so3 + so4 + so6 + so8 + green));

	return ((so2 + so3 + so4 + so6 + so8 + green) == mahjong.totalTiles);
}



int32_t isSevenPairs(myMahjong mahjong) {
	int32_t check = 0;
	for (int32_t i = 1; i <= TILE_TYPE; i++) {
		if (mahjong.tilesAmount[i] == 2) {
			check++;
		} else if (mahjong.tilesAmount[i] != 0) {
			return 0;
		}
	}

	if (check == 7) {
		return 2;
	}

	return 0;
}

void printYaku(int32_t yaku) {
	printf("    ");

	switch (yaku) {
		// Two Yakuman

		case BIG_FOUR_WINDS:
		printf("Big four winds (2 Yakuman)\n"); break;

		case FOUR_CONCEALED_TRIPLETS_SINGLE_WAIT:
		printf("Four concealed triplets single wait (2 Yakuman)\n"); break;

		case NINE_GATES_NINE_WAIT:
		printf("Nine gates nine wait (2 Yakuman)\n"); break;

		case THIRTEEN_ORPHANS_13_WAIT:
		printf("Thirteen orphans 13 wait (2 Yakuman)\n"); break;

		// One Yakuman

		case ALL_GREEN:
		printf("All green (1 Yakuman)\n"); break;

		case ALL_HONORS:
		printf("All honors (1 Yakuman)\n"); break;

		case ALL_TERMINALS:
		printf("All terminals (1 Yakuman)\n"); break;

		case BIG_THREE_DRAGONS:
		printf("Big three dragons (1 Yakuman)\n"); break;

		case FOUR_CONCEALED_TRIPLETS:
		printf("Four concealed triplets (1 Yakuman)\n"); break;

		case FOUR_KANS:
		printf("Four kans (1 Yakuman)\n"); break;

		case LITTLE_FOUR_WINDS:
		printf("Little four winds (1 Yakuman)\n"); break;

		case NINE_GATES:
		printf("Nine gates (1 Yakuman)\n"); break;

		case THIRTEEN_ORPHANS:
		printf("Thirteen orphans (1 Yakuman)\n"); break;

		// 6 Han

		case FLUSH:
		printf("Flush (6 Han)\n"); break;

		// 5 Han

		case FLUSH_OPEN:
		printf("Flush (5 Han)\n"); break;

		// 3 Han

		case HALF_FLUSH:
		printf("Half-flush (3 Han)\n"); break;

		case TERMINAL_IN_EACH_SET:
		printf("Terminal in each set (3 Han)\n"); break;

		// 2 Han

		case ALL_TERMINALS_AND_HONORS:
		printf("All terminals and honors (2 Han)\n"); break;

		case ALL_TRIPLETS:
		printf("All triplets (2 Han)\n"); break;

		case HALF_FLUSH_OPEN:
		printf("Half-flush (2 Han)\n"); break;

		case LITTLE_THREE_DRAGONS:
		printf("Little three dragons (2 Han)\n"); break;

		case SEVEN_PAIRS:
		printf("Seven pairs (2 Han)\n"); break;

		case STRAIGHT:
		printf("Straight (2 Han)\n"); break;

		case TERMINAL_IN_EACH_SET_OPEN:
		printf("Terminal in each set (2 Han)\n"); break;

		case TERMINAL_OR_HONOR_IN_EACH_SET:
		printf("Terminal or honor in each set (2 Han)\n"); break;

		case THREE_COLOUR_STRAIGHTS:
		printf("Three colour straights (2 Han)\n"); break;

		case THREE_COLOUR_TRIPLETS:
		printf("Three colour triplets (2 Han)\n"); break;

		case THREE_CONCEALED_TRIPLETS:
		printf("Three concealed triplets (2 Han)\n"); break;

		case THREE_KANS:
		printf("Three kans (2 Han)\n"); break;

		case TWO_SETS_OF_IDENTICAL_SEQUENCES:
		printf("Two sets of same sequences (2 Han)\n"); break;

		// 1 Han

		case ALL_SIMPLES:
		printf("All simples (1 Han)\n"); break;

		case HONER_GREEN:
		printf("Honer: Green (1 Han)\n"); break;

		case HONER_PLAYER_WIND:
		printf("Honer: Player's wind (1 Han)\n"); break;

		case HONER_PREVAILING_WIND:
		printf("Honer: Prevailing wind (1 Han)\n"); break;

		case HONER_RED:
		printf("Honer: Red (1 Han)\n"); break;

		case HONER_WHITE:
		printf("Honer: White (1 Han)\n"); break;

		case NO_POINTS_HAND:
		printf("No points Hand (1 Han)\n"); break;

		case ONE_SET_OF_IDENTICAL_SEQUENCES:
		printf("One set of identical sequences (1 Han)\n"); break;

		case STRAIGHT_OPEN:
		printf("Straight (1 Han)\n"); break;

		case TERMINAL_OR_HONOR_IN_EACH_SET_OPEN:
		printf("Terminal or honor in each set (1 Han)\n"); break;

		case THREE_COLOUR_STRAIGHTS_OPEN:
		printf("Three colour straights (1 Han)\n"); break;

		// Error

		case ERROR_YAKU:
		default: 
		printf("Unreasonable case\n"); break;
	}
}
