N, Q = map(int, input().split())
s = input()
T = []
D = []
for _ in range(Q):
	t, d = input().split()
	T.append(t)
	D.append(d)


ans = 0
left = 0
right = N-1
for i in range(Q-1,-1,-1):
	if D[i] == 'R':
		if T[i] == s[right]:
			right -= 1
			if right == 0:
				print(0)
				exit()
		if left > 0 and s[left-1]==T[i]:
			left -= 1

	else:
		if T[i] == s[left]:
			left += 1
			if left == N-1:
				print(0)
				exit()
		if right < N-1 and s[right+1]==T[i]:
			right += 1
	# print(s[left:right+1])
print(max(0,right-left+1))
