#include <stdio.h>
#include <stdint.h>
#include "mychess.h"

int main() {
	// int32_t board[BOARD_X][BOARD_Y] = {
	// 	// RED
	// 	{ 0, 0, 0, 1, 0, 0, 0, 0, 0},
	// 	{ 0, 0,15, 0,17, 0, 0,15, 0},
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{ 0, 4, 0, 0,17, 0,17, 6, 0},
	// 	/*  CHU HE ------ HAN JIE  */
	// 	{ 0, 0, 0, 0,14, 0, 0, 0, 0},
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
	// 	{ 0, 0, 0, 0,11, 0, 7, 0,14},
	// 	{ 0, 0, 0, 0, 0, 0, 0, 5, 0},
	// 	{ 0, 0, 0,12, 0,12, 0, 0, 0},
	// 	// BLACK
	// };

	// for (int32_t i = 0; i < BOARD_X; i++) {
	// 	for (int32_t j = 0; j < BOARD_Y; j++) {
	// 		printf("%-2d ", board[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int32_t board[BOARD_X][BOARD_Y] = {0};

	printf("Input board: \n");
	for (int32_t i = 0; i < BOARD_X; i++) {
		for (int32_t j = 0; j < BOARD_Y; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	printf("Total moves: %d\n", checkmate(board));

	return 0;
}
