#pragma once

#include <stdio.h>
#include <stdint.h>

/**
 * Print the steps of tower of Hanoi.
 * @param n The number of disks
 * @param source The source rod
 * @param target The target rod
 * @param spared The spared rod
 */
void towerOfHanoi(int32_t n, int32_t source, int32_t target, int32_t spared);
