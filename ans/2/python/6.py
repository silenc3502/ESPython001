import random

def is_dup(arr):
	cur_idx = len(arr) - 1

	for i in range(cur_idx - 1):
		if arr[cur_idx] == arr[i]:
			return 1

	return 0

def pretty_print(arr):
    for i in range(len(arr)):
        if (i % 5 == 4):
            print('{0:<5s}'.format(arr[i]))
        else:
            print('{0:<5s}'.format(arr[i]), end=', ')

    print()
		
def ladder_game():
	cnt = 0
	match = []
	rand_num = []
	player = ["김택용", "이영호", "김명운", "이제동", "송병구",
			"김윤환", "임홍규", "염보성", "박지호", "오영종",
			"임요환", "홍진호", "이재호", "박정석", "김승현",
			"도재욱", "이성은", "김성현", "조일장", "김윤중"]

	pretty_print(player)
	print("사다리 게임을 시작한다.")

	player_len = len(player)

	while(cnt < player_len):
		rand_num.append(random.randint(0, 19))
		cur_len = len(rand_num)

		while(is_dup(rand_num)):
			rand_num.pop()
			rand_num.append(random.randint(0, 19))

		match.append(player[rand_num[cnt]])
		cnt += 1

	pretty_print(match)

ladder_game()
