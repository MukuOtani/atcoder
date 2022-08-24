H,W = map(int, input().split())
A = []
for i in range(0,H):
	A.append(input())
B = []
B.append('#' * (W+2))
for i in range(0,H):
	B.append('#' + A[i] + '#')
B.append('#' * (W+2))
for i in range(0,H+2):
	print(B[i])
	
