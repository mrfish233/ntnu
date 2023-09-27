#include <stdio.h>
#include <stdint.h>

/*
 * Bounded Area
 */
int main()
{
	// Input points
	int32_t x1 = 0, y1 = 0;
	int32_t x2 = 0, y2 = 0;
	
	// equation's value
	float dx = 0, dy = 0;
	float gradient = 0, y_intercept = 0;
	float area = 0;

	// Scan two points
	printf("Please enter the point A (x,y): ");
	scanf("%d,%d", &x1, &y1);
	printf("Please enter the point B (x,y): ");
	scanf("%d,%d", &x2, &y2);

	// Check points if there is no bounded area
	// If the line is parallel to x-axis or y-axis
	if (x1 == x2 || y1 == y2)
	{
		printf("Area: 0\n");
		return 1;
	}

	// If y_intercept of the line is at origin
	if (x1 * y2 == y1 * x2)
	{
		printf("Area: 0\n");
		return 1;
	}

	// Calculate dx and dy
	dx = (float) x2 - x1;
	dy = (float) y2 - y1;
	
	// Calculate gradient and y_intercept
	gradient    = dy / dx;
	y_intercept = (float) y1 - gradient * x1; 

	// Calculate and print the area
	area = y_intercept * y_intercept / gradient / 2.0;

	// Make sure the area is positive
	if (area < 0)
	{
		area = -area;
	}

	printf("Area: %.2f\n", area);

	return 0;
}

