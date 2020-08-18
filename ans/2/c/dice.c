#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int init_rand_dice(void)
{
	srand(time(NULL));

	return rand() % 6 + 1;
}

void start_game(int dice)
{
	char ans[64] = "";
	char buf[64] = "주사위 눈금을 맞춰보세요!\n";
	write(1, buf, strlen(buf));
	read(0, ans, sizeof(ans));

	if(atoi(ans) == dice)
	{
		printf("정답\n");
	}
	else
	{
		printf("오답 - 정답은 %d\n", dice);
	}
}

int main(void)
{
	char buf[64] = "";
	int dice_num;
	dice_num = init_rand_dice();

	start_game(dice_num);

	return 0;
}
