#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void rand_init(void)
{
	srand(time(NULL));
}

void arr_init(int *arr)
{
	int i;

	for(i = 0; i < 7; i++)
	{
		arr[i] = rand() % 10 + 3;
	}
}

void arr_print(int *arr)
{
	int i;

	for(i = 0; i < 7; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

int main(void)
{
	int arr[7];

	rand_init();

	arr_init(arr);
	arr_print(arr);

	return 0;
}
