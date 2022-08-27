T = [[0,0],[0,0],[0,0],[0,0],[0,0]]
for i in range(5):
	t = int(input())
	if t%10 == 0:
		T[i][0] = 10
	else:
		T[i][0] = t%10
	T[i][1] = t

T.sort(reverse=True)
# print(T)
ans = 0
for i in range(4):
	if T[i][0] == 10:
		ans += T[i][1]
	else:
		ans += (T[i][1]//10+1)*10
	# print(ans)
ans += T[4][1]
print(ans)
