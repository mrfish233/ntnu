#include <stdio.h>
#include <stdint.h>
#include "mychess.h"

int main() {
	int32_t board[BOARD_X][BOARD_Y] = {
		// RED
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{ 0, 0,15, 0,17, 0, 0,15, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0,17, 0,17, 4, 0},
		/*  CHU HE ------ HAN JIE  */
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0,11, 0, 7, 0,14},
		{ 0, 0, 0, 0, 0, 0, 0, 5, 0},
		{ 0, 0, 0,12, 0,12, 0, 0, 0},
		// BLACK
	};

	printf("Total moves: %d\n", checkmate(board));

	return 0;
}
