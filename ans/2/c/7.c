#include <stdio.h>

int first = 1;
int second = 3;

int calc_custom_series(int no)
{
	int i, tmp;

	for(i = 0; i < no - 2; i++)
	{
		tmp = first;
		first = second;
		second = tmp + second;
		printf("res = %d\n", second);
	}

	return second;
}

int main(void)
{
	int res = calc_custom_series(23);
	printf("res = %d\n", res);

	return 0;
}
