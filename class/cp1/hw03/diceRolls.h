#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/**
 * Clear all dices rolled.
 */
void clearDices();

/**
 * Print a dice from array.
 * @param index The index of the dice to print.
 */
void printDice(int32_t index);

/**
 * Print all dices rolled.
 */
void printDices();

/**
 * Print all dices with index.
 */
void printDicesWithIndex();

/**
 * Print the sum of all dices rolled.
 */
void printSum();

/**
 * Print the sum of all kept dices.
 */
void printSumKept();

/**
 * Roll specified number of dices with specified number of sides.
 * @param numDices The number of dices to roll.
 * @param sides The number of sides on the die.
 * @return The sum of all rolled dices.
 */
int32_t rollDices(int32_t numDices, int32_t sides);

/**
 * Select dice to keep.
 * @param index The index of the dice to keep.
 * @return The value of the dice kept, -1 if invalid index.
 */
int32_t keepDice(int32_t index);

/**
 * Select and find the amount of highest and lowest dices to keep.
 * @param highest The amount of highest dices to keep.
 * @param lowest The amount of lowest dices to keep.
 * @return 0 if success, -1 if invalid index.
 */
int32_t keepHighestLowest(int32_t highest, int32_t lowest);

/**
 * Set shift value of sum for dice with range -10 to 10.
 * @param value The shift value.
 * @return 0 if success, -1 if invalid index.
 */
int32_t setSumShift(int32_t value);
