#pragma once

#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"

enum PlayerClass {
	CLASS_NONE,
	CLASS_WARRIOR,
	CLASS_ROGUE,
	CLASS_MAGE
};

/**
 * Clear the player's stats.
 */
void clearPlayer();

/**
 * Initialize the player's stats.
 */
void initPlayer(enum PlayerClass class);

/**
 * Print the player's stats.
 */
void printPlayer();

/**
 * Get the player's STR.
 * @return The player's STR.
 */
int32_t getPlayerSTR();

/**
 * Get the player's INT.
 * @return The player's INT.
 */
int32_t getPlayerINT();

/**
 * Get the player's DEX.
 * @return The player's DEX.
 */
int32_t getPlayerDEX();

/**
 * Get the player's health.
 * @return The player's health.
 */
int32_t getPlayerHealth();

/**
 * Get the player's sanity.
 * @return The player's sanity.
 */
int32_t getPlayerSanity();

/**
 * Get the player's luck.
 * @return The player's luck.
 */
int32_t getPlayerLuck();

/**
 * Get the player's inventory.
 * @param index The index of the item.
 * @return 1 if the item is in the inventory, 0 otherwise.
 * @return -1 if the index is invalid.
 */
int32_t getPlayerInventory(uint64_t index);

/**
 * Set the player's STR.
 * @param newSTR The STR to set.
 * @return 0 if the STR is set successfully, -1 otherwise.
 */
void setPlayerSTR(int32_t newSTR);

/**
 * Set the player's INT.
 * @param newINT The INT to set.
 * @return 0 if the INT is set successfully, -1 otherwise.
 */
void setPlayerINT(int32_t newINT);

/**
 * Set the player's DEX.
 * @param newDEX The DEX to set.
 * @return 0 if the DEX is set successfully, -1 otherwise.
 */
void setPlayerDEX(int32_t newDEX);

/**
 * Set the player's health.
 * @param newHealth The health to set.
 * @return 0 if the health is set successfully, -1 otherwise.
 */
void setPlayerHealth(int32_t newHealth);

/**
 * Set the player's sanity.
 * @param newSanity The sanity to set.
 * @return 0 if the sanity is set successfully, -1 otherwise.
 */
void setPlayerSanity(int32_t newSanity);

/**
 * Set the player's luck.
 * @param newLuck The luck to set.
 * @return 0 if the luck is set successfully, -1 otherwise.
 */
void setPlayerLuck(int32_t newLuck);

/**
 * Set the player's inventory.
 * @param index The index of the item.
 * @param value The value to set.
 * @return 0 if the inventory is set successfully, -1 otherwise.
 */
void setPlayerInventory(uint64_t index, int32_t value);

/**
 * Roll the stats.
 * @param numDice  Number of dices.
 * @param numSides Number of sides.
 * @param highest  Number of highest dices to keep.
 * @return The sum of the kept dices.
 */
int32_t rollPlayerStat(int32_t numDice, int32_t numSides, int32_t highest);
