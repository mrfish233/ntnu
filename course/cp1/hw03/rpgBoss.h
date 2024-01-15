#pragma once

#include <stdint.h>
#include "diceRolls.h"

/**
 * Initialize the boss.
 */
void rpgBossInit();

/**
 * End the boss.
 */
void rpgBossEnd();

/**
 * Get the boss's health.
 * @return The boss's health. -1 if the boss is not initialized.
 */
int32_t rpgBossGetHealth();

/**
 * Get the boss's damage.
 * @return The boss's damage. -1 if the boss is not initialized.
*/
int32_t rpgBossGetDamage();

/**
 * Get the boss's action.
 * @return The boss's action. -1 if the boss is not initialized.
 */
int32_t rpgBossGetAction();

/**
 * Check if the boss is initialized.
 * @return 1 if the boss is initialized, 0 otherwise.
 */
int32_t rpgBossIsInitialized();

/**
 * Update the boss's health.
 * @param newHealth The new health value.
 */
void rpgBossUpdateHealth(int32_t newHealth);

/**
 * Update the boss's next action.
*/
void rpgBossUpdateAction();
