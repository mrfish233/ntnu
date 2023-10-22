#pragma once

#include <stdio.h>
#include <stdint.h>

/**
 * Print the steps of tower of Hanoi.
 * n: the number of disks
 * source: the source rod
 * target: the target rod
 * spared: the spared rod
 */
void towerOfHanoi(int32_t n, int32_t source, int32_t target, int32_t spared);
