#include <stdio.h>
#include <stdint.h>

int32_t isLeapYear(uint64_t year) {
	if (year % 400 == 0) return 1;
	if (year % 100 == 0) return 0;
	if (year % 4 == 0) return 1;
	return 0;
}

uint64_t getDaysInYear(uint64_t year) {
	if (isLeapYear(year)) return 366;
	return 365;
}

uint64_t getDaysInMonth(uint64_t year, uint64_t month) {
	if (month == 2) {
		if (isLeapYear(year)) return 29;
		return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}

int32_t checkValidDate(uint64_t year, uint64_t month, uint64_t day) {
	if (month < 1 || month > 12) return 0;
	if (day < 1 || day > getDaysInMonth(year, month)) return 0;
	return 1;
}

int32_t checkValidTime(uint64_t hour, uint64_t min, uint64_t sec) {
	if (hour > 23) return 0;
	if (min > 59) return 0;
	if (sec > 59) return 0;
	return 1;
}

int main() {
	uint64_t startYear  = 0, endYear  = 0;
	uint64_t startMonth = 0, endMonth = 0;
	uint64_t startDay   = 0, endDay   = 0;
	uint64_t startHour  = 0, endHour  = 0;
	uint64_t startMin   = 0, endMin   = 0;
	uint64_t startSec   = 0, endSec   = 0;

	printf("Start time: ");
	scanf("%ld-%ld-%ld %ld:%ld:%ld", &startYear, &startMonth, &startDay, &startHour, &startMin, &startSec);

	printf("End time: ");
	scanf("%ld-%ld-%ld %ld:%ld:%ld", &endYear, &endMonth, &endDay, &endHour, &endMin, &endSec);

	// Check datetime is valid
	if (!checkValidDate(startYear, startMonth, startDay)) {
		printf("Error: start date is incorrect\n");
		return 0;
	}
	if (!checkValidTime(startHour, startMin, startSec)) {
		printf("Error: start time is incorrect\n");
		return 0;
	}
	if (!checkValidDate(endYear, endMonth, endDay)) {
		printf("Error: end date is incorrect\n");
		return 0;
	}
	if (!checkValidTime(endHour, endMin, endSec)) {
		printf("Error: end time is incorrect\n");
		return 0;
	}

	// Check input is valid
	if (startYear > endYear) {
		printf("Error: date range is incorrect\n");
		return 0;
	}
	if (startYear == endYear && startMonth > endMonth) {
		printf("Error: date range is incorrect\n");
		return 0;
	}
	if (startYear == endYear && startMonth == endMonth && startDay > endDay) {
		printf("Error: date range is incorrect\n");
		return 0;
	}
	if (startYear == endYear && startMonth == endMonth && startDay == endDay && startHour > endHour) {
		printf("Error: date range is incorrect\n");
		return 0;
	}
	if (startYear == endYear && startMonth == endMonth && startDay == endDay && startHour == endHour && startMin > endMin) {
		printf("Error: date range is incorrect\n");
		return 0;
	}
	if (startYear == endYear && startMonth == endMonth && startDay == endDay && startHour == endHour && startMin == endMin && startSec > endSec) {
		printf("Error: date range is incorrect\n");
		return 0;
	}

	// Calculate total seconds
	uint64_t totalSec = 0;

	// Calculate if same day
	if (startYear == endYear && startMonth == endMonth && startDay == endDay) {
		totalSec = endHour * 3600 + endMin * 60 + endSec - (startHour * 3600 + startMin * 60 + startSec);
	} else {
		// Calculate total seconds in only start datetime and only end datetime
		uint64_t startDateTimeSec = 86400 - (startHour * 3600 + startMin * 60 + startSec);
		uint64_t endDateTimeSec   = endHour * 3600 + endMin * 60 + endSec;

		totalSec = startDateTimeSec + endDateTimeSec;

		startDay += 1;
		if (startDay > getDaysInMonth(startYear, startMonth)) {
			startDay = 1;
			startMonth += 1;
			if (startMonth > 12) {
				startMonth = 1;
				startYear += 1;
			}
		}

		// if same month and year
		if (startYear == endYear && startMonth == endMonth) {
			uint64_t days = endDay - startDay;
			totalSec += days * 86400;
		} else {
			// if same year
			if (startYear == endYear) {
				uint64_t startYearDays = 0;
				uint64_t endYearDays   = 0;
				uint64_t totalDays     = 0;

				for (uint64_t i = 1; i < startMonth; i++) {
					startYearDays += getDaysInMonth(startYear, i);
				}
				startYearDays += startDay;

				for (uint64_t i = 1; i < endMonth; i++) {
					endYearDays += getDaysInMonth(endYear, i);
				}
				endYearDays += endDay;

				totalDays = endYearDays - startYearDays;
				totalSec += totalDays * 86400;

			} else {
				// if not same year
				uint64_t startYearDays = 0;
				uint64_t endYearDays   = 0;

				for (uint64_t i = 12; i > startMonth; i--) {
					startYearDays += getDaysInMonth(startYear, i);
				}
				startYearDays += getDaysInMonth(startYear, startMonth) - startDay + 1;

				totalSec += startYearDays * 86400;

				for (uint64_t i = 1; i < endMonth; i++) {
					endYearDays += getDaysInMonth(endYear, i);
				}
				endYearDays += endDay;

				totalSec += endYearDays * 86400;

				for (uint64_t i = startYear + 1; i < endYear; i++) {
					totalSec += getDaysInYear(i) * 86400;
				}
			}
		}

		// uint64_t startYearDays = 0;
		// uint64_t endYearDays   = 0;

		// for (int32_t i = 12; i > startMonth; i--) {
		// 	startYearDays += getDaysInMonth(startYear, i);
		// }
		// startYearDays += getDaysInMonth(startYear, startMonth) - startDay + 1;

		// totalSec += startYearDays * 86400;

		// for (int32_t i = 1; i < endMonth; i++) {
		// 	endYearDays += getDaysInMonth(endYear, i);
		// }
		// endYearDays += endDay;

		// totalSec += endYearDays * 86400;

		// for (int32_t i = startYear + 1; i < endYear; i++) {
		// 	totalSec += getDaysInYear(i) * 86400;
		// }
	}

	printf("Duration: %ld\n", totalSec);

	return 0;
}
