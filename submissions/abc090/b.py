A,B = map(int, input().split())
ans = 0
for i in range(A, B+1):
	s = i%10
	t = int(i/10000)
	u = int(i/10)%10
	v = int(i/1000)%10
	if (s==t)&(u==v):
		ans += 1
print(ans)
