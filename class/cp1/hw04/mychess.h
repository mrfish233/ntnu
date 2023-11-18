#pragma once

#include <stdio.h>
#include <stdint.h>

#define EMPTY           (0)
#define RED_GENERAL     (1)
#define RED_ADVISOR     (2)
#define RED_ELEPHANT    (3)
#define RED_HORSE       (4)
#define RED_CHARIOT     (5)
#define RED_CANNON      (6)
#define RED_SOLDIER     (7)
#define BLACK_GENERAL  (11)
#define BLACK_ADVISOR  (12)
#define BLACK_ELEPHANT (13)
#define BLACK_HORSE    (14)
#define BLACK_CHARIOT  (15)
#define BLACK_CANNON   (16)
#define BLACK_SOLDIER  (17)

#define BOARD_X 10
#define BOARD_Y  9

/**
 * Find and print all possible moves for red-side to check the black-side. All
 * moves are ordered by: piece order -> smallest i -> smallest j for (i,j).
 * Print format: `1) Move Horse from (4,7) to (6,6)`
 * @param board The given board.
 * @return The number of possible moves, -1 if the board is invalid.
 */
int32_t checkmate(int32_t board[BOARD_X][BOARD_Y]);

/**
 * Check if the position is valid.
 * @param x The position x of the piece.
 * @param y The position y of the piece.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidPos(int32_t x, int32_t y);

/**
 * Check the amount of piece.
 * @param piece The given piece.
 * @param amount The amount of the piece.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidPieceAmount(int32_t piece, int32_t amount);

/**
 * Check the amount of piece.
 * @param piece The given piece.
 * @param x The position x of the piece.
 * @param y The position y of the piece.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidPiecePosition(int32_t piece, int32_t x, int32_t y);

/**
 * Check the board's validity.
 * @param board The given board.
 * @return 1 if valid, 0 if invalid.
 */
int32_t isValidBoard(int32_t board[BOARD_X][BOARD_Y]);

/**
 * Check if the RED piece checkmates.
 * @param board The given board.
 * @param piece The given piece.
 * @param x The position x of the piece.
 * @param y The position y of the piece.
 * @return 1 if able to checkmate, 0 otherwise.
 */
int32_t canCheckmate(int32_t board[BOARD_X][BOARD_Y], int32_t piece, int32_t x, int32_t y);

/**
 * Find and print the checkmate moves for given RED pieces (Consider only moved piece).
 * Does not include checkmated board.
 * @param board The given board.
 * @param piece The given piece.
 * @param x The position x of the piece.
 * @param y The position y of the piece.
 */
void findCheckmateMoves(int32_t board[BOARD_X][BOARD_Y], int32_t piece, int32_t x, int32_t y);
