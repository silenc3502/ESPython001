import random

def quiz20_game():
	cnt = 20
	rand_num = random.randint(0, 100)
	print("1 ~ 100사이의 난수를 맞춰보시오.")
	
	while(cnt > 0):
		din = int(input("{0} 번의 기회가 남았습니다.\n".format(cnt)))
		if(din == rand_num):
			print("정답")
			break
		elif(din > rand_num):
			print("입력이 더 크다.")
		else:
			print("입력이 더 작다.")
		cnt -= 1

quiz20_game()
