#include "mychess.h"

#define MOVE(x) "%d) Move " #x " from (%d,%d) to (%d,%d)\n"

// Amount of moves
static int32_t g_moves = 0;

int32_t checkmate(int32_t board[BOARD_X][BOARD_Y]) {
	if (!isValidBoard(board)) {
		return -1;
	}

	g_moves = 0;

	for (int32_t i = RED_HORSE; i <= RED_SOLDIER; i++) {
		for (int32_t j = 0; j < BOARD_X; j++) {
			for (int32_t k = 0; k < BOARD_Y; k++) {
				if (board[j][k] == i) {
					findCheckmateMoves(board, i, j, k);
				}
			}
		}
	}

	return g_moves;
}

int32_t isValidPos(int32_t x, int32_t y) {
	return !(x < 0 || x > BOARD_X || y < 0 || y > BOARD_Y);
}

int32_t isValidPieceAmount(int32_t piece, int32_t amount) {
	switch (piece) {
		case RED_GENERAL:
		case BLACK_GENERAL:
			if (amount != 1) {
				return 0;
			}
			break;
		case RED_ADVISOR:
		case RED_ELEPHANT:
		case RED_HORSE:
		case RED_CHARIOT:
		case RED_CANNON:
		case BLACK_ADVISOR:
		case BLACK_ELEPHANT:
		case BLACK_HORSE:
		case BLACK_CHARIOT:
		case BLACK_CANNON:
			if (amount > 2) {
				return 0;
			}
			break;
		case RED_SOLDIER:
		case BLACK_SOLDIER:
			if (amount > 5) {
				return 0;
			}
			break;
		default:
			return 0;
	}

	return 1;
}

int32_t isValidPiecePosition(int32_t piece, int32_t x, int32_t y) {
	switch (piece) {
		case RED_GENERAL:
			if ((x < 0 || x > 2) || (y < 3 || y > 5)) {
				return 0;
			}
			break;
		case BLACK_GENERAL:
			if ((x < 7 || x > 9) || (y < 3 || y > 5)) {
				return 0;
			}
			break;

		case RED_ADVISOR:
			if (!(  ((x == 0 || x == 2) && (y == 3 || y == 5)) || 
					((x == 1) && (y == 4)) )) {
				return 0;
			}
			break;
		case BLACK_ADVISOR:
			if (!(  ((x == 7 || x == 9) && (y == 3 || y == 5)) || 
					((x == 8) && (y == 4)) )) {
				return 0;
			}
			break;

		case RED_ELEPHANT:
			if (!(  ((x == 0 || x == 4) && (y == 2 || y == 6)) || 
					((x == 2) && (y == 0 || y == 4 || y == 8)) )) {
				return 0;
			}
			break;
		case BLACK_ELEPHANT:
			if (!(  ((x == 5 || x == 9) && (y == 2 || y == 6)) || 
					((x == 7) && (y == 0 || y == 4 || y == 8)) )) {
				return 0;
			}
			break;

		case RED_HORSE:
		case RED_CHARIOT:
		case RED_CANNON:
		case BLACK_HORSE:
		case BLACK_CHARIOT:
		case BLACK_CANNON:
			return 1;
			break;

		case RED_SOLDIER:
			if ((x < 3) || 
				((x == 3 || x == 4) && (y == 1 || y == 3 || y == 5 || y == 7))) {
				return 0;
			}
			break;
		case BLACK_SOLDIER:
			if ((x > 6) || 
				((x == 5 || x == 6) && (y == 1 || y == 3 || y == 5 || y == 7))) {
				return 0;
			}
			break;
		default:
			return 0;
	}

	return 1;
}

int32_t isValidBoard(int32_t board[BOARD_X][BOARD_Y]) {
	int32_t pieces[18] = {0};

	for (int32_t i = 0; i < BOARD_X; i++) {
		for (int32_t j = 0; j < BOARD_Y; j++) {
			if (board[i][j] == 0) {
				continue;
			}

			if (!isValidPiecePosition(board[i][j], i, j)) {
				return 0;
			}

			pieces[board[i][j]]++;
		}
	}

	for (int32_t i = 1; i < 18; i++) {
		if (i < RED_GENERAL || (i > RED_SOLDIER && i < BLACK_GENERAL) || i > BLACK_SOLDIER) {
			continue;
		}

		if (!isValidPieceAmount(i, pieces[i])) {
			return 0;
		}
	}

	return 1;
}

int32_t canCheckmate(int32_t board[BOARD_X][BOARD_Y], int32_t piece, int32_t x, int32_t y) {
	if (board[x][y] >= RED_GENERAL && board[x][y] <= RED_SOLDIER) {
		return 0;
	}

	if (!isValidPos(x, y)) {
		return 0;
	}

	switch (piece) {
		case RED_HORSE:
			if (isValidPos(x-1, y) && board[x-1][y] == EMPTY) {
				if ((isValidPos(x-2, y-1) && board[x-2][y-1] == BLACK_GENERAL) || 
					(isValidPos(x-2, y+1) && board[x-2][y+1] == BLACK_GENERAL)) {
					return 1;
				}
			}
			if (isValidPos(x+1, y) && board[x+1][y] == EMPTY) {
				if ((isValidPos(x+2, y-1) && board[x+2][y-1] == BLACK_GENERAL) || 
					(isValidPos(x+2, y+1) && board[x+2][y+1] == BLACK_GENERAL)) {
					return 1;
				}
			}
			if (isValidPos(x, y-1) && board[x][y-1] == EMPTY) {
				if ((isValidPos(x-1, y-2) && board[x-1][y-2] == BLACK_GENERAL) || 
					(isValidPos(x+1, y-2) && board[x+1][y-2] == BLACK_GENERAL)) {
					return 1;
				}
			}
			if (isValidPos(x, y+1) && board[x][y+1] == EMPTY) {
				if ((isValidPos(x-1, y+2) && board[x-1][y+2] == BLACK_GENERAL) || 
					(isValidPos(x+1, y+2) && board[x+1][y+2] == BLACK_GENERAL)) {
					return 1;
				}
			}
			break;
		case RED_CHARIOT:
		case RED_CANNON:
		case RED_SOLDIER:
		default:
			return 0;
	}

	return 0;
}

void findCheckmateMoves(int32_t board[BOARD_X][BOARD_Y], int32_t piece, int32_t x, int32_t y) {
	switch (piece) {
		case RED_HORSE:
			if (isValidPos(x-1, y) && board[x-1][y] == EMPTY) {
				if (canCheckmate(board, piece, x-2, y-1)) {
					printf(MOVE(Horse), ++g_moves, x, y, x-2, y-1);
				}
				if (canCheckmate(board, piece, x-2, y+1)) {
					printf(MOVE(Horse), ++g_moves, x, y, x-2, y+1);
				}
			}
			if (isValidPos(x, y-1) && board[x][y-1] == EMPTY) {
				if (canCheckmate(board, piece, x-1, y-2)) {
					printf(MOVE(Horse), ++g_moves, x, y, x-1, y-2);
				}
			}
			if (isValidPos(x, y+1) && board[x][y+1] == EMPTY) {
				if (canCheckmate(board, piece, x-1, y+2)) {
					printf(MOVE(Horse), ++g_moves, x, y, x-1, y+2);
				}
			}
			if (isValidPos(x, y-1) && board[x][y-1] == EMPTY) {
				if (canCheckmate(board, piece, x+1, y-2)) {
					printf(MOVE(Horse), ++g_moves, x, y, x+1, y-2);
				}
			}
			if (isValidPos(x, y+1) && board[x][y+1] == EMPTY) {
				if (canCheckmate(board, piece, x+1, y+2)) {
					printf(MOVE(Horse), ++g_moves, x, y, x+1, y+2);
				}
			}
			if (isValidPos(x+1, y) && board[x+1][y] == EMPTY) {
				if (canCheckmate(board, piece, x+2, y-1)) {
					printf(MOVE(Horse), ++g_moves, x, y, x+2, y-1);
				}
				if (canCheckmate(board, piece, x+2, y+1)) {
					printf(MOVE(Horse), ++g_moves, x, y, x+2, y+1);
				}
			}
			break;
		case RED_CHARIOT:
		case RED_CANNON:
		case RED_SOLDIER:
		default:
			return;
	}
}
