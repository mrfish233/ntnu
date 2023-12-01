#include "gsat_calculate.h"

void findSubjectGrade(int32_t subjectGrade[GRADE_NUM], int32_t subject, int32_t studentScore[][6], int32_t studentNumber) {
	int32_t *subjectScore = calloc(studentNumber, sizeof(int32_t));

	for (int32_t i = 0; i < studentNumber; i++) {
		subjectScore[i] = studentScore[i][subject];
	}

	for (int32_t i = 0; i < studentNumber - 1; i++) {
		for (int32_t j = i + 1; j < studentNumber; j++) {
			if (subjectScore[i] < subjectScore[j]) {
				int32_t temp    = subjectScore[i];
				subjectScore[i] = subjectScore[j];
				subjectScore[j] = temp;
			}
		}
	}

	double top12 = ceil(studentNumber * 0.12);
	double top25 = ceil(studentNumber * 0.25);
	double top50 = ceil(studentNumber * 0.50);
	double top75 = ceil(studentNumber * 0.75);
	double top88 = ceil(studentNumber * 0.88);

	subjectGrade[TOP_12] = subjectScore[(int32_t) top12 - 1];
	subjectGrade[TOP_25] = subjectScore[(int32_t) top25 - 1];
	subjectGrade[TOP_50] = subjectScore[(int32_t) top50 - 1];
	subjectGrade[TOP_75] = subjectScore[(int32_t) top75 - 1];
	subjectGrade[TOP_88] = subjectScore[(int32_t) top88 - 1];

	free(subjectScore);
}
