#include <stdio.h>
#include <stdint.h>

int main() {
	// Investment variables
	double initialInvest = 0, monthInvest = 0;
	// Date variables
	int32_t startMonth = 0, startYear = 0, endMonth = 0, endYear = 0;
	// Annual rate variable
	double annualRate = 0;

	/* 
	 * Inputs
	 */

	// Investment
	printf("Initial Investment:           ");
	scanf("%lf", &initialInvest);

	printf("Recurring Monthly Investment: ");
	scanf("%lf", &monthInvest);

	// Start and end of date
	printf("Start Month:                  ");
	scanf("%d", &startMonth);

	printf("Start Year:                   ");
	scanf("%d", &startYear);

	printf("End Month:                    ");
	scanf("%d", &endMonth);

	printf("End Year:                     ");
	scanf("%d", &endYear);

	// Annual rate
	printf("Annual Rate of Return (%%):    ");
	scanf("%lf", &annualRate);

	// Error check
	if ((initialInvest == 0 && monthInvest == 0) ||
		 initialInvest  < 0 || monthInvest  < 0) {
		printf("Error: incorrect investment\n");
		return 1;
	}

	if (startYear < 0 || startMonth < 0 || startMonth > 12 || 
		endYear   < 0 || endMonth   < 0 || endMonth   > 12) {
		printf("Error: incorrect date\n");
		return 1;
	}

	if (startYear > endYear || (startYear == endYear && startMonth > endMonth)) {
		printf("Error: incorrect date range\n");
		return 1;
	}

	if (annualRate <= 0) {
		printf("Error: incorrect annual rate\n");
		return 1;
	}

	/* 
	 * Data
	 */

	// Date
	int32_t year  = startYear;
	int32_t month = startMonth;
	
	// Interest and future value
	double totalInvest   = initialInvest;
	double futureValue   = initialInvest;
	double monthInterest = 0;
	double totalInterest = 0;
	double rateOfReturn  = 0;

	// Monthly rate
	double monthRate = annualRate / 12.0 / 100;

	/* 
	 * Output
	 */

	printf("--- Output ---\n");

	// Print first month
	printf("%d.%2d) %.0f/%.0f/%.0f/%.0f%%\n", 
			year, month, totalInvest, futureValue, totalInterest, rateOfReturn);

	// Loop month
	while (!(year == endYear && month == endMonth)) {
		// Move to next month
		month += 1;
		if (month > 12) {
			year  += 1;
			month -= 12;
		}

		monthInterest = totalInvest * monthRate;
		
		totalInvest   += monthInvest;
		totalInterest += monthInterest;
		futureValue   += monthInvest + monthInterest;

		rateOfReturn  = totalInterest / futureValue * 100;

		// Print the result
		printf("%d.%2d) %.0f/%.0f/%.0f/%.2f%%\n", 
				year, month, totalInvest, futureValue, totalInterest, rateOfReturn);
	} // End while loop

	return 0;
}
