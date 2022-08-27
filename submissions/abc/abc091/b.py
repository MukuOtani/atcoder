N = int(input())
s = []
t = []
p = []
ans = 0
for i in range(0,N):
	s.append(input())
M = int(input())
for i in range(0,M):
	t.append(input())
for i in range(0,N):
	p.append(0)
	for j in range(0,N):
		if s[i] == s[j]:
			p[i] += 1
	for k in range(0,M):
		if s[i] == t[k]:
			p[i] -= 1
	if ans < p[i]:
		ans = p[i]
print(ans)
