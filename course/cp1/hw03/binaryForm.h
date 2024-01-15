#pragma once

#include <stdio.h>
#include <stdint.h>

/**
 * Print the binary form of the given 32-bit integer by recursion
 * @param val the given integer
 * @param pos the position of the bit to be printed, MSB is 1, LSB is 32
 */
void BinaryForm(uint32_t val, int32_t pos);
