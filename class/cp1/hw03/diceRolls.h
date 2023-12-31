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
 * Print a simple dice from array.
 * @param index The index of the dice to print.
 */
void printSimpleDice(int32_t index);

/**
 * Print all dices rolled.
 */
void printDices();

/**
 * Print all dices rolled in simple format.
 */
void printSimpleDices();

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
 * Get the number of kept dices.
 * @return The number of kept dices.
 */
int32_t getKeptDices();

/**
 * Get the sum of all dices rolled.
 * @return The sum of all dices rolled.
 */
int32_t getSum();

/**
 * Get the sum of all kept dices.
 * @return The sum of all kept dices.
 */
int32_t getSumKept();

/**
 * Roll specified number of dices with specified number of sides.
 * @param numDices The number of dices to roll.
 * @param sides The number of sides on the die.
 * @return The sum of all rolled dices.
 * @return -1 if invalid number of dices, -2 if invalid number of sides.
 */
int32_t rollDices(int32_t numDices, int32_t sides);

/**
 * Select dice to keep.
 * @param index The index of the dice to keep.
 * @return The value of the dice kept.
 * @return -1 if invalid index, -2 if already kept.
 */
int32_t keepDice(int32_t index);

/**
 * Select and find the amount of highest dices to keep.
 * @param highest The amount of highest dices to keep.
 * @return 0 if success.
 * @return -1 if invalid highest, -2 if invalid sum.
 */
int32_t keepHighest(int32_t highest);

/**
 * Select and find the amount of lowest dices to keep.
 * @param lowest The amount of lowest dices to keep.
 * @return 0 if success.
 * @return -1 if invalid lowest, -2 if invalid sum.
 */
int32_t keepLowest(int32_t lowest);

/**
 * Set shift value of sum for dice with range -10 to 10.
 * @param value The shift value.
 * @return 0 if success, -1 if invalid index.
 */
int32_t setSumShift(int32_t value);
