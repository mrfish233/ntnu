#pragma once

#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"
#include "rpgPlayer.h"
#include "rpgStory.h"

/**
 * Start a new game
 */
void rpgEventStartGame();

/**
 * Handle the process of the game
 */
void rpgEventGameProcess();
