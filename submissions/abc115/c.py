N, K = map(int, input().split())
h = []
for _ in range(N):
	h.append(int(input()))
h.sort()
ans = h[N-1]
for i in range(N-K+1):
	ans = min(ans, h[i+K-1]-h[i])
print(ans)
