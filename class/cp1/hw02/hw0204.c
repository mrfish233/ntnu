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
	if (initialInvest < 1 || initialInvest > 10000000) {
		printf("Error: initial investment is out of range\n");
		return 1;
	}

	if (monthInvest < 0 || monthInvest > 10000000) {
		printf("Error: recurring monthly investment is out of range\n");
		return 1;
	}

	if (startYear < 1 || startYear > 10000 || startMonth < 1 || startMonth > 12 || 
		endYear   < 1 || endYear   > 10000 || endMonth   < 1 || endMonth   > 12) {
		printf("Error: incorrect date format\n");
		return 1;
	}

	if (startYear > endYear || (startYear == endYear && startMonth >= endMonth)) {
		printf("Error: incorrect date range\n");
		return 1;
	}

	if (annualRate < 1 || annualRate > 100) {
		printf("Error: annual rate is out of range\n");
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
	if (month < 10) {
		printf("%d.0%d) ", year, month);
	} else {
		printf("%d.%d) ",  year, month);
	}
	printf("%.0f/%.0f/%.0f/%.0f%%\n", 
			totalInvest, futureValue, totalInterest, rateOfReturn);

	// Loop month
	// while ( !((year == endYear     && month == endMonth - 1) ||
	// 		  (year == endYear - 1 && month == 12 && endMonth == 1)) ) {
	int32_t start = startYear * 12 + startMonth;
	int32_t end   = endYear   * 12 + endMonth;
	for (int32_t i = start; i < end - 1; i++) {
		// Move to next month
		month += 1;
		if (month > 12) {
			year  += 1;
			month -= 12;
		}

		// First calculate interest by last month's future value
		monthInterest  = futureValue * monthRate;

		// Update total investment
		totalInvest   += monthInvest;

		// Update total interest
		totalInterest += monthInterest;

		// Update future value
		futureValue   += monthInvest + monthInterest;

		// Calculate rate of return
		rateOfReturn   = totalInterest / futureValue * 100;

		// Print the result
		double max = 1000000000000000.0;
		if (totalInvest >= max || totalInterest >= max || futureValue >= max) {
			printf("*/*/*/*%%\n");
		} else {
			// Print year and month with leading zero
			printf("%d.%02d) ",  year, month);

			// Print total investment, future value and total interest
			printf("%ld/%ld/%ld/", 
				(int64_t) totalInvest, (int64_t) futureValue, (int64_t) totalInterest);

			// Print rate of return without trailing zero
			int32_t precision = 0;
			if (rateOfReturn >= 10.0) {
				precision = 4;
			} else if (rateOfReturn >= 1.0) {
				precision = 3;
			} else {
				precision = 2;
			}
			printf("%.*g%%\n", precision, rateOfReturn);
		}
	} // End while loop

	return 0;
}
