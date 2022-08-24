N = int(input())
a = input().split()
ans = 0
ci = -2
t = 1
for i in range(0,N):
	a[i] = int(a[i])
a.append(0)
for i in range(0,N):
	if a[i]==a[i+1]:
		ci = i
		t += 1
	if a[i]!=a[i+1]:
		if ci == i-1:
			ans += int(t/2)
			t = 1
print(ans)
