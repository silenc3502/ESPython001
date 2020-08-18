def my_series(num):
	first = 1
	second = 3

	num -= 2

	while(num > 0):
		first, second = second, first + second
		print("second = {0}".format(second))
		num -= 1

	return second

res = my_series(23)
print("res = {0}".format(res))
