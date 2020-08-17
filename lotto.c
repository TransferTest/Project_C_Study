#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	// set a new seed value with current time
	srand((unsigned)time(NULL));

	printf("로또 당첨번호: ");

	// Loop 5 times
	int i = 0;
	int next_num;
	while (1)
	{
		next_num = rand() % 45 + 1;
		if (i > 5) break;
		printf("%d, ", next_num);
		i++;
	}
	printf("%d", next_num);
	next_num = rand() % 45 + 1;
	printf(" + 보너스 번호 %d\n", next_num);
	return 1;
}

