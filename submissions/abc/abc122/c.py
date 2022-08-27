N, Q = map(int, input().split())
S = input()
L = []
R = []
# ans = []
for _ in range(Q):
	l, r = map(int, input().split())
	L.append(l)
	R.append(r)
sum = [0] * (N+1)
for i in range(1, N):
	if S[i-1] == 'A' and S[i] == 'C':
		sum[i+1] = sum[i] + 1
	else:
		sum[i+1] = sum[i]
# print(sum)


for i in range(Q):
	print(sum[R[i]] - sum[L[i]])
