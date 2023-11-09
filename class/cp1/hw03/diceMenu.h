#pragma once

#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"
#include "rpgEvent.h"

/**
 * Print the menu for the dice program.
 */
void printMenu();

/**
 * Handle the user's choice from the menu.
 * @return The user's choice, -1 if invalid, 0 if exit.
 */
int32_t handleChoice();

/**
 * Exit the program.
 */
void callExit();

/**
 * Roll given number of given-sided dice.
 * @return 0 if success, -1 if invalid input.
 */
int32_t callRollGiven();

/**
 * Choose which dice to keep.
 * @return 0 if success, -1 if invalid input.
 */
int32_t callKeepDice();

/**
 * Choose amount of highest dice and lowest dice to keep.
 * @return 0 if success, -1 if invalid input.
 */
int32_t callKeepHighestLowest();

/**
 * Set the sum shift.
 * @return 0 if success, -1 if invalid input.
 */
int32_t callSetSumShift();

