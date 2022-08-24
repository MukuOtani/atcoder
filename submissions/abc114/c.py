import itertools
N = int(input())
l = len(str(N))
ans = 0
if l < 3:
	pass
else:
	S = []
	for k in range(3,l+1):
		S += list(itertools.product(['3', '5', '7'], repeat=k))
	# print(S)
	for i in range(len(S)):
		num = ''
		for t in range(len(S[i])):
			num = num + S[i][t]
		# print(num)
		if '3' in num:
			if '5' in num:
				if '7' in num:
					if int(num) <= N:
						# print(num)
						ans += 1
print(ans)
