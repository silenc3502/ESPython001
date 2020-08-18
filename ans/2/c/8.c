#include <stdio.h>

void set_series(long long int *arr)
{
	int i;

	for(i = 2; i < 57; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

void print_arr(long long int *arr)
{
	int i, cnt = 0;

	for(i = 0; i < 57; i++)
	{
		if(!(++cnt % 5))
		{
			printf("%12lld\n", arr[i]);
		}
		else
		{
			printf("%12lld, ", arr[i]);
		}
	}

	printf("\n");
}

void get_each_sum(long long int *arr, long long int *even, long long int *odd)
{
	int i;

	for(i = 0; i < 57; i++)
	{
		if(!(arr[i] % 2))
		{
			*even += arr[i];
		}
		else
		{
			*odd += arr[i];
		}
	}
}

void calc_custom_series_oper(void)
{
	long long int arr[57] = {1, 1};
	long long int even_sum = 0;
	long long int odd_sum = 0;

	set_series(arr);
	print_arr(arr);

	get_each_sum(arr, &even_sum, &odd_sum);

	printf("even sum = %lld\n", even_sum);
	printf("odd sum = %lld\n", odd_sum);

	printf("even sum - odd sum = %lld\n", even_sum - odd_sum);
}

int main(void)
{
	calc_custom_series_oper();

	return 0;
}
