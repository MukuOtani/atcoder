N, M = map(int, input().split())
A = []
for i in range(0,N):
	A.append(0)
for i in range(0,M):
	a, b = map(int, input().split())
	A[a-1] += 1
	A[b-1] += 1
for i in range(0,N):
	print(A[i])
