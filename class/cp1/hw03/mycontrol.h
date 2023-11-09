#pragma once

#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 * Setup the initial position to (x,y) and the moving direction.
 * @param x The initial x position.
 * @param y The initial y position.
 * @param a The initial angle counterclockwise from the x axis.
 */
void initialize(double x, double y, double a);

/**
 * Convert the angle to the range [0, 2*PI).
 */
void convert_angle();

/**
 * Move forward by the given distance.
 * @param length The distance to move forward.
 * @return 0 if the move is successful, -1 if initial position is invalid.
 */
int32_t forward(double length);

/**
 * Turn clockwise by the given angle.
 * @param angle The angle to turn clockwise.
 * @return 0 if the turn is successful, -1 if initial position is invalid.
 */
int32_t clock_turn(double angle);

/**
 * Turn counterclockwise by the given angle.
 * @param angle The angle to turn counterclockwise.
 * @return 0 if the turn is successful, -1 if initial position is invalid.
 */
int32_t counterclock_turn(double angle);

/**
 * Print the current position and direction.
 * Print format: "position: (x,y), angle: a", 0 <= a <= 2 * pi.
 * @return 0 if the print is successful, -1 if initial position is invalid.
 */
int32_t print(void);
