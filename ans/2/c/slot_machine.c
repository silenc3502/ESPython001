#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SLOT_LEN_MAX		7
#define SLOT_NUM			3
#define KINDS_OF_SLOT		3
#define KINDS_OF_WIN		3

char *success[3][3] = {
	{ "cherry", "cherry", "cherry" },
	{ "apple", "apple", "apple" },
	{ "dollar", "dollar", "dollar" },
};

char *slot[3] = {
	"cherry", "dollar", "apple"
};

char **make_mem(void)
{
	int i;
	char **buf = NULL;

	// char *arr[3]
	// malloc할당은 Heap 공간에 할당한다.
	// 사용자의 필요에 따라 메모리 할당을 제어할 수 있다.
	// 스택은 컴파일시에 정적으로 할당되지만
	// 힙은 프로그램 동작시에 동적으로 할당되므로 느리다.
	// 그러나 유연성을 있기 때문에 서비스 관점에서는 매우 중요하다.
	// 펌웨어 -> RTOS가 올라가면 또 필요해진다.
	buf = (char **)malloc(sizeof(char *) * SLOT_NUM);

	for(i = 0; i < SLOT_NUM; i++)
	{
		buf[i] = (char *)malloc(sizeof(char) * SLOT_LEN_MAX);
	}

	return buf;
}

void free_mem(char **buf)
{
	int i;

	for(i = 0; i < SLOT_NUM; i++)
	{
		free(buf[i]);
	}

	free(buf);
}

void set_rand_slot(char **buf)
{
	int i;

	for(i = 0; i < SLOT_NUM; i++)
	{
		strcpy(buf[i], slot[rand() % KINDS_OF_SLOT]);
	}
}

void print_mem(char **buf)
{
	int i;

	for(i = 0; i < SLOT_NUM; i++)
	{
		if(i != SLOT_NUM - 1)
		{
			printf("%s, ", buf[i]);
		}
		else
		{
			printf("%s\n", buf[i]);
		}
	}
}

void check_win(char **buf)
{
	int i, j, cnt = 0;

	for(i = 0; i < SLOT_NUM; i++)
	{
		for(j = 0; j < KINDS_OF_SLOT; j++)
		{
			if(!strcmp(buf[j], slot[i]))
			{
				cnt++;
				if(cnt == 3)
				{
					printf("Win!\n");
					goto finish;
				}
			}
		}

		cnt = 0;
	}

finish:
	return;
}

void start_slot_game(void)
{
	int rlen;
	char ans[4] = "";
	char buf[64] = "슬롯 머신을 돌리겠습니까 ? y/n: ";
	// 이중 포인터는 가변 배열일 수도 있고
	// 단순한 변수 1개일수도 있다.
	// char **res == char *res[]
	// 배열은 공간이 할당되지만 포인터는 공간이 할당되지 않는다.
	// 그러므로 포인터를 사용할 때는 메모리를 먼저 할당해야 한다.
	char **res = NULL;

	write(1, buf, strlen(buf));
	rlen = read(0, ans, sizeof(ans));
	printf("rlen = %d\n", rlen);
	ans[rlen - 1] = '\0';

	if(!strcmp(ans, "y"))
	{
		printf("슬롯을 돌립니다!\n");
		srand(time(NULL));
		res = make_mem();
		set_rand_slot(res);
	}
	else
	{
		printf("게임을 종료합니다!\n");
	}

	print_mem(res);

	check_win(res);

	free_mem(res);
}

int main(void)
{
	start_slot_game();

	return 0;
}
