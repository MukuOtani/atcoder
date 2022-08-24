S = input()
c = ['A', 'T', 'C', 'G']
ans = 0
cnt = 0
for i in range(len(S)):
	if S[i] in c:
		cnt += 1
		if i == len(S)-1:
			ans = max(cnt, ans)
	else:
		ans = max(cnt, ans)
		cnt = 0
print(ans)
