N = input()
ans = 0
for i in range(0,len(N)):
	ans += int(N[i])
if int(N)%ans==0:
	print('Yes')
else:
	print('No')
