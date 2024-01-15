#include "rpgBoss.h"

// Boss struct
static struct Boss {
	int32_t health;
	int32_t damage;

	enum bossAction {
		ACTION_REST,
		ACTION_CHARGE,
		ACTION_ATTACK,
		ACTION_MAGIC,
	} action;
} gBoss;

static int32_t initFlag = 0;

void rpgBossInit() {
	if (initFlag) {
		return;
	}

	// Initialize the boss
	gBoss.health = 5;
	gBoss.damage = 0;

	gBoss.action = ACTION_REST;

	// Set the init flag
	initFlag = 1;
}

void rpgBossEnd() {
	// Reset the init flag
	initFlag = 0;
}

int32_t rpgBossGetHealth() {
	// Return -1 if the boss is not initialized
	if (!rpgBossIsInitialized()) {
		return -1;
	}

	// Return the health
	return gBoss.health;
}

int32_t rpgBossGetDamage() {
	// Return -1 if the boss is not initialized
	if (!rpgBossIsInitialized()) {
		return -1;
	}

	// Return the damage
	return gBoss.damage;
}

int32_t rpgBossGetAction() {
	// Return -1 if the boss is not initialized
	if (!rpgBossIsInitialized()) {
		return -1;
	}

	// Return the action
	return gBoss.action;
}

int32_t rpgBossIsInitialized() {
	// Return the init flag
	return initFlag;
}

void rpgBossUpdateHealth(int32_t newHealth) {
	// Return if the boss is not initialized
	if (!rpgBossIsInitialized()) {
		return;
	}

	gBoss.health = newHealth;
}

void rpgBossUpdateAction() {
	// Return if the boss is not initialized
	if (!rpgBossIsInitialized()) {
		return;
	}

	if (gBoss.action == ACTION_REST) {
		gBoss.action = ACTION_CHARGE;
	} else if (gBoss.action == ACTION_CHARGE) {
		gBoss.action = ACTION_ATTACK;

		// Damage 2d3 + 2
		gBoss.damage = rollDices(2, 3) + 2;
	} else if (gBoss.action == ACTION_ATTACK) {
		gBoss.action = ACTION_MAGIC;
	} else {
		gBoss.action = ACTION_REST;
	}
}
