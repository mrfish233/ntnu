#pragma once

#include <stdio.h>
#include <stdint.h>

/**
 * Sort array according to the given policy:
 * 1. All even numbers should be before odd numbers.
 * 2. All odd numbers are in ascending order.
 * 3. All even numbers are in descending order.
 * @param array The array to be sorted.
 * @param size Size of array.
 */
void mysort(int32_t array[], int32_t size);

/**
 * Print array elements in order.
 * @param array The array to be sorted.
 * @param size Size of array.
 */
void myprint(int32_t array[], int32_t size);
