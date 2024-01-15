#include <stdio.h>
#include <stdint.h>

void printSpace(int64_t length) {
	for (int64_t i = 0; i < length; i++) {
		printf(" ");
	}
}

void printLine(int64_t length, int64_t repeat) {
	for (int64_t i = 0; i < length; i++) {
		if (i % repeat == 0) {
			printf("+");
		} else {
			printf("-");
		}
	}
}

void printLineColor(int64_t length, int64_t repeat, int64_t color) {
	for (int64_t i = 0; i < length; i++) {
		if (i % repeat == 0) {
			printf("|");
		} else {
			// Print empty space with color
			printf("\033[0;%ldm \033[0m", color);
		}
	}
}

int main() {
	int64_t n = 0, l = 0;

	printf("Please enter n: ");
	scanf("%ld", &n);

	printf("Please enter the edge length: ");
	scanf("%ld", &l);

	if (n < 1 || l < 1) {
		printf("Invalid input\n");
		return 0;
	}

	int64_t width = 2 * l + 2;
	int64_t height = l + 2;

	// Print top
	for (int64_t i = 0; i < n; i++) {
		
		// Loop height times
		for (int64_t j = 0; j < height - 1; j++) {

			// Print space
			printSpace((width - 1) * (n - i - 1));

			if (j == 0) {
				// Print line
				printLine((width - 1)* (2 * i + 1) + 1, width - 1);
			} else {
				// Loop color in red->green->blue
				int64_t color = 41;
				for (int64_t k = 0; k < i + 1; k++) {
					printLineColor(width - 1, width - 1, color);

					if (color == 41) {
						color = 42;
					} else if (color == 42) {
						color = 44;
					} else {
						color = 41;
					}
				}

				if (color == 41) {
					color = 42;
				} else if (color == 42) {
					color = 44;
				} else {
					color = 41;
				}

				for (int64_t k = 0; k < i; k++) {
					printLineColor(width - 1, width - 1, color);

					if (color == 41) {
						color = 44;
					} else if (color == 44) {
						color = 42;
					} else {
						color = 41;
					}
				}

				printLineColor(1, 1, 0);
			}

			printf("\n");
		}
	}

	// Print bottom
	for (int64_t i = 0; i < n; i++) {

		// Skip first line
		if (i == 0) {
			continue;
		}
		
		// Loop height times
		for (int64_t j = 0; j < height - 1; j++) {
			if (j == 0) {
				// Print space
				printSpace((width - 1) * (i - 1));

				// Print line
				printLine((width - 1) * (2 * (n - i) - 1) + 1 + 2 * (width - 1), width - 1);
			} else {
				// Print space
				printSpace((width - 1) * i);

				// Loop color in red->green->blue
				int64_t color = 41;
				for (int64_t k = 0; k < n - i; k++) {
					printLineColor(width - 1, width - 1, color);

					if (color == 41) {
						color = 42;
					} else if (color == 42) {
						color = 44;
					} else {
						color = 41;
					}
				}

				if (color == 41) {
					color = 42;
				} else if (color == 42) {
					color = 44;
				} else {
					color = 41;
				}

				for (int64_t k = 0; k < n - i - 1; k++) {
					printLineColor(width - 1, width - 1, color);

					if (color == 41) {
						color = 44;
					} else if (color == 44) {
						color = 42;
					} else {
						color = 41;
					}
				}

				printLineColor(1, 1, 0);
			}

			printf("\n");
		}
	}

	// Print last line
	printSpace((width - 1) * (n - 1));
	printLine(width, width - 1);
	printf("\n");

	return 0;
}
