#include <stdio.h>
#include <stdint.h>

/* 
 * Print separate line by given length
 */
void printSeparateLine(int32_t len) {
	if (len < 0) return;

	for (int32_t i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
}

/* 
 * Print spaces by given length
 */
void printSpace(int32_t len) {
	if (len < 0) return;

	for (int32_t i = 0; i < len; i++) {
		printf(" ");
	}
}

/* 
 * Calculate digit of number
 */
int64_t digitCount(int64_t num) {
	int64_t digit = 1;

	while (num >= 10) {
		num /= 10;
		digit++;
	}
	
	return digit;
}

/* 
 * Calculate power of ten by digit
 */
int64_t powerOfTen(int64_t digit) {
	int64_t power = 1;

	for (int64_t i = 0; i < digit - 1; i++) {
		power *= 10;
	}

	return power;
}

/* 
 * Print number with given format
 */
void printFormatNum(int64_t num) {
	int64_t digit = digitCount(num);
	int64_t pow10 = powerOfTen(digit);
	int64_t currDigit = 0;

	for (int64_t i = 0; i < digit; i++) {
		currDigit = num / pow10;

		printf("%ld", currDigit);
		if (i != digit - 1) {
			printSpace(1);
		}

		num   -= currDigit * pow10;
		pow10 /= 10;
	}
	printf("\n");
}

int main() {
	int64_t num1  = 0, num2 = 0;
	int64_t total = 0;

	printf("Please enter the first  number: ");
	scanf("%ld", &num1);

	printf("Please enter the second number: ");
	scanf("%ld", &num2);

	if (num1 < 0 || num1 > INT32_MAX || num2 < 0 || num2 > INT32_MAX) {
		printf("Error: number is out of range\n");
		return 1;
	}

	/* 
	 * Calculation
	 */

	total = num1 * num2;

	// Find digits
	int64_t num1Digit = 0, num2Digit = 0, totalDigit = 0;

	num1Digit  = digitCount(num1);
	num2Digit  = digitCount(num2);
	totalDigit = digitCount(total);

	// Find max digit
	int64_t maxDigit = 0;
	if (num1Digit > num2Digit) {
		maxDigit = num1Digit > totalDigit ? num1Digit : totalDigit;
	} else {
		maxDigit = num2Digit > totalDigit ? num2Digit : totalDigit;
	}

	// Total width
	int64_t width = 2 * maxDigit + 1;

	/* 
	 * Print the result
	 */

	// Print num1
	printSpace(width - 2 * num1Digit + 1); 
	printFormatNum(num1);

	// Print num2
	printf("*)");
	printSpace(width - 2 * num2Digit + 1 - 2); // 2 spaces for "*)"
	printFormatNum(num2);

	// Print separate line
	printSeparateLine(width);

	// Print the process
	if (num2 >= 10 && total != 0) {
		int64_t tempNum2  = num2;
		int64_t tempTotal = 0, tempTotalDigit = 0;

		for (int64_t i = 0; i < num2Digit; i++) {
			tempTotal = num1 * (tempNum2 % 10);
			tempTotalDigit = digitCount(tempTotal);
			tempNum2 /= 10;

			printSpace(width - 2 * tempTotalDigit - 2 * i + 1);
			printFormatNum(tempTotal);
		}

		printSeparateLine(width);
	}

	// Print total
	printSpace(width - 2 * totalDigit + 1);
	printFormatNum(total);

	return 0;
}

