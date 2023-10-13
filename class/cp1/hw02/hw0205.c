#include <stdio.h>
#include <stdint.h>

/* 
 * Print the line in format "*---*" with different dash length
 */
void printLine(int32_t length) {
	printf("*");

	for (int32_t i = 0; i < length - 2; i++) {
		printf("-");
	}

	printf("*");
}

/* 
 * Print spaces in given length
 */
void printSpace(int32_t length) {
	for (int32_t i = 0; i < length; i++) {
		printf(" ");
	}
}

int main() {
	// Input variables
	int32_t layer = 0, length = 0;

	printf("Please input the length: ");
	scanf("%d", &length);

	printf("Please input the number of layer: ");
	scanf("%d", &layer);

	// Check island width
	int32_t longestWidth = 0;
	// First and last '*'
	longestWidth += 2;
	// An empty space with a line, repeat layer-1 times
	longestWidth += (layer - 1) * (2 * length + 2 * (length - 2));
	// Last empty space before '*'
	longestWidth += length + 2 * (length - 2);

	if (layer < 1) {
		printf("Error: number of layers is too small\n");
		return 1;
	} else if (length < 3) {
		printf("Error: length of an island is too small\n");
		return 1;
	} else if (longestWidth > 80) {
		printf("Error: the island is too big\n");
		return 1;
	}

	// Star lines
	int32_t starLines = ((4 * layer) - 1);
	int32_t starLineCount = 0;

	// Slash lines 
	int32_t slashLines = ((4 * layer) - 2) * (length - 2);

	// Total lines
	int32_t totalLines = starLines + slashLines;

	// Flag used to determine 2 situations
	int32_t flag = 1;

	// Loop every line
	for (int32_t line_i = 1; line_i <= totalLines; line_i++) {

		// Star line check
		int32_t isStarLine = 0;
		if ((line_i - 1) % (length - 1) == 0) {
			starLineCount++;
			isStarLine = 1;
		} else {
			isStarLine = 0;
		}

		// Repeat line is at middle of pattern
		int32_t isRepeatLine = 0;
		int32_t repeatLineCheck = (length - 1) * (layer - 1);
		if (line_i > repeatLineCheck && line_i < totalLines - repeatLineCheck + 1) {
			isRepeatLine = 1;
		} else {
			isRepeatLine = 0;
		}

		// Different repeat count used in non-repeat line
		int32_t nonRepeatLineDiff = 0;

		// Space length
		int32_t spaceLength = 0;

		// Different space length used in slash line
		int32_t spaceDiff = 0, backSlashSpaceLength = 0, forwSlashSpaceLength = 0;

		// Different line with different pattern
		// Repeat star line
		if (isRepeatLine && isStarLine) {
			// Change flag
			flag = !flag;

			// Space length is 1 full length and 2 length without '*'
			spaceLength = length + 2 * (length - 2);

			if (!flag) { // Space first
				// Print first spaces
				printSpace(length - 1);

				// Repeatedly print line then spaces by different layers
				for (int32_t j = 0; j < layer - 1; j++) {
					printLine(length);
					printSpace(spaceLength); 
				}

				// Print last line
				printLine(length);
			} else { // Star first
				// Print first '*'
				printf("*");

				// Repeatedly print spaces then line by different layers
				for (int32_t j = 0; j < layer - 1; j++) {
					printSpace(spaceLength);
					printLine(length);
				}

				// Print last spaces
				printSpace(spaceLength);

				// Print last '*'
				printf("*");
			} // Endif flag

		}
		// Repeat slash line
		else if (isRepeatLine && !isStarLine) {
			// Different space differnce with different line
			spaceDiff = ((line_i - 1) % (length - 1)) - 1;

			// Backslash space length
			backSlashSpaceLength = length + (2 * ((length - 2) - (spaceDiff + 1)));
			// Forward slash space length
			forwSlashSpaceLength = length + (2 * spaceDiff);

			if (!flag) { // Forward slash first
				// Print first spaces
				printSpace((length - 2)- spaceDiff);

				// Repeatedly print slash, blackslash and spaces by different layers
				for (int32_t j = 0; j < layer - 1; j++) {
					printf("/");
					printSpace(forwSlashSpaceLength);
					printf("\\");
					printSpace(backSlashSpaceLength);
				}

				// Print last slash, blackslash and spaces
				printf("/");
				printSpace(forwSlashSpaceLength);
				printf("\\");
			} else { // Back slash first
				// Print first spaces
				printSpace(spaceDiff + 1);

				// Repeatedly print slash, blackslash and spaces by different layers
				for (int32_t j = 0; j < layer - 1; j++) {
					printf("\\");
					printSpace(backSlashSpaceLength);
					printf("/");
					printSpace(forwSlashSpaceLength);
				}

				// Print last slash, blackslash and spaces
				printf("\\");
				printSpace(backSlashSpaceLength);
				printf("/");
			} // Endif flag

		}
		// Start/end star line
		else if (!isRepeatLine && isStarLine) {
			// Different repeat times with different star line 
			if (line_i <= repeatLineCheck) { // Start non-repeat lines
				nonRepeatLineDiff = starLineCount - 1;
			} else {
				nonRepeatLineDiff = (4 * layer) - starLineCount - 1;
			}

			// Print first spaces with amount of (length-1) lines
			spaceLength = (length - 1) * (2 * (layer - nonRepeatLineDiff) - 1);
			printSpace(spaceLength);

			// Repeatedly print line then spaces by different layers
			for (int32_t j = 0; j < nonRepeatLineDiff; j++) {
				printLine(length);

				spaceLength = length + 2 * (length - 2);
				printSpace(spaceLength);
			}

			// Print last line
			printLine(length);

		}
		// Start/end slash line
		else { 
			// Different repeat times with different star line 
			if (line_i <= repeatLineCheck) { // Start non-repeat lines
				nonRepeatLineDiff = starLineCount - 1;
			} else {
				nonRepeatLineDiff = (4 * layer) - starLineCount - 2;
			}

			// Different space differnce with different line
			spaceDiff = ((line_i - 1) % (length - 1)) - 1;

			// Backslash space length
			backSlashSpaceLength  = length + (2 * ((length - 2) - (spaceDiff + 1)));
			// Forward slash space length
			forwSlashSpaceLength = length + (2 * spaceDiff);

			if (line_i <= repeatLineCheck) { // Forward slash first
				// Print first spaces with amount of (length-1) lines - (space different + 1)
				spaceLength = (length - 1) * (2 * (layer - nonRepeatLineDiff) - 1) - (spaceDiff + 1);
				printSpace(spaceLength);

				// Repeatedly print slash, blackslash and spaces by different layers
				for (int32_t j = 0; j < nonRepeatLineDiff; j++) {
					printf("/");
					printSpace(forwSlashSpaceLength);
					printf("\\");
					printSpace(backSlashSpaceLength);
				}

				// Print last slash, blackslash and spaces
				printf("/");
				printSpace(forwSlashSpaceLength);
				printf("\\");
			} else { // Back slash first
				// Print first spaces with amount of (length-1) lines - (length - 2 - space different)
				spaceLength = (length - 1) * (2 * (layer - nonRepeatLineDiff) - 1) - (length - 2 - spaceDiff);
				printSpace(spaceLength);

				// Repeatedly print slash, blackslash and spaces by different layers
				for (int32_t j = 0; j < nonRepeatLineDiff; j++) {
					printf("\\");
					printSpace(backSlashSpaceLength);
					printf("/");
					printSpace(forwSlashSpaceLength);
				}

				// Print last slash, blackslash and spaces
				printf("\\");
				printSpace(backSlashSpaceLength);
				printf("/");
			} // Endif flag

		} // Endif repeat line and star line

		// Newline
		printf("\n");
	} /* End for loop */

	return 0;
}
