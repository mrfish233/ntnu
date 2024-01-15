#include "mychess.h"

#define MOVE(x) "%d) Move " #x " from (%d,%d) to (%d,%d)\n"

// Amount of moves
static int32_t g_moves = 0;

int32_t checkmate(int32_t board[BOARD_X][BOARD_Y]) {
	if (!isValidBoard(board)) {
		return -1;
	}

	g_moves = 0;

	for (int32_t i = RED_GENERAL; i <= RED_SOLDIER; i++) {
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

int32_t isRedPiece(int32_t piece) {
	return (piece >= RED_GENERAL && piece <= RED_SOLDIER);
}

int32_t isBlackPiece(int32_t piece) {
	return (piece >= BLACK_GENERAL && piece <= BLACK_SOLDIER);
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

		default: return 0;
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

		default: return 0;
	}

	return 1;
}

int32_t isValidBoard(const int32_t board[BOARD_X][BOARD_Y]) {
	int32_t pieces[18] = {0};

	for (int32_t i = 0; i < BOARD_X; i++) {
		for (int32_t j = 0; j < BOARD_Y; j++) {
			if (board[i][j] < 0 || board[i][j] > 18) {
				return 0;
			}

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
		if (!isRedPiece(i) && !isBlackPiece(i)) {
			continue;
		}

		if (!isValidPieceAmount(i, pieces[i])) {
			return 0;
		}
	}

	return 1;
}

int32_t canCheckmate(const int32_t board[BOARD_X][BOARD_Y], int32_t piece, int32_t newX, int32_t newY) {
	if (isRedPiece(board[newX][newY])) {
		return 0;
	}

	if (!isValidPos(newX, newY)) {
		return 0;
	}

	switch (piece) {
		case RED_GENERAL:
		for (int32_t i = newX; i < BOARD_X; i++) {
			if (board[i][newY] == BLACK_GENERAL) {
				return 1;
			} else if (isRedPiece(board[i][newY]) || isBlackPiece(board[i][newY])) {
				break;
			}
		}
		break;

		case RED_HORSE:
		if (isValidPos(newX-1, newY) && board[newX-1][newY] == EMPTY) {
			if ((isValidPos(newX-2, newY-1) && board[newX-2][newY-1] == BLACK_GENERAL) ||
				(isValidPos(newX-2, newY+1) && board[newX-2][newY+1] == BLACK_GENERAL)) {
				return 1;
			}
		}
		if (isValidPos(newX+1, newY) && board[newX+1][newY] == EMPTY) {
			if ((isValidPos(newX+2, newY-1) && board[newX+2][newY-1] == BLACK_GENERAL) ||
				(isValidPos(newX+2, newY+1) && board[newX+2][newY+1] == BLACK_GENERAL)) {
				return 1;
			}
		}
		if (isValidPos(newX, newY-1) && board[newX][newY-1] == EMPTY) {
			if ((isValidPos(newX-1, newY-2) && board[newX-1][newY-2] == BLACK_GENERAL) ||
				(isValidPos(newX+1, newY-2) && board[newX+1][newY-2] == BLACK_GENERAL)) {
				return 1;
			}
		}
		if (isValidPos(newX, newY+1) && board[newX][newY+1] == EMPTY) {
			if ((isValidPos(newX-1, newY+2) && board[newX-1][newY+2] == BLACK_GENERAL) ||
				(isValidPos(newX+1, newY+2) && board[newX+1][newY+2] == BLACK_GENERAL)) {
				return 1;
			}
		}
		break;

		case RED_CHARIOT:
		for (int32_t i = newX-1; i >= 0; i--) {
			if (isRedPiece(board[i][newY])) {
				break;
			}
			if (isBlackPiece(board[i][newY])) {
				if (board[i][newY] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
		}
		for (int32_t i = newY-1; i >= 0; i--) {
			if (isRedPiece(board[newX][i])) {
				break;
			}
			if (isBlackPiece(board[newX][i])) {
				if (board[newX][i] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
		}
		for (int32_t i = newY+1; i < BOARD_Y; i++) {
			if (isRedPiece(board[newX][i])) {
				break;
			}
			if (isBlackPiece(board[newX][i])) {
				if (board[newX][i] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
		}
		for (int32_t i = newX+1; i < BOARD_X; i++) {
			if (isRedPiece(board[i][newY])) {
				break;
			}
			if (isBlackPiece(board[i][newY])) {
				if (board[i][newY] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
		}
		break;

		case RED_CANNON:
		int32_t blockPiece = 0;
		for (int32_t i = newX-1; i >= 0; i--) {
			if (isRedPiece(board[i][newY]) || isBlackPiece(board[i][newY])) {
				blockPiece++;
			}
			if (blockPiece == 2 && isBlackPiece(board[i][newY])) {
				if (board[i][newY] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
			if (blockPiece == 2) {
				break;
			}
		}
		blockPiece = 0;
		for (int32_t i = newY-1; i >= 0; i--) {
			if (isRedPiece(board[newX][i]) || isBlackPiece(board[newX][i])) {
				blockPiece++;
			}
			if (blockPiece == 2 && isBlackPiece(board[newX][i])) {
				if (board[newX][i] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
			if (blockPiece == 2) {
				break;
			}
		}
		blockPiece = 0;
		for (int32_t i = newY+1; i < BOARD_Y; i++) {
			if (isRedPiece(board[newX][i]) || isBlackPiece(board[newX][i])) {
				blockPiece++;
			}
			if (blockPiece == 2 && isBlackPiece(board[newX][i])) {
				if (board[newX][i] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
			if (blockPiece == 2) {
				break;
			}
		}
		blockPiece = 0;
		for (int32_t i = newX+1; i < BOARD_X; i++) {
			if (isRedPiece(board[i][newY]) || isBlackPiece(board[i][newY])) {
				blockPiece++;
			}
			if (blockPiece == 2 && isBlackPiece(board[i][newY])) {
				if (board[i][newY] == BLACK_GENERAL) {
					return 1;
				} else {
					break;
				}
			}
			if (blockPiece == 2) {
				break;
			}
		}
		break;

		case RED_SOLDIER:
		if (isValidPos(newX, newY-1) && board[newX][newY-1] == BLACK_GENERAL) {
			return 1;
		}
		if (isValidPos(newX, newY+1) && board[newX][newY+1] == BLACK_GENERAL) {
			return 1;
		}
		if (isValidPos(newX+1, newY) && board[newX+1][newY] == BLACK_GENERAL) {
			return 1;
		}
		break;

		default: return 0;
	}

	return 0;
}

void findCheckmateMoves(const int32_t board[BOARD_X][BOARD_Y], int32_t piece, int32_t x, int32_t y) {
	switch (piece) {
		case RED_GENERAL:
		if (isValidPiecePosition(piece, x, y-1) && canCheckmate(board, piece, x, y-1)) {
			printf(MOVE(General), ++g_moves, x, y, x, y-1);
		}
		if (isValidPiecePosition(piece, x, y+1) && canCheckmate(board, piece, x, y+1)) {
			printf(MOVE(General), ++g_moves, x, y, x, y+1);
		}
		break;

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
		for (int32_t i = x-1; i >= 0; i--) {
			if (canCheckmate(board, piece, i, y)) {
				printf(MOVE(Chariot), ++g_moves, x, y, i, y);
			}
			if (isBlackPiece(board[i][y]) || isRedPiece(board[i][y])) {
				break;
			}
		}
		for (int32_t i = y-1; i >= 0; i--) {
			if (canCheckmate(board, piece, x, i)) {
				printf(MOVE(Chariot), ++g_moves, x, y, x, i);
			}
			if (isBlackPiece(board[x][i]) || isRedPiece(board[x][i])) {
				break;
			}
		}
		for (int32_t i = y+1; i < BOARD_Y; i++) {
			if (canCheckmate(board, piece, x, i)) {
				printf(MOVE(Chariot), ++g_moves, x, y, x, i);
			}
			if (isBlackPiece(board[x][i]) || isRedPiece(board[x][i])) {
				break;
			}
		}
		for (int32_t i = x+1; i < BOARD_X; i++) {
			if (canCheckmate(board, piece, i, y)) {
				printf(MOVE(Chariot), ++g_moves, x, y, i, y);
			}
			if (isBlackPiece(board[i][y]) || isRedPiece(board[i][y])) {
				break;
			}
		}
		break;

		case RED_CANNON:
		int32_t blockPiece = 0;
		for (int32_t i = x-1; i >= 0; i--) {
			if (isBlackPiece(board[i][y]) || isRedPiece(board[i][y])) {
				blockPiece++;
			}
			if ( ((blockPiece == 0) || (blockPiece == 2 && isBlackPiece(board[i][y]))) &&
				canCheckmate(board, piece, i, y) ) {
				printf(MOVE(Cannon), ++g_moves, x, y, i, y);
			}
			if (blockPiece == 2) {
				break;
			}
		}
		blockPiece = 0;
		for (int32_t i = y-1; i >= 0; i--) {
			if (isBlackPiece(board[x][i]) || isRedPiece(board[x][i])) {
				blockPiece++;
			}
			if ( ((blockPiece == 0) || (blockPiece == 2 && isBlackPiece(board[x][i]))) &&
				canCheckmate(board, piece, x, i) ) {
				printf(MOVE(Cannon), ++g_moves, x, y, x, i);
			}
			if (blockPiece == 2) {
				break;
			}
		}
		blockPiece = 0;
		for (int32_t i = y+1; i < BOARD_Y; i++) {
			if (isBlackPiece(board[x][i]) || isRedPiece(board[x][i])) {
				blockPiece++;
			}
			if ( ((blockPiece == 0) || (blockPiece == 2 && isBlackPiece(board[x][i]))) &&
				canCheckmate(board, piece, x, i) ) {
				printf(MOVE(Cannon), ++g_moves, x, y, x, i);
			}
			if (blockPiece == 2) {
				break;
			}
		}
		blockPiece = 0;
		for (int32_t i = x+1; i < BOARD_X; i++) {
			if (isBlackPiece(board[i][y]) || isRedPiece(board[i][y])) {
				blockPiece++;
			}
			if ( ((blockPiece == 0) || (blockPiece == 2 && isBlackPiece(board[i][y]))) &&
				canCheckmate(board, piece, i, y) ) {
				printf(MOVE(Cannon), ++g_moves, x, y, i, y);
			}
			if (blockPiece == 2) {
				break;
			}
		}
		break;

		case RED_SOLDIER:
		if (x == 3 || x == 4) {
			return;
		}
		if (isValidPos(x, y-1) && canCheckmate(board, piece, x, y-1)) {
			printf(MOVE(Soldier), ++g_moves, x, y, x, y-1);
		}
		if (isValidPos(x, y+1) && canCheckmate(board, piece, x, y+1)) {
			printf(MOVE(Soldier), ++g_moves, x, y, x, y+1);
		}
		if (isValidPos(x+1, y) && canCheckmate(board, piece, x+1, y)) {
			printf(MOVE(Soldier), ++g_moves, x, y, x+1, y);
		}
		break;

		default: return;
	}
}
