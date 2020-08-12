#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void rand_init(void)
{
	srand(time(NULL));
}

void arr_init(int *arr, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		arr[i] = rand() % 10 + 3;
	}
}

void arr_print(int *arr, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[7];
	int arr2[3];

	rand_init();

	arr_init(arr, 7);
	arr_init(arr2, 3);
	arr_print(arr, 7);
	arr_print(arr2, 3);

	return 0;
}
