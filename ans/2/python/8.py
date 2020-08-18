def get_series_res(no):
	arr = [1, 1]
	even_sum = odd_sum = 0

	for i in range(2, no):
		arr.append(arr[i - 1] + arr[i - 2])
		print("arr[{0}] = {1}".format(i, arr[i]))

		if arr[i] % 2 == 0:
			even_sum += arr[i]
		else:
			odd_sum += arr[i]

	odd_sum += 2
	
	print("even_sum:", even_sum)	
	print("odd_sum:", odd_sum)	

	return even_sum - odd_sum

res = get_series_res(57)
print("res = {0}".format(res))
