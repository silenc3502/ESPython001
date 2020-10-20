#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int **n_by_n_space;
int num;

void create_n_by_n_array(void)
{
	int i;

	srand(time(NULL));

	// 3 ~ 7
	num = rand() % 5 + 3;

	n_by_n_space = (int **)malloc(sizeof(int *) * num);

	for (i = 0; i < num; i++)
	{
		n_by_n_space[i] = (int *)malloc(sizeof(int) * num);
	}
}

void init_n_by_n_array(void)
{
	int i, j;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			n_by_n_space[i][j] = -1;
		}
	}
}

void print_n_by_n_array(void)
{
	int i, j;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%3d", n_by_n_space[i][j]);
		}

		printf("\n");
	}
}

int main(void)
{
	create_n_by_n_array();
	init_n_by_n_array();
	print_n_by_n_array();

	return 0;
}
