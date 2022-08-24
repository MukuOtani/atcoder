N = int(input())
K = int(input())
x = input().split()
ans = 0
for i in range(0,N):
	if int(x[i]) > (K-int(x[i])):
		ans += (K-int(x[i]))*2
	else:
		 ans += int(x[i])*2
print(ans)
