s = input()
l = len(s)
ans = int(s[0])
for i in range(1,l,2):
	if s[i] == '+':
		ans += 1
	else:
		ans -= 1
print(ans)
	
