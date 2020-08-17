#include <stdio.h>

int main ()
{
	// Input money
	int money;
	int stuff;
	printf("돈을 넣어주세요: ");
	scanf("%d", &money);
	
	// Print menu
	printf("========= 메뉴 =========\n1. 애플망고      | \\800\n2. 에비앙        | \\600\n3. 핫식스        | \\1,000\n4. 칠성사이다    | \\700\n5. 홍삼          | \\5,000\n메뉴를 선택해주세요: ");
	
	// Input stuff number
	rewind(stdin);
	scanf("%d", &stuff);
	
	switch(stuff)
	{
		case 1:
			if (money < 800)
			{
				printf("잔액부족\n");
				break;
			}
			money -= 800;
			printf("애플망고가 나왔습니다.\n잔액: %d원\n", money);
			break;
		case 2:
			if (money < 600)
			{
				printf("잔액부족\n");
				break;
			}
			money -= 600;
			printf("에비앙이 나왔습니다.\n잔액: %d원\n", money);
			break;
		case 3:
			if (money < 1000)
			{
				printf("잔액부족\n");
				break;
			}
			money -= 1000;
			printf("핫식스가 나왔습니다.\n잔액: %d원\n", money);
			break;
		case 4:
			if (money < 700)
			{
				printf("잔액부족\n");
				break;
			}
			money -= 700;
			printf("칠성사이다가 나왔습니다.\n잔액: %d원\n", money);
			break;
		case 5:
			if (money < 5000)
			{
				printf("잔액부족\n");
				break;
			}
			money -= 5000;
			printf("홍삼이 나왔습니다.\n잔액: %d원\n", money);
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
	}
}
