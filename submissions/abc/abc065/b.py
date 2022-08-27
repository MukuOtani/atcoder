N = int(input())
a = []
flag = 0
for i in range(0,N):
	a.append(int(input()))
state = 1
for i in range(0,N):
	state = a[state-1]
	if state == 2:
		flag = 1
		t = i
		break
if flag:
	print(t+1)
else:
	print(-1)
