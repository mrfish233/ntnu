#pragma once

#include <stdio.h>
#include <stdint.h>
#include "rpgPlayer.h"
#include "rpgBoss.h"

/**
 * Initialize the file.
 * @return 0 if the file is opened successfully, -1 otherwise.
 */
int32_t rpgStoryInit();

/**
 * Clear the file.
 * @return 0 if the file is cleared successfully, -1 otherwise.
 */
int32_t rpgStoryClear();

/**
 * Handle each week of the game.
 * @param week The week number.
 * @return 0 if function is executed successfully, -1 if error of the file.
 */
int32_t rpgStoryWeek(int32_t week);

/**
 * Check if the player passes the roll.
 * @param check The check to pass.
 * @param str   The string to print.
 * @return 1 if the player passes the roll, 2 if critical success (1).
 * @return 0 if failure. -1 if critical failure (20).
 */
int32_t rpgStoryRollCheck(int32_t check, char *str);

/**
 * Handle the option of the day.
 * @param day    The day number.
 * @param option The option number.
 * @return next day number.
 * @return -1 if the option is invalid. 0 if the game is over.
 * @return -2 for special case: print the player stats.
 * @return -3 for special case: force the game to end.
 */
int32_t rpgStoryOptionHandle(int32_t day, int32_t option);

// NOTE: I'm lazy to write options in new text files, so I'll just write them inside the code.
