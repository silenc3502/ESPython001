import random

def slot_machine():
	cnt = 0
	res = []
	list = ["apple", "cherry", "dollar"]
	print("슬롯머신을 돌립니다!")

	for i in range(3):
		res.append(list[random.randint(0, 2)])

	print(res)

	for i in range(3):
		if(res[0] == res[i]):
			cnt += 1

	if cnt == 3:
		print("Win")
	else:
		print("Lose")

slot_machine()
