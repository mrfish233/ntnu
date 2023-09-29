#include <stdio.h>
#include <stdint.h>

int main()
{
	// Read variables
	int32_t read_email_local = 0, read_email_domain  = 0;
	int32_t read_subject_title = 0;
	uint64_t read_score = 0;

	// Check variables
	int32_t domain_length = 0;

	char hw_char = '\0', p_char = '\0';
	int32_t hw_number = 0, p_number = 0;
	int32_t assign_ta = 0;

	uint64_t title_score = 0;

	// Check result variables
	int32_t is_email_passed = 0, is_subject_passed = 0, is_score_passed = 0;

	/*
	 * Scan inputs
	 */

	// Scan email
	printf("Please enter the sender address      > ");
	scanf("%*[a-zA-z0-9]@%n%*[ntnugappscsie].%*[ntnuedutw.cool]%n", &read_email_local, &read_email_domain);

	//getchar();

	// Scan subject
	printf("Please enter the email subject       > ");
	scanf(" %*3[[hwge]%c%*3[][erap]%c%*[]]%*[^\n]%n", &hw_char, &p_char, &read_subject_title);

	//getchar();

	// Scan score
	printf("Please enter the email content score > ");
	scanf(" %lu", &read_score); 

	/*
	 * Check inputs
	 */
	
	// Domain length
	domain_length = read_email_domain - read_email_local;
	//printf("%d %d %d\n", read_email_local, read_email_domain, domain_length);

	// Convert char to int
	hw_number = hw_char - '0';
	p_number  = p_char  - '0';
	// TA assign
	if (hw_char == 'n' && p_char == 'l')
	{
		assign_ta = 5;
	}
	else
	{
		assign_ta = (hw_number * p_number) % 5;
	}
	//printf("%c=%d %c=%d %d assign=%d\n", hw_char, hw_number, p_char, p_number, read_subject_title, assign_ta);

	// Calculate title score to compare with read score
	title_score = (read_subject_title - 11) * 10000000000;
	//printf("%lu %lu\n", read_score, title_score);
	
	/*
	 * Validity Check
	 */
	
	// Check email validity
	printf("\n================================================================================\n\n");
	printf("Sender Address Test : ");
	
	// Check local part
	if (read_email_local == 0)
	{
		printf("Failed, local-part is invalid\n"); 
	}
	// Check domain part
	else if (read_email_domain == 0 ||
			 (domain_length != 9 && domain_length != 11 && domain_length != 16 && domain_length != 17))
	{
		printf("Failed, domain is not authorised\n");
	}
	// Email is correct
	else
	{
		is_email_passed = 1;
		printf("Passed\n");
	}

	// Check subject validity
	printf("Email Subject Test  : ");
	
	// Skip test if email test failed
	if (!is_email_passed)
	{
		printf("-\n");
	}
	// Check category part
	else if (hw_number < 0|| p_number < 0)
	{
		printf("Failed, no category\n");
	}
	// Check title part
	else if (read_subject_title == 0)
	{
		printf("Failed, title is empty\n");
	}
	// Subject is correct
	else
	{
		is_subject_passed = 1;
		printf("Passed\n");
	}

	// Check score validity
	printf("Email Content Test  : ");

	// Skip test if subject test failed
	if (!is_subject_passed)
	{
		printf("-\n");
	}
	// Check score range
	else if (read_score < 0 || read_score > 10000000000000000000UL)
	{
		printf("Failed, out of range\n");
	}
	// Compare title score and content score
	else if (read_score < title_score)
	{
		printf("Failed, too low\n");
	}
	// Score is correct
	else
	{
		is_score_passed = 1;
		printf("Passed\n");
	}

	/*
	 * Assign or Reject
	 */
	printf("\n--------------------------------------------------------------------------------\n\n");

	// Reject if any failed test
	if (!(is_email_passed && is_subject_passed && is_score_passed))
	{
		printf("Rejected\n");
	}
	// General assign to QB
	else if (assign_ta == 0)
	{
		printf("Assigned to Kaname Madoka\n");
	}
	else if (assign_ta == 1)
	{
		printf("Assigned to Akemi Homura\n");
	}
	else if (assign_ta == 2)
	{
		printf("Assigned to Miki Sayaka\n");
	}
	else if (assign_ta == 3)
	{
		printf("Assigned to Tomoe Mami\n");
	}
	else if (assign_ta == 4)
	{
		printf("Assigned to Sakura Kyoko\n");
	}
	else if (assign_ta == 5)
	{
		printf("Assigned to QB\n");
	}
	else
	{
		printf("Rejected\n");
	}

	return 0;
}

