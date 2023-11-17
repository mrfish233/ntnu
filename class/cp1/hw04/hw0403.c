#include <stdio.h>
#include <stdint.h>
#include "gsat.h"
#include "gsat_calculate.h"

int main() {
	int32_t subjectsGrade[SUBJECT_NUM][GRADE_NUM] = {0};

	for (int32_t i = 0; i < SUBJECT_NUM; i++) {
		findSubjectGrade(subjectsGrade[i], i, score, STUDENT_NUMBER);
	}

	printf("\tCHINESE | ENGLISH | MATH_A  | MATH_B  | SOCIAL  | SCIENCE\n");

	for (int32_t i = 0; i < GRADE_NUM; i++) {
		switch (i) {
			case 0: printf("TOP 12%%"); break;
			case 1: printf("TOP 25%%"); break;
			case 2: printf("TOP 50%%"); break;
			case 3: printf("TOP 75%%"); break;
			case 4: printf("TOP 88%%"); break;
			default: break;
		}

		for (int32_t j = 0; j < SUBJECT_NUM; j++) {
			printf("    %2d", subjectsGrade[j][i]);

			if (j != SUBJECT_NUM - 1) {
				printf("    ");
			}
		}
		printf("\n");
	}

	return 0;
}
