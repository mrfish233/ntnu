#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define STUDENT_ID  0
#define STUDENT_SUM 1

#define SUBJECT_NUM 6
#define GRADE_NUM   5

#define TOP_12 0
#define TOP_25 1
#define TOP_50 2
#define TOP_75 3
#define TOP_88 4

/**
 * Find the subject's grade. Grade standard: 12%, 25%, 50%, 75%, 88%
 * @param subjectGrade The array of a subject's grade
 * @param subject The subject
 * @param studentScore The array of all students scores
 * @param studentNumber The number of students
 */
void findSubjectGrade(int32_t subjectGrade[GRADE_NUM], int32_t subject,
	int32_t studentScore[][6], int32_t studentNumber);
