N = int(input())
a = input().split()


for i in range(0,N):
	a[i] = int(a[i])
mi = 0
for i in range(0,N-1):
	for j in range(i+1,N):
		if abs(a[i]-a[j]) > mi:
			mi = abs(a[i]-a[j])
print(mi)
