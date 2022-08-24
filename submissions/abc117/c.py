N, M = map(int, input().split())
X = list(map(int, input().split()))

ans = 0
if N >= M:
	pass
else:
	X.sort()
	# print(X)
	Y = [0]*(M-1)
	for i in range(M-1):
		Y[i] = X[i+1] - X[i]
	Y.sort(reverse=True)
	# print(Y)
	L = 0
	for i in range(N-1):
		L += Y[i]
	ans = X[M-1] - X[0] - L
print(ans)
