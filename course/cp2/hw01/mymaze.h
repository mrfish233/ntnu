#pragma once

#include <stdio.h>

#include <stdint.h>
#include <stdlib.h>

/**
 * Room structure
 * @param cost the cost of the room
 * @param doors the door number of 4 directions, 2 bits for each direction.
 * The doors are in the following order: N, E, S, W.
 * The adjacent room is accessible if the corresponding door numbers (0-3) are same, otherwise it is blocked.
 */
typedef struct _sRoom {
    uint32_t cost;
    uint8_t doors;
} sRoom;

/**
 * Point structure
 * @param row the number of rows
 * @param col the number of columns
 */
typedef struct _sPoint {
    uint32_t row;
    uint32_t col;
} sPoint;

/**
 * Path structure
 * @param length the length of the path
 * @param cost the cost of the path
 * @param pPath the array of all points in order
 */
typedef struct _sPath
{
    uint32_t length; // Path length.
    uint32_t cost;   // Cost
    sPoint *pPath;   // An array of all points in order.
} sPath;

/**
 * Find the minimum cost path from the top-left corner to the bottom-right corner of the maze.
 * @param pMaze the maze
 * @param row the number of rows
 * @param col the number of columns
 * @param pMinPath the minimum cost path
 * @return 1: success, 0: no path, -1: invalid input
 */
int32_t find_min_path(const sRoom *pMaze, const uint8_t row, const uint8_t col, sPath *pMinPath);

/**
 * Get the door number of the given direction.
 * @param door the door number of 4 directions
 * @param direction the direction
 * @return the door number of the given direction
 */
int32_t doorNum(uint8_t door, uint8_t direction);

/**
 * Check if the next position is reachable.
 * @param pMaze the maze
 * @param row the number of rows
 * @param col the number of columns
 * @param currPos the current position
 * @param nextPos the next position
 * @return 1: reachable, 0: blocked
 */
int32_t isReachable(const sRoom *pMaze, const uint8_t row, const uint8_t col, const sPoint currPos, const sPoint nextPos);

/**
 * Check if the positions are the same.
 * @param p1 the first position
 * @param p2 the second position
 * @return 1: same, 0: different
 */
int32_t isSamePos(const sPoint p1, const sPoint p2);

/**
 * Find the minimal cost path from 4 directions.
 * @param pDir the array of all paths
 * @param pMinPath the minimum cost path
 * @return 1: success, 0: no path
 */
int32_t findMinDir(sPath *pDir, sPath *pMinPath);
