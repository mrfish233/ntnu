#include <stdio.h>
#include <stdint.h>

/*
 * Full Multiplication
 */
int main()
{
	// Input numbers
	int32_t number1 = 0, number2 = 0;
	// Total
	int32_t total = 0;
	// Place value of a number
	int32_t ones = 0, tens = 0, hundreds = 0, thousands = 0;

	// Scan and check the first number
	printf("Please enter the first  number: ");
	scanf("%d", &number1);

	if (number1 < 0 || number1 > 99)
	{
		printf("Wrong input, your input must between 0 ~ 99.\n");
		return 0;
	}

	// Scan and check the second number
	printf("Please enter the second number: ");
	scanf("%d", &number2);
	
	if (number2 < 0 || number2 > 99)
	{
		printf("Wrong input, your input must between 0 ~ 99.\n");
		return 0;
	}

	// Multiply the numbers
	total = number1 * number2;

	// Print the result directly if number2 < 10
	if (number2 < 10)
	{
		// Print different pattern by checking the value of total
		if (total < 10 && number1 < 10)
		{
			// Print in length of 3
			printf("  %d\n", number1);
			printf("*)%d\n", number2);
			printf("---\n");
			printf("  %d\n", total);
		}
		else if (total < 100)
		{
			// Print in length of 5
			// Check and print number1
			if (number1 < 10)
			{
				printf("    %d\n", number1);
			}
			else
			{
				tens = number1 / 10;
				ones = number1 % 10;
				
				printf("  %d %d\n", tens, ones);
			}

			// Print number2
			printf("*)  %d\n", number2);
			
			printf("-----\n");
			
			// Check and print total
			if (total == 0)
			{
				// Print out directly if total == 0
				printf("    %d\n", total);
			}
			else
			{
				tens = total / 10;
				ones = total % 10;

				printf("  %d %d\n", tens, ones);
			}
		}
		else // total < 1000
		{
			// Print in length of 7
			// Print number1
			tens = number1 / 10;
			ones = number1 % 10;
			
			printf("    %d %d\n", tens, ones);
			
			// Print number2
			printf("*)    %d\n", number2);
			
			printf("-------\n");

			// Print total
			hundreds = total / 100;
			tens     = total / 10 % 10;
			ones     = total % 10;
			
			printf("  %d %d %d\n", hundreds, tens, ones);
		}
		// Endif total check
	}
	else // If number2 >= 10
	{
		// Print the process before printing the result
		// Temporary result to print multiplcation process
		int32_t tens_result = 0, ones_result = 0;
		
		tens_result = number1 * (number2 / 10);
		ones_result = number1 * (number2 % 10);

		// Print different pattern by checking the value of total
		if (total < 100)
		{
			// Print in length of 5
			// Check and print number1
			if (number1 < 10)
			{
				printf("    %d\n", number1);
			}
			else
			{
				tens = number1 / 10;
				ones = number1 % 10;

				printf("  %d %d\n", tens, ones);
			}

			// Print number2
			tens = number2 / 10;
			ones = number2 % 10;

			printf("*)%d %d\n", tens, ones);
			
			printf("-----\n");

			// Don't print process if total == 0
			if (total == 0)
			{
				printf("    %d\n", total);
			}
			else
			{	
				// Print ones_result
				if (ones_result < 10)
				{
					printf("    %d\n", ones_result);
				}
				else
				{
					tens = ones_result / 10;
					ones = ones_result % 10;

					printf("  %d %d\n", tens, ones);
				}
				// Print tens_result
				// As total < 100, therefore tens_result < 10
				printf("  %d  \n", tens_result);
			
				printf("-----\n");
				
				// Print total
				tens = total / 10;
				ones = total % 10;

				printf("  %d %d\n", tens, ones);
			}
		}
		else if (total < 1000)
		{
			// Print in length of 7
			// Check and print number1
			if (number1 < 10)
			{
				printf("      %d\n", number1);
			}
			else
			{
				tens = number1 / 10;
				ones = number1 % 10;

				printf("    %d %d\n", tens, ones);
			}

			// Print number2
			tens = number2 / 10;
			ones = number2 % 10;

			printf("*)  %d %d\n", tens, ones);

			printf("-------\n");

			// Check and print ones_result
			if (ones_result < 10)
			{
				printf("      %d\n", ones_result);
			}
			else if (ones_result < 100)
			{
				tens = ones_result / 10;
				ones = ones_result % 10;

				printf("    %d %d\n", tens, ones);
			}
			else
			{
				hundreds = ones_result / 100;
				tens     = ones_result / 10 % 10;
				ones     = ones_result % 10;

				printf("  %d %d %d\n", hundreds, tens, ones);
			}

			// Check and print tens_result
			if (tens_result < 10)
			{
				printf("    %d\n", tens_result);
			}
			else
			{
				tens = tens_result / 10;
				ones = tens_result % 10;

				printf("  %d %d\n", tens, ones);
			}

			printf("-------\n");

			// Print total
			hundreds = total / 100;
			tens     = total / 10 % 10;
			ones     = total % 10;

			printf("  %d %d %d\n", hundreds, tens, ones);
		}
		else // total < 10000
		{
			// Print in length of 9
			// Print number1
			tens = number1 / 10;
			ones = number1 % 10;

			printf("      %d %d\n", tens, ones);

			// Print number2
			tens = number2 / 10;
			ones = number2 % 10;

			printf("*)    %d %d\n", tens, ones);

			printf("---------\n");

			// Check and print ones_result
			if (ones_result == 0)
			{
				printf("        %d\n", ones_result);
			}
			else if (ones_result < 100)
			{
				tens = ones_result / 10;
				ones = ones_result % 10;

				printf("      %d %d\n", tens, ones);
			}
			else
			{
				hundreds = ones_result / 100;
				tens     = ones_result / 10 % 10;
				ones     = ones_result % 10;

				printf("    %d %d %d\n", hundreds, tens, ones);
			}

			// Check and print tens_result
			if (tens_result < 100)
			{
				tens = tens_result / 10;
				ones = tens_result % 10;

				printf("    %d %d\n", tens, ones);
			}
			else
			{
				hundreds = tens_result / 100;
				tens     = tens_result / 10 % 10;
				ones     = tens_result % 10;

				printf("  %d %d %d\n", hundreds, tens, ones);
			}

			printf("---------\n");

			// Print total
			thousands = total / 1000;
			hundreds  = total / 100 % 10;
			tens      = total / 10  % 10;
			ones      = total % 10;

			printf("  %d %d %d %d\n", thousands, hundreds, tens, ones);
		}
		// Endif total check
	}

	return 0;
}

