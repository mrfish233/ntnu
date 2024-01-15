#pragma once

#include <stdio.h>
#include <stdint.h>

// Setup weights for boys and girls
void setup_girl_weight( uint32_t );
void setup_boy_weight( uint32_t );

// Calculate the weight that the member at (x,y) should bear.
// If there is any error inputs or weights are not initialized , return -1.
int64_t afford_weight( int32_t x, int32_t y );
