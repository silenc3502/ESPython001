#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define AMOUNT_BIAS		100
#define AMOUNT_RANGE	101

#define NUM_RANGE		100

int partition(int *, int, int);
void quicksort(int *, int, int);

int init_rand_arr(int **arr)
{
	int i;
	int rand_len;

	srand(time(NULL));

	rand_len = rand() % AMOUNT_RANGE + AMOUNT_BIAS;

	*arr = (int *)malloc(sizeof(int) * rand_len);

	for(i = 0; i < rand_len; i++)
	{
		(*arr)[i] = rand() % NUM_RANGE;
	}

	return rand_len;
}

float calc_mean(int *arr, int rand_len)
{
	int i;
	float sum = 0;

	for(i = 0; i < rand_len; i++)
	{
		sum += arr[i];
	}

	return sum / rand_len;
}

float calc_median(int *arr, int rand_len)
{
	int i;

	if(!(rand_len % 2))
	{
		return (arr[rand_len / 2] + arr[rand_len / 2 - 1]) / 2.0f;
	}
	else
	{
		return arr[rand_len / 2];
	}
}

void print_arr(int *arr, int len)
{
	int i;
	int cnt = 0;

	for(i = 0; i < len; i++)
	{
		if(++cnt % 10)
		{
			printf("%3d, ", arr[i]);
		}
		else
		{
			printf("%3d\n", arr[i]);
		}
	}
	printf("\n");
}

void swap(int *arr, int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void quick_sort(int *arr, int left, int right)
{
	if(left <= right)
	{
		int pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}

int partition(int *arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		while(low <= right && pivot >= arr[low])
		{
			low++;
		}
		while(high >= (left + 1) && pivot <= arr[high])
		{
			high--;
		}
		if(low <= high)
		{
			swap(arr, low, high);
		}
	}

	swap(arr, left, high);

	return high;
}

float calc_var(int *arr, float mean, int len)
{
	int i;
	float sum = 0;

	for(i = 0; i < len; i++)
	{
		sum += pow(arr[i] - mean, 2);
	}

	return sum / len;
}

float calc_std_dev(float var)
{
	return sqrt(var);
}

int main(void)
{
	float mean;
	float median;
	float variation;
	float std_dev;

	int *arr;
	int rand_len;

	rand_len = init_rand_arr(&arr);

	printf("Before Sort Data: \n");
	print_arr(arr, rand_len);

	printf("After Sort Data: \n");
	quick_sort(arr, 0, rand_len);
	print_arr(arr, rand_len);

	mean = calc_mean(arr, rand_len);
	printf("mean = %f\n", mean);

	median = calc_median(arr, rand_len);
	printf("median = %f\n", median);

	variation = calc_var(arr, mean, rand_len);
	printf("variation = %f\n", variation);

	std_dev = calc_std_dev(variation);
	printf("standard deviation = %f\n", std_dev);

	free(arr);

	return 0;
}
