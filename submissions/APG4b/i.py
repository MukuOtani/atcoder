a = input().split()
M = int(a[0])
m = int(a[0])
for i in range(0,len(a)):
	if M < int(a[i]):
		M = int(a[i])
	if m > int(a[i]):
		m = int(a[i])
print(M-m)
