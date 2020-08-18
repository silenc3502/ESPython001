#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NAME_MAX		20
#define CHAR_MAX		2

char name[21];
char position[21];

void init_ladders(void)
{
	int i;
	char c = 'A';

	for(i = 0; i < NAME_MAX; i++)
	{
		name[i] = c + i;
	}
}

void init_position(void)
{
	int i;

	for(i = 0; i < NAME_MAX; i++)
	{
		position[i] = -1;
	}
}

void print_ladders(void)
{
	int i, cnt = 0;

	for(i = 0; i < 20; i++)
	{
		if(!(++cnt % 10))
		{
			printf("%c\n", name[i]);
		}
		else
		{
			printf("%c, ", name[i]);
		}
	}
}

void print_position(void)
{
	int i, cnt = 0;

	for(i = 0; i < 20; i++)
	{
		if(!(++cnt % 10))
		{
			printf("%c\n", position[i]);
		}
		else
		{
			printf("%c, ", position[i]);
		}
	}
}

int is_dup(int cur_idx)
{
	int i;

	for(i = 0; i < cur_idx; i++)
	{
		if(position[cur_idx] == position[i])
		{
			return 1;
		}
	}

	return 0;
}

void start_game(void)
{
	int i, idx;
	char form[64] = "사다리 게임을 시작합니다!\n";

	srand(time(NULL));

	write(1, form, strlen(form));

	for(i = 0; i < 20; i++)
	{
redo:
		idx = rand() % 20;
		position[i] = name[idx];

		if(is_dup(i))
		{
			goto redo;
		}
	}
}

int main(void)
{
	init_ladders();
	init_position();
	start_game();
	print_ladders();
	printf("스타팅 멤버 선출 완료!\n");
	print_position();

	return 0;
}
