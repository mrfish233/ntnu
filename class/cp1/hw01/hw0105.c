#include <stdio.h>
#include <stdint.h>

int main()
{
	int32_t readed = 0;

	scanf("%*[a-zA-Z0-9]@csie.cool%n", &readed);
	printf("readed = %d\n", readed);

	return 0;
}
