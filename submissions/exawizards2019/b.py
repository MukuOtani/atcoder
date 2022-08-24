N = int(input())
s = input()
r = 0
b = 0
for i in range(N):
	if s[i] == 'R':
		r += 1
	else:
		b += 1
if r > b:
	print('Yes')
else:
	print('No')
