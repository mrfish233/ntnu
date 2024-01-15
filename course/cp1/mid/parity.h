#pragma once

// #include <stdio.h>
#include <stdint.h>

// Used only by parity_2d
uint64_t oddParity( int32_t );

// Compute the parity of 5 32-bit integers using 2D parity
uint64_t parity_2d( int32_t , int32_t , int32_t , int32_t , int32_t );
