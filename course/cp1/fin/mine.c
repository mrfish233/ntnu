#include "mine.h"

#define ROW 16
#define COL 30

#define BLANK -1
#define MINE  -2

int32_t hit(int32_t board[16][30], int32_t row, int32_t col) {
    if (board[row][col] == MINE) {
        return 1;
    }

    if (board[row][col] != BLANK) {
        return -1;
    }

    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return -1;
    }

    int32_t surroundMines = 0;
    for (int32_t i = row - 1; i <= row + 1; i++) {
        if (i < 0 || i >= ROW) continue;

        for (int32_t j = col - 1; j <= col + 1; j++) {
            if (j < 0 || j >= COL) continue;

            if (board[i][j] == MINE) {
                surroundMines++;
            }
        }
    }

    board[row][col] = surroundMines;
    if (surroundMines != 0) {
        return 0;
    }

    for (int32_t i = row - 1; i <= row + 1; i++) {
        for (int32_t j = col - 1; j <= col + 1; j++) {
            hit(board, i, j);
        }
    }

    return 0;
}
