#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int init_rand_dice(void)
{
	srand(time(NULL));

	return rand() % 100;
}

void start_game(int ans)
{
	int cnt = 20;

	char guess[4] = "";
	char form[64] = "값을 %d번내에 맞춰보세요!\n";
	char buf[64] = "";

	while(cnt > 0)
	{
		int tmp;

		sprintf(buf, form, cnt);	
		write(1, buf, strlen(buf));
		read(0, guess, sizeof(guess));

		tmp = atoi(guess);

		if(tmp == ans)
		{
			printf("정답\n");
			goto finish;
		}
		else
		{
			if(tmp > ans)
			{
				printf("정답은 더 작다.\n");
			}
			else
			{
				printf("정답은 더 크다.\n");
			}
		}

		cnt--;
	}

finish:
	return;
}

int main(void)
{
	char buf[64] = "";
	int dice_num;
	dice_num = init_rand_dice();

	start_game(dice_num);

	return 0;
}
