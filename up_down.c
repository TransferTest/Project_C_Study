#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	int target_num, guess;
	int score = 100;
	// Initialize seed and get a random number
	srand((unsigned)time(NULL));
	target_num = rand() % 100 + 1;
	
	while(1)
	{
		printf("입력: ");
		scanf("%d", &guess);
		rewind(stdin);
		if (guess == target_num)
		{
			printf("Num: %d, Score: %d\n", target_num, score);
			break;
		}
		score -= 5;
		if (score <= 0)
		{
			printf("You loose\n");
			break;
		}
		if (guess < target_num)
		{
			printf("Up!\n");
		}
		else
		{
			printf("Down!\n");
		}
	}
	return 1;
}
