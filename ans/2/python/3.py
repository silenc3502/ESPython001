import random
import math

def calc_var(arr, mean):
	sum = 0
	arr_len = len(arr)

	for i in range(arr_len):
		sum += (arr[i] - mean) ** 2

	return sum / arr_len

def calc_std_dev(var):
	return math.sqrt(var)

def calc_mean(arr):
	sum = 0
	arr_len = len(arr)

	for i in range(arr_len):
		sum += arr[i]

	return sum / arr_len

def calc_median(arr):
	arr_len = len(arr)

	if arr_len % 2 == 0:
		return (arr[arr_len // 2] + arr[arr_len // 2 - 1]) / 2
	else:
		return arr[arr_len // 2]

def init_arr():
	arr = []
	idx = random.randint(100, 200)

	for i in range(idx):
		arr.append(random.randint(0, 100))

	return arr

def pretty_print(arr):
	for i in range(len(arr)):
		if (i % 10 == 9):
			print('[{0:<3d}]'.format(arr[i]))
		else:
			print('[{0:<3d}]'.format(arr[i]), end=', ')

	print()

arr = init_arr()
pretty_print(arr)

mean = calc_mean(arr)
print("mean = {0}".format(mean))

arr.sort()
pretty_print(arr)

median = calc_median(arr)
print("median = {0}".format(median))

var = calc_var(arr, mean)
print("variation = {0}".format(var))

std_dev = calc_std_dev(var)
print("standard deviation = {0}".format(std_dev))
