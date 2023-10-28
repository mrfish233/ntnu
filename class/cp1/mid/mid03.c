#include <stdio.h>
#include <stdint.h>

int32_t rule1(int32_t n, int32_t l) {
	static int32_t pass1 = 0, pass2 = 0, pass3 = 0;

	if (pass3 == 1) return 1;

	if (n == 1 || (l == 3 && n == 2)) pass1 = 1;

	if (pass1 == 1) {
		if (l == 6 && n == 5) pass2 = 1;
	}

	if (pass2 == 1) {
		if (n == 9 || (l == 7 && n == 8)) pass3 = 1;
	}

	if (pass3 == 1) return 1;

	return 0;
}

int32_t rule2(int32_t n) {
	static int32_t pass1 = 0, pass2 = 0, pass3 = 0;

	if (pass3 >= 1) return 1;

	if (n == 7) pass1++;

	if (pass1 == 1 || pass1 == 2) {
		if (n == 5) pass2++;

		if (pass2 == 0 || pass2 == 1) {
			if (n == 3) pass3++;
		}
	}

	if (pass3 >= 1) return 1;
	else return 0;
}

int32_t rule3(int32_t n, int32_t l) {
	static int32_t pass1 = 0, pass2 = 0, pass3 = 0;

	if (pass3 >= 1) return 1;

	if (n == 4) pass1 = 1;

	if (pass1 == 1) {
		if (n == 6 && pass2 == 0) pass2++;

		if (pass2 == 1 || pass2 == 2) {
			if (l == 6 && n == 6) pass2++;
			else pass2 = 0;
		}

		if (pass2 == 3) {
			if (n == 8) pass3++;
		}
	}

	if (pass3 >= 1) return 1;
	else return 0;
}

int main() {
	int32_t input = 0, last = -1;

	int32_t r1=0, r2=0, r3=0;

	while (input != -1) {
		printf("Please input the digit: ");
		scanf("%d", &input);

		r1 = rule1(input, last);
		r2 = rule2(input);
		r3 = rule3(input, last);

		last = input;
	}

	if (r1 == 1 && r2 == 1 && r3 == 1) printf("SUCCESS\n");
	else {
		if (r1 == 0) {
			printf("Rule1 ");
		}

		if (r2 == 0) {
			printf("Rule2 ");
		}

		if (r3 == 0) {
			printf("Rule3 ");
		}

		printf("not follow!\n");
	}
	
	return 0;
}
