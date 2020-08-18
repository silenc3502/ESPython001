import random

def dice_game():
	dice = random.randint(1, 6)

	print("주사위 눈금을 맞춰보세요!")
	ans = input()

	if(dice == int(ans)):
		print("정답")
	else:
		print("오답 - {0}".format(dice))

dice_game()
