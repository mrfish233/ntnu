#pragma once

#include <stdint.h>

#define STUDENT_NUMBER (10)
#define CHINESE (0)
#define ENGLISH (1)
#define MATH_A  (2)
#define MATH_B  (3)
#define SOCIAL  (4)
#define SCIENCE (5)

int32_t score[][6] = {
	{ 15, 15, 15,  0, 15, 15 },
	{ 14, 14, 15,  0, 15, 10 },
	{ 12, 13, 15,  0, 15, 10 },
	{  9, 12, 15,  0, 15, 10 },
	{ 15, 11, 15,  0,  5, 15 },
	{ 15, 10, 15,  0,  5, 15 },
	{  7,  9, 15,  0,  5,  7 },
	{  6,  8, 15,  0,  5,  7 },
	{  5,  7, 15,  0,  5,  7 },
	{ 10,  6, 15,  0,  5,  7 }
};
