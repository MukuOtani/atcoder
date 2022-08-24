N = int(input())
A = input().split()
s = 0
for i in range(0,N):
	s += int(A[i])
average = int(s/N)
for i in range(0,N):
	print(abs(int(A[i])-average))
