S = list(input())
move = 0
ans = 0
for i in range(len(S)):
	if S[i] == 'B':
		move += 1
	else:
		ans += move
print(ans)
