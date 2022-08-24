N = int(input())

S = []


for i in range(N):
	a,b = map(str, input().split())
	c = int(b)
	S.append([i, a, c])

S.sort(key=lambda x:(x[1],-x[2]))

for i in range(N):
	print(S[i][0]+1)
