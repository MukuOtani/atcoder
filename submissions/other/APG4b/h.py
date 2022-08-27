N = int(input())
a = input().split()
b = input().split()
c = input().split()
sa = 0
sb = 0
sc = 0

for i in range(0,N):
	sa += int(a[i])
	sb += int(b[i])
	sc += int(c[i])
print(sa*sb*sc)
