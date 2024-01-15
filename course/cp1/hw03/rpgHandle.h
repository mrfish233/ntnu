#pragma once

#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"
#include "rpgPlayer.h"

/**
 * Handles the player status of the RPG game.
 * @return -1 if the player is dead or insane, 0 otherwise.
 */
int32_t rpgHandleStatus();

/**
 * Handles the player's health.
 * @param numDices The number of dices to roll. If less than 0, the player will lose health.
 * @param sides The number of sides of the dices.
 * @param value The value to add to the result of the roll.
 * @return -1 if the player is dead, 0 otherwise.
 */
int32_t rpgHandleHealth(int32_t numDices, int32_t sides, int32_t value);

/**
 * Handles the player's sanity.
 * @param numDices The number of dices to roll. If less than 0, the player will lose sanity.
 * @param sides The number of sides of the dices.
 * @param value The value to add to the result of the roll.
 * @return -1 if the player is insane, 0 otherwise.
 */
int32_t rpgHandleSanity(int32_t numDices, int32_t sides, int32_t value);

/**
 * Handles the player's attributes.
 * @param attribute The attribute to modify.
 * @param value The value to add to the attribute.
 */
void rpgHandleAttribute(int32_t attribute, int32_t value);

/**
 * Handles the player's inventory.
 * @param index The index of the item in the inventory.
 * @param value The value to add to the item.
 */
void rpgHandleInventory(int32_t index, int32_t value);
