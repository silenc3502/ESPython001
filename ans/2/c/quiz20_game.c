#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int init_rand_quiz_num(void)
{
	srand(time(NULL));

	return rand() % 100;
}

void start_game(int ans)
{
	int cnt = 20;

	/* 값의 입력 및 출력 시작 */
	char guess[4] = "";
	char form[64] = "값을 %d번내에 맞춰보세요!\n";
	char buf[64] = "";

	while(cnt > 0)
	{
		int tmp;

		sprintf(buf, form, cnt);	
		write(1, buf, strlen(buf));
		read(0, guess, sizeof(guess));
		/* 값의 입력 및 출력 끝 */

		/* 정답 확인 시작 */
		tmp = atoi(guess);

		if(tmp == ans)
		{
			printf("정답\n");
			// goto finish;
			return;
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
		/* 정답 확인 끝 */

		cnt--;
	}

finish:
	return;
}

int main(void)
{
	char buf[64] = "";
	int quiz_ans;
	// 난수 생성
	quiz_ans = init_rand_quiz_num();

	// 스무고개 게임 시작!
	start_game(quiz_ans);

	return 0;
}
