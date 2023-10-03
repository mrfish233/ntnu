#include <stdio.h>
#include <stdint.h>

int main() {
	// Readed variables
	int32_t emailLocalReaded = 0, emailDomainReaded = 0;
	int32_t subjectCategoryReaded = 0, subjectTitleReaded = 0;
	int32_t hwNum = 0, pNum = 0;
	uint64_t contentScore = 0;

	// Validate variables
	uint64_t subjectTitleScore = 0;
	int32_t isEmailPassed = 0, isSubjectPassed = 0, isContentScorePassed = 0;

	// Assign variables
	int32_t assignTA = 0;

	/*
	 * Inputs 
	 */

	/* Scan email input*/
	printf("Please enter the sender address      > ");

	// Validate email local
	scanf("%*[a-zA-Z0-9]@%n", &emailLocalReaded);

	// Validate email domain
	if (emailLocalReaded != 0) {
		scanf("csie.cool%n", &emailDomainReaded);
		scanf("ntnu.edu.tw%n", &emailDomainReaded);
		scanf("gapps.ntnu.edu.tw%n", &emailDomainReaded);
	}

	// Clear input buffer
	while (getchar() != '\n');

	/* Scan subject input */
	printf("Please enter the email subject       > ");

	// Validate subject category
	scanf("[%n", &subjectCategoryReaded);

	if (subjectCategoryReaded == 1) { /* If read "[" */
		scanf("general]%n", &subjectCategoryReaded);
		scanf("hw%d][p%d]%n", &hwNum, &pNum, &subjectCategoryReaded);
	}

	if (subjectCategoryReaded != 8) {	/* If wrong category  */
		subjectCategoryReaded = 0;		/* Reset readed value to 0 */
	}

	// Validate subject title
	scanf("%*[^\n]%n", &subjectTitleReaded);

	// Clear input buffer
	while (getchar() != '\n');

	/* Scan content score */
	printf("Please enter the email content score > ");
	scanf("%lu", &contentScore);

	// Clear input buffer
	while (getchar() != '\n');

	/* DEBUG */
	// printf("local=%d, domain=%d\n", emailLocalReaded, emailDomainReaded);
	// printf("category=%d, title=%d\n", subjectCategoryReaded, subjectTitleReaded);
	// printf("hw=%d, p=%d\n", hwNum, pNum);
	// printf("score=%lu\n", contentScore);

	printf("================================================================================\n\n");

	/*
	 * Tests
	 */
	
	/* Email test */
	printf("Sender Address Test : ");

	if (!emailLocalReaded) {
		printf("Failed, local-part is invalid"); 
	}
	else if (!emailDomainReaded) {
		printf("Failed, domain is not authorised");
	}
	else {
		isEmailPassed = 1;
		printf("Passed");
	}
	printf("\n");

	/* Subject test */
	printf("Email Subject Test  : ");

	if (!isEmailPassed) { /* Skip test if email fail*/
		printf("-");
	}
	else if (!subjectCategoryReaded) {
		printf("Failed, no category");
	}
	else if (!subjectTitleReaded) {
		printf("Failed, title is empty");
	}
	else {
		isSubjectPassed = 1;
		printf("Passed");
	}
	printf("\n");

	/* Content score test */
	// Title score
	subjectTitleScore = (subjectTitleReaded - 1) * 10000000000;

	printf("Email Content Test  : ");

	if (!isSubjectPassed) {
		printf("-");
	}
	else if (contentScore > 10000000000000000000UL) {
		printf("Failed, out of range");
	}
	else if (contentScore < subjectTitleScore) {
		printf("Failed, too low");
	}
	else {
		isContentScorePassed = 1;
		printf("Passed");
	}
	printf("\n");

	printf("--------------------------------------------------------------------------------\n\n");

	/*
	 * TA Assignments
	 */
	if (hwNum == 0 && pNum == 0) {
		assignTA = 5; /* General assings to QB */
	}
	else {
		assignTA = (hwNum * pNum) % 5; /* Homework assings to 1 of 5 TAs */
	}

	if (!(isEmailPassed && isSubjectPassed && isContentScorePassed)) {
		printf("Rejected");
	}
	else if (assignTA == 0) {
		printf("Assigned to Kaname Madoka");
	}
	else if (assignTA == 1) {
		printf("Assigned to Akemi Homura");
	}
	else if (assignTA == 2) {
		printf("Assigned to Miki Sayaka");
	}
	else if (assignTA == 3) {
		printf("Assigned to Tomoe Mami");
	}
	else if (assignTA == 4) {
		printf("Assigned to Sakura Kyoko");
	}
	else if (assignTA == 5) {
		printf("Assigned to QB");
	}
	printf("\n");

	return 0;
}

