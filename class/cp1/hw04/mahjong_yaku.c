#include "mahjong_yaku.h"

int32_t isHonorTile(int32_t tile) {
	return (tile == EAST  || tile == SOUTH ||
			tile == WEST  || tile == NORTH ||
			tile == WHITE || tile == GREEN ||
			tile == RED);
}

int32_t isYaochuTile(int32_t tile) {
	return (tile == PIN_1 || tile == PIN_9 ||
			tile == SO_1  || tile == SO_9  ||
			tile == MAN_1 || tile == MAN_9 ||
			tile == EAST  || tile == SOUTH ||
			tile == WEST  || tile == NORTH ||
			tile == WHITE || tile == GREEN ||
			tile == RED);
}

int32_t isStraightMeld(myMahjong mahjong, int32_t meld) {
	int32_t head  = (meld == 0) ? 0 : mahjong.melds[meld-1][MELD_TILES];
	int32_t tail  = mahjong.melds[meld][MELD_TILES];
	int32_t tiles = tail - head;

	if (tiles != 3) {
		return 0;
	}

	int32_t tempMeld[3] = {0};

	for (int32_t i = head; i < tail; i++) {
		tempMeld[i - head] = mahjong.tiles[i];
	}

	for (int32_t i = 0; i < tiles - 1; i++) {
		for (int32_t j = i + 1; j < tiles; j++) {
			if (tempMeld[i] > tempMeld[j]) {
				int32_t temp = tempMeld[i];
				tempMeld[i]  = tempMeld[j];
				tempMeld[j]  = temp;
			}
		}
	}

	switch (tempMeld[0]) {
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

	if ((tempMeld[0] + 1 == tempMeld[1]) && (tempMeld[1] + 1 == tempMeld[2])) {
		// printf("Is straight!\n");
		return 1;
	}

	return 0;
}

int32_t isTripletOrKanMeld(myMahjong mahjong, int32_t meld) {
	int32_t head  = (meld == 0) ? 0 : mahjong.melds[meld-1][MELD_TILES];
	int32_t tail  = mahjong.melds[meld][MELD_TILES];
	int32_t tiles = tail - head;

	if (tiles != 3 && tiles != 4) {
		return 0;
	}

	for (int32_t i = head; i < tail - 1; i++) {
		if (mahjong.tiles[i] != mahjong.tiles[i + 1]) {
			return 0;
		}
	}

	return tiles - 2;
}

int32_t isSpecialMeld(myMahjong mahjong, int32_t meld) {
	int32_t head  = (meld == 0) ? 0 : mahjong.melds[meld-1][MELD_TILES];
	int32_t tail  = mahjong.melds[meld][MELD_TILES];
	int32_t tiles = tail - head;

	if (tiles != 14) {
		return 0;
	}

	if (!isThirteenOrphans(mahjong) && !isSevenPairs(mahjong)) {
		return 0;
	}

	return 1;
}

int32_t isClosedHand(myMahjong mahjong) {
	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (mahjong.melds[i][MELD_OPEN] == 1) {
			return 0;
		}
	}

	return 1;
}

int32_t amountOfHonors(myMahjong mahjong) {
	int32_t total = 0;
	for (int32_t i = EAST; i <= RED; i++) {
		total += mahjong.tilesAmount[i];
	}

	return total;
}

int32_t amountOfTerminals(myMahjong mahjong) {
	int32_t total = 0;

	total += mahjong.tilesAmount[PIN_1];
	total += mahjong.tilesAmount[PIN_9];
	total += mahjong.tilesAmount[SO_1];
	total += mahjong.tilesAmount[SO_9];
	total += mahjong.tilesAmount[MAN_1];
	total += mahjong.tilesAmount[MAN_9];

	return total;
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

	if (isAllHonors(mahjong) == ONE_YAKUMAN) {
		printYaku(ALL_HONORS);
		total += ONE_YAKUMAN;
	}

	if (isAllTerminals(mahjong) == ONE_YAKUMAN) {
		printYaku(ALL_TERMINALS);
		total += ONE_YAKUMAN;
	}

	if (isBigThreeDragons(mahjong) == ONE_YAKUMAN) {
		printYaku(BIG_THREE_DRAGONS);
		total += ONE_YAKUMAN;
	}

	if (isFourConcealedTriplets(mahjong) == ONE_YAKUMAN) {
		printYaku(FOUR_CONCEALED_TRIPLETS);
		total += ONE_YAKUMAN;
	}

	if (isFourKans(mahjong) == ONE_YAKUMAN) {
		printYaku(FOUR_KANS);
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
	int32_t triplet = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (isTripletOrKanMeld(mahjong, i)) {
			triplet++;
		}
	}

	if (triplet == 4 && isClosedHand(mahjong)) {
		if (mahjong.winningTile == mahjong.tiles[mahjong.totalTiles-1]) {
			return TWO_YAKUMAN;
		} else if (mahjong.selfDrawn == 1) {
			return ONE_YAKUMAN;
		}
	}

	return 0;
}

int32_t isNineGates(myMahjong mahjong) {
	if (!isClosedHand(mahjong)) {
		return 0;
	}

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
			} else if ((j != 1 && j != 9) && amount >= 1) {
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
	int32_t total = so2 + so3 + so4 + so6 + so8 + green;

	if (total == mahjong.totalTiles) {
		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t isAllHonors(myMahjong mahjong) {
	if (amountOfHonors(mahjong) == mahjong.totalTiles) {
		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t isAllTerminals(myMahjong mahjong) {
	if (amountOfTerminals(mahjong) == mahjong.totalTiles) {
		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t isBigThreeDragons(myMahjong mahjong) {
	int32_t white = mahjong.tilesAmount[WHITE];
	int32_t green = mahjong.tilesAmount[GREEN];
	int32_t red   = mahjong.tilesAmount[RED];

	if (white >= 3 && green >= 3 && red >= 3) {
		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t isFourKans(myMahjong mahjong) {
	if (mahjong.totalTiles == 18) {
		return ONE_YAKUMAN;
	}

	return 0;
}

int32_t handleYaku(myMahjong mahjong) {
	int32_t total = 0;

	// 6 Han

	if (isFlush(mahjong) == SIX_HAN) {
		printYaku(FLUSH);
		total += SIX_HAN;
	}

	// 5 Han

	if (isFlush(mahjong) == FIVE_HAN) {
		printYaku(FLUSH_OPEN);
		total += FIVE_HAN;
	}

	// 3 Han

	if (isHalfFlush(mahjong) == THREE_HAN) {
		printYaku(HALF_FLUSH);
		total += THREE_HAN;
	}

	if (isTerminalInEachSet(mahjong) == THREE_HAN) {
		printYaku(TERMINAL_IN_EACH_SET);
		total += THREE_HAN;
	}

	// 2 Han

	if (isAllTerminalsAndHonors(mahjong) == TWO_HAN) {
		printYaku(ALL_TERMINALS_AND_HONORS);
		total += TWO_HAN;
	}

	if (isAllTriplets(mahjong) == TWO_HAN) {
		printYaku(ALL_TRIPLETS);
		total += TWO_HAN;
	}

	if (isHalfFlush(mahjong) == TWO_HAN) {
		printYaku(HALF_FLUSH_OPEN);
		total += TWO_HAN;
	}

	if (isLittleThreeDragons(mahjong) == TWO_HAN) {
		printYaku(LITTLE_THREE_DRAGONS);
		total += TWO_HAN;
	}

	if (isSevenPairs(mahjong) == TWO_HAN) {
		printYaku(SEVEN_PAIRS);
		total += TWO_HAN;
	}

	if (isStraight(mahjong) == TWO_HAN) {
		printYaku(STRAIGHT);
		total += TWO_HAN;
	}

	if (isTerminalInEachSet(mahjong) == TWO_HAN) {
		printYaku(TERMINAL_IN_EACH_SET_OPEN);
		total += TWO_HAN;
	}

	if (isTerminalOrHonorInEachSet(mahjong) == TWO_HAN) {
		printYaku(TERMINAL_OR_HONOR_IN_EACH_SET);
		total += TWO_HAN;
	}

	if (isThreeColourStraights(mahjong) == TWO_HAN) {
		printYaku(THREE_COLOUR_STRAIGHTS);
		total += TWO_HAN;
	}

	if (isThreeColourTriplets(mahjong) == TWO_HAN) {
		printYaku(THREE_COLOUR_TRIPLETS);
		total += TWO_HAN;
	}

	if (isThreeConcealedTriplets(mahjong) == TWO_HAN) {
		printYaku(THREE_CONCEALED_TRIPLETS);
		total += TWO_HAN;
	}

	if (isThreeKans(mahjong) == TWO_HAN) {
		printYaku(THREE_KANS);
		total += TWO_HAN;
	}

	if (isIdenticalSequences(mahjong) == TWO_HAN) {
		printYaku(TWO_SETS_OF_IDENTICAL_SEQUENCES);
		total += TWO_HAN;
	}

	// 1 Han

	if (isAllSimples(mahjong) == ONE_HAN) {
		printYaku(ALL_SIMPLES);
		total += ONE_HAN;
	}

	if (hasHonerGreen(mahjong) == ONE_HAN) {
		printYaku(HONER_GREEN);
		total += ONE_HAN;
	}

	if (hasHonerPlayerWind(mahjong) == ONE_HAN) {
		printYaku(HONER_PLAYER_WIND);
		total += ONE_HAN;
	}

	if (hasHonerPrevailingWind(mahjong) == ONE_HAN) {
		printYaku(HONER_PREVAILING_WIND);
		total += ONE_HAN;
	}

	if (hasHonerRed(mahjong) == ONE_HAN) {
		printYaku(HONER_RED);
		total += ONE_HAN;
	}

	if (hasHonerWhite(mahjong) == ONE_HAN) {
		printYaku(HONER_WHITE);
		total += ONE_HAN;
	}

	if (hasNoPointsHand(mahjong) == ONE_HAN) {
		printYaku(NO_POINTS_HAND);
		total += ONE_HAN;
	}

	if (isIdenticalSequences(mahjong) == ONE_HAN) {
		printYaku(ONE_SET_OF_IDENTICAL_SEQUENCES);
		total += ONE_HAN;
	}

	if (isStraight(mahjong) == ONE_HAN) {
		printYaku(STRAIGHT_OPEN);
		total += ONE_HAN;
	}

	if (isTerminalOrHonorInEachSet(mahjong) == ONE_HAN) {
		printYaku(TERMINAL_OR_HONOR_IN_EACH_SET_OPEN);
		total += ONE_HAN;
	}

	if (isThreeColourStraights(mahjong) == ONE_HAN) {
		printYaku(THREE_COLOUR_STRAIGHTS_OPEN);
		total += ONE_HAN;
	}

	return total;
}

int32_t isFlush(myMahjong mahjong) {
	for (int32_t i = 0; i < 3; i++) {
		int32_t total = 0;

		for (int32_t j = 1; j <= 9; j++) {
			total += mahjong.tilesAmount[i * 9 + j];
		}

		if (total == mahjong.totalTiles) {
			return (isClosedHand(mahjong)) ? SIX_HAN : FIVE_HAN;
		}
	}

	return 0;
}

int32_t isHalfFlush(myMahjong mahjong) {
	if (amountOfHonors(mahjong) == 0) {
		return 0;
	}

	for (int32_t i = 0; i < 3; i++) {
		int32_t totalSuits = 0;

		for (int32_t j = 1; j <= 9; j++) {
			totalSuits += mahjong.tilesAmount[i * 9 + j];
		}

		if ((totalSuits + amountOfHonors(mahjong)) == mahjong.totalTiles) {
			return (isClosedHand(mahjong)) ? THREE_HAN : TWO_HAN;
		}
	}

	return 0;
}

int32_t isTerminalInEachSet(myMahjong mahjong) {
	if (amountOfHonors(mahjong) != 0) {
		return 0;
	}

	int32_t check = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];

		for (int32_t j = head; j < tail; j++) {
			if (isYaochuTile(mahjong.tiles[j])) {
				check++;
				break;
			}
		}
	}

	if (isYaochuTile(mahjong.tiles[mahjong.totalTiles-1])) {
		check++;
	}

	if (check == 5) {
		return (isClosedHand(mahjong)) ? THREE_HAN : TWO_HAN;
	}

	return 0;
}

int32_t isAllTerminalsAndHonors(myMahjong mahjong) {
	int32_t honors = amountOfHonors(mahjong);
	int32_t terminals = amountOfTerminals(mahjong);

	if (honors == 0 || terminals == 0) {
		return 0;
	}

	if (honors + terminals == mahjong.totalTiles) {
		return TWO_HAN;
	}

	return 0;
}

int32_t isAllTriplets(myMahjong mahjong) {
	int32_t triplet = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (isTripletOrKanMeld(mahjong, i)) {
			triplet++;
		}
	}

	if (triplet == 4) {
		return TWO_HAN;
		// return (pair == 1) ? TWO_YAKUMAN : ONE_YAKUMAN;
	}

	return 0;
}

int32_t isLittleThreeDragons(myMahjong mahjong) {
	int32_t triplet = 0, pair = 0;

	for (int32_t i = WHITE; i <= RED; i++) {
		if (mahjong.tilesAmount[i] >= 3) {
			triplet++;
		} else if (mahjong.tilesAmount[i] == 2) {
			pair = 1;
		}
	}

	if (triplet == 2 && pair == 1) {
		return TWO_HAN;
	}

	return 0;
}

int32_t isSevenPairs(myMahjong mahjong) {
	int32_t pair = 0;

	for (int32_t i = 1; i <= TILE_TYPE; i++) {
		if (mahjong.tilesAmount[i] == 2) {
			pair++;
		} else if (mahjong.tilesAmount[i] != 0) {
			return 0;
		}
	}

	if (pair == 7 && mahjong.totalMelds != 4) {
		return TWO_HAN;
	}

	return 0;
}

int32_t isStraight(myMahjong mahjong) {
	int32_t check123[3] = {0}, check456[3] = {0}, check789[3] = {0};

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (!isStraightMeld(mahjong, i)) {
			continue;
		}

		// printf("is straight!\n");

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];
		int32_t check[9] = {0};

		for (int32_t j = head; j < tail; j++) {
			int32_t num  = (mahjong.tiles[j] - 1) % 9;
			int32_t type = (mahjong.tiles[j] - 1) / 9 + 1;

			check[num] = type;
		}

		// printf("check: ");
		// for(int32_t j = 0; j < 9; j++) {
		// 	printf("%d ", check[j]);
		// }
		// printf("\n");

		if (check[0] && (check[0] == check[1]) && (check[0] == check[2])) {
			check123[check[0] - 1]++;
		}

		if (check[3] && (check[3] == check[4]) && (check[3] == check[5])) {
			check456[check[3] - 1]++;
		}

		if (check[6] && (check[6] == check[7]) && (check[6] == check[8])) {
			check789[check[6] - 1]++;
		}
	}

	// for (int32_t i = 0; i < 3; i++) {
	// 	printf("i=%d: %d %d %d\n", i+1, check123[i], check456[i], check789[i]);
	// }

	if ((check123[0] && check456[0] && check789[0]) ||
		(check123[1] && check456[1] && check789[1]) ||
		(check123[2] && check456[2] && check789[2])) {
		return (isClosedHand(mahjong)) ? TWO_HAN : ONE_HAN;
	}

	return 0;
}

int32_t isTerminalOrHonorInEachSet(myMahjong mahjong) {
	if (amountOfHonors(mahjong) == 0) {
		return 0;
	}

	int32_t straight = 0, yaochu = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (isStraightMeld(mahjong, i)) {
			straight++;
		}

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];

		for (int32_t i = head; i < tail; i++) {
			if (isYaochuTile(mahjong.tiles[i])) {
				yaochu++;
				break;
			}
		}
	}

	if (isYaochuTile(mahjong.tiles[mahjong.totalTiles-1])) {
		yaochu++;
	}

	if (straight && (yaochu == mahjong.totalMelds + 1)) {
		return (isClosedHand(mahjong)) ? TWO_HAN : ONE_HAN;
	}

	return 0;
}

int32_t isThreeColourStraights(myMahjong mahjong) {
	int32_t result[7][3] = {0};

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (!isStraightMeld(mahjong, i)) {
			continue;
		}

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];
		int32_t check[9] = {0};

		for (int32_t j = head; j < tail; j++) {
			int32_t num  = (mahjong.tiles[j] - 1) % 9;
			int32_t type = (mahjong.tiles[j] - 1) / 9 + 1;
			check[num] = type;
		}

		for (int32_t j = 0; j < 7; j++) {
			if (check[j] && (check[j] == check[j+1]) && (check[j] == check[j+2])) {
				result[j][check[j] - 1]++;
			}
		}
	}

	// printf("     P S M\n");
	// for (int32_t i = 0; i < 7; i++) {
	// 	printf("%d%d%d: ", i+1,i+2,i+3);
	// 	for (int32_t j = 0; j < 3; j++) {
	// 		printf("%d ", result[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (int32_t i = 0; i < 7; i++) {
		if (result[i][0] && result[i][1] && result[i][2]) {
			return (isClosedHand(mahjong)) ? TWO_HAN : ONE_HAN;
		}
	}

	return 0;
}

int32_t isThreeColourTriplets(myMahjong mahjong) {
	int32_t result[9][3] = {0};

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (!isTripletOrKanMeld(mahjong, i)) {
			continue;
		}

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tile = mahjong.tiles[head];

		if (isHonorTile(tile)) {
			continue;
		}

		result[(tile - 1) % 9][(tile - 1) / 9]++;
	}

	// printf("   P S M\n");
	// for (int32_t i = 0; i < 9; i++) {
	// 	printf("%d: ", i+1);
	// 	for (int32_t j = 0; j < 3; j++) {
	// 		printf("%d ", result[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (int32_t i = 0; i < 9; i++) {
		if (result[i][0] && result[i][1] && result[i][2]) {
			return TWO_HAN;
		}
	}

	return 0;
}

int32_t isThreeConcealedTriplets(myMahjong mahjong) {
	int32_t close = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (!isTripletOrKanMeld(mahjong, i)) {
			continue;
		}

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tile = mahjong.tiles[head];

		if (mahjong.melds[i][MELD_OPEN] == 0 && tile != mahjong.winningTile) {
			close++;
		}
	}

	if (close == 3) {
		return TWO_HAN;
	}

	return 0;
}

int32_t isThreeKans(myMahjong mahjong) {
	if (mahjong.totalTiles == 17) {
		return TWO_HAN;
	}

	return 0;
}

int32_t isIdenticalSequences(myMahjong mahjong) {
	if (!isClosedHand(mahjong)) {
		return 0;
	}

	int32_t result[7][3] = {0};
	
	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (!isStraightMeld(mahjong, i)) {
			continue;
		}

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];
		int32_t check[9] = {0};

		for (int32_t j = head; j < tail; j++) {
			int32_t num  = (mahjong.tiles[j] - 1) % 9;
			int32_t type = (mahjong.tiles[j] - 1) / 9 + 1;
			check[num] = type;
		}

		for (int32_t j = 0; j < 7; j++) {
			if (check[j] && (check[j] == check[j+1]) && (check[j] == check[j+2])) {
				result[j][check[j] - 1]++;
			}
		}
	}

	int32_t identical = 0;

	for (int32_t i = 0; i < 7; i++) {
		for (int32_t j = 0; j < 3; j++) {
			if (result[i][j] == 2) {
				identical++;
			}
		}
	}

	if (identical == 2) {
		return TWO_HAN;
	} else if (identical == 1) {
		return ONE_HAN;
	}

	return 0;
}

int32_t isAllSimples(myMahjong mahjong) {
	for (int32_t i = 0; i < mahjong.totalTiles; i++) {
		if (isYaochuTile(mahjong.tiles[i])) {
			return 0;
		}
	}

	return ONE_HAN;
}

int32_t hasHonerGreen(myMahjong mahjong) {
	if (mahjong.tilesAmount[GREEN] >= 3) {
		return ONE_HAN;
	}

	return 0;
}

int32_t hasHonerPlayerWind(myMahjong mahjong) {
	for (int32_t i = EAST; i <= NORTH; i++) {
		if (mahjong.tilesAmount[i] >= 3 && (mahjong.playerWind + EAST == i)) {
			return ONE_HAN;
		}
	}

	return 0;
}

int32_t hasHonerPrevailingWind(myMahjong mahjong) {
	for (int32_t i = EAST; i <= NORTH; i++) {
		if (mahjong.tilesAmount[i] >= 3 && (mahjong.prevailingWind + EAST == i)) {
			return ONE_HAN;
		}
	}

	return 0;
}

int32_t hasHonerRed(myMahjong mahjong) {
	if (mahjong.tilesAmount[RED] >= 3) {
		return ONE_HAN;
	}

	return 0;
}

int32_t hasHonerWhite(myMahjong mahjong) {
	if (mahjong.tilesAmount[WHITE] >= 3) {
		return ONE_HAN;
	}

	return 0;
}

int32_t hasNoPointsHand(myMahjong mahjong) {
	int32_t noPointsHand = 0;

	for (int32_t i = 0; i < mahjong.totalMelds; i++) {
		if (!isStraightMeld(mahjong, i)) {
			return 0;
		}

		int32_t head = (i == 0) ? 0 : mahjong.melds[i-1][MELD_TILES];
		int32_t tail = mahjong.melds[i][MELD_TILES];
		int32_t check[9] = {0};

		for (int32_t j = head; j < tail; j++) {
			int32_t num = (mahjong.tiles[j] - 1) % 9;
			check[num] = mahjong.tiles[j];
		}

		for (int32_t j = 0; j < 7; j++) {
			if ((check[j] && check[j+1] == mahjong.winningTile) ||
				(j == 6 && check[j] == mahjong.winningTile) ||
				(j == 0 && check[j+2] == mahjong.winningTile)) {
				break;
			} else if (check[j] == mahjong.winningTile || 
					(check[j] && check[j+2] == mahjong.winningTile)) {
				noPointsHand++;
				break;
			}
		}
	}

	if (noPointsHand) {
		return ONE_HAN;
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
		printf("Two sets of identical sequences (2 Han)\n"); break;

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

		case NO_YAKU:
		printf("No Yaku\n"); break;

		// Error

		case ERROR_YAKU:
		default: 
		printf("Unreasonable case\n"); break;
	}
}
